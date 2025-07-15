module;

#pragma comment (lib, "Ws2_32.lib")

#include "debug.h"

#undef UNICODE
#define WIN32_LEAN_AND_MEAN
#include <windows.h>
#include <winsock2.h>
#include <ws2tcpip.h>

export module network;

import std;

//packetID source name
//0 C ping
//1 S pong
//2 C connection request
//3 S connection response
//only acknowledge if no packet is sent in response to another packet
//4 C acknowledge packet
//5 S acknowledge packet

//https://learn.microsoft.com/en-us/windows/win32/winsock/getting-started-with-winsock
//initialize server
//packet management

class WinsockManager {
	inline static WSADATA wsaData;
	bool initialized = false;

public:

	WinsockManager() {
		int iResult = WSAStartup(MAKEWORD(2, 2), &wsaData);
		if (iResult != 0) {
			STAMPSTACK();
			STAMPDMSG("InitWinsock - WSAStartup failed with error: " << iResult);
			
			return;
		}
		initialized = true;
	}

	WinsockManager(const WinsockManager&) = delete;
	WinsockManager& operator =(const WinsockManager&) = delete;

	operator bool() {
		return initialized;
	}
	bool operator !() {
		return !initialized;
	}

	~WinsockManager() {
		if (initialized) {
			initialized = false;
			WSACleanup();
		}
	}
};
WinsockManager winsock{};

static inline void reverseBytes(void* begin, void* end, void* dest) {
	for (uint8_t* i = ((uint8_t*)end - 1), *j = (uint8_t*)dest; i >= begin; i--, j++) {
		*j = *i;
	}
}
static inline void endianFix(void* source, void* dest, int length) {
	if (std::endian::native == std::endian::little) {
		memcpy_s(dest, length, source, length);
	}
	else {
		reverseBytes(source, (char*)source + length, dest);
	}
}

enum struct ServerState {
	Uninitialized,
	Initializing,
	Failed,
	Listening,
};
enum struct ClientRecieveState {
	OK,
	Closing,
	Failed,
};
//uint32 length 2 + sizeof(body)
//uint16 ID
//body

class Packet final {
	friend class TCPServerClient;
	std::vector<uint8_t>& data;
	int dataIndex;
	int packetID;


	Packet(std::vector<uint8_t>& data) : data(data) {
		packetID = Int16();
	}
public:
	int getPacketID() {
		return packetID;
	}
	int32_t VarInt32() {
		int32_t o = 0;
		for (int i = 0; i < (32+6)/7; i++) {
			uint8_t v = data[dataIndex];
			dataIndex++;
			o |= v & 0x7F;
			if (!(v & 0x80)) break;
			o <<= 7;
		}
		return o;
	}
	int64_t VarInt64() {
		int64_t o = 0;
		for (int i = 0; i < (64+6) / 7; i++) {
			uint8_t v = data[dataIndex];
			dataIndex++;
			o |= v & 0x7F;
			if (!(v & 0x80)) break;
			o <<= 7;
		}
		return o;
	}
	uint32_t VarUint32() {
		STAMPERROR(data.size() - dataIndex <= sizeof(int8_t), "Packet::GetVarInt - out of bounds.");
		uint32_t o = 0;
		for (int i = 0; i < (32 + 6) / 7; i++) {
			uint8_t v = data[dataIndex];
			dataIndex++;
			o |= v & 0x7F;
			if (!(v & 0x80)) break;
			o <<= 7;
		}
		return o;
	}
	uint64_t VarUint64() {
		STAMPERROR(data.size() - dataIndex <= sizeof(int8_t), "Packet::GetVarInt - out of bounds.");
		uint64_t o = 0;
		for (int i = 0; i < (64 + 6) / 7; i++) {
			uint8_t v = data[dataIndex];
			dataIndex++;
			o |= v & 0x7F;
			if (!(v & 0x80)) break;
			o <<= 7;
		}
		return o;
	}
	uint8_t Uint8() {
		STAMPERROR(data.size() - dataIndex <= sizeof(int8_t), "Packet::GetInt8 - out of bounds.");
		uint8_t k = data[dataIndex];
		dataIndex += sizeof(int8_t);
		return k;
	}
	uint16_t Uint16() {
		STAMPERROR(data.size() - dataIndex <= sizeof(int16_t), "Packet::GetInt16 - out of bounds.");
		uint16_t k = *(int16_t*)(data.data() + dataIndex);
		uint16_t o;
		dataIndex += sizeof(int16_t);
		endianFix(&k, &o, sizeof(int16_t));
		return o;
	}
	uint32_t Uint32() {
		STAMPERROR(data.size() - dataIndex <= sizeof(int), "Packet::GetInt32 - out of bounds.");
		uint32_t k = *(int32_t*)(data.data() + dataIndex);
		uint32_t o;
		dataIndex += sizeof(int32_t);
		endianFix(&k, &o, sizeof(int32_t));
		return o;
	}
	uint64_t Uint64() {
		STAMPERROR(data.size() - dataIndex <= sizeof(int64_t), "Packet::GetInt64 - out of bounds.");
		uint64_t k = *(int64_t*)(data.data() + dataIndex);
		uint64_t o;
		dataIndex += sizeof(int64_t);
		endianFix(&k, &o, sizeof(int64_t));
		return o;
	}
	int8_t Int8() {
		STAMPERROR(data.size() - dataIndex <= sizeof(int8_t), "Packet::GetInt8 - out of bounds.");
		int8_t k = data[dataIndex];
		dataIndex += sizeof(int8_t);
		return k;
	}
	int16_t Int16() {
		STAMPERROR(data.size() - dataIndex <= sizeof(int16_t), "Packet::GetInt16 - out of bounds.");
		int16_t k = *(int16_t*)(data.data() + dataIndex);
		int16_t o;
		dataIndex += sizeof(int16_t);
		endianFix(&k, &o, sizeof(int16_t));
		return o;
	}
	int32_t Int32() {
		STAMPERROR(data.size() - dataIndex <= sizeof(int), "Packet::GetInt32 - out of bounds.");
		int32_t k = *(int32_t*)(data.data() + dataIndex);
		int32_t o;
		dataIndex += sizeof(int32_t);
		endianFix(&k, &o, sizeof(int32_t));
		return o;
	}
	int64_t Int64() {
		STAMPERROR(data.size() - dataIndex <= sizeof(int64_t), "Packet::GetInt64 - out of bounds.");
		int64_t k = *(int64_t*)(data.data() + dataIndex);
		int64_t o;
		dataIndex += sizeof(int64_t);
		endianFix(&k, &o, sizeof(int64_t));
		return o;
	}
	float Float() {
		STAMPERROR(data.size() - dataIndex <= sizeof(float), "Packet::GetFloat - out of bounds.");
		float k = *(float*)(data.data() + dataIndex);
		float o;
		dataIndex += sizeof(float);
		endianFix(&k, &o, sizeof(float));
		return o;
	}
	double Double() {
		STAMPERROR(data.size() - dataIndex <= sizeof(double), "Packet::GetDouble - out of bounds.");
		double k = *(double*)(data.data() + dataIndex);
		double o;
		dataIndex += sizeof(double);
		endianFix(&k, &o, sizeof(double));
		return o;
	}
	std::string String() {
		uint32_t size = VarUint32();
		std::string str{ };
		str.reserve(size);
		for (int i = 0; i < size; i++) {
			str += Int8();
		}
		return str;
	}
	std::u16string String16() {
		uint32_t size = VarUint32();
		std::u16string str{ };
		str.reserve(size);
		for (int i = 0; i < size; i++) {
			str += Int16();
		}
		return str;
	}
	void Bytes(void* dest, size_t size) {
		STAMPERROR(data.size() - dataIndex <= size, "Packet::GetBytes - out of bounds.");
		uint8_t* k = data.data() + dataIndex;
		memcpy_s(dest, size, k, size);
		dataIndex += size;
	}
};

class PacketBuilder {
	std::vector<uint8_t> data{};
	void UpdateSize() {
		*(uint32_t*)(data.data()) = data.size()-4;
	}
public:
	PacketBuilder(uint16_t id) {
		Uint32(2);
		Uint16(id);
	}

	std::vector<uint8_t>& GetDataBuffer() {
		UpdateSize();
		return data;
	}

	void VarUint32(uint32_t v) {
		for (int i = 0; i < (32 + 6) / 7; i++) {
			uint8_t k = v & 0x7F;
			v >>= 7;
			if (v) k |= 0x80;
			data.push_back(k);
			if (!v) break;
		}
	}
	void VarUint64(uint64_t v) {
		for (int i = 0; i < (64 + 6) / 7; i++) {
			uint8_t k = v & 0x7F;
			v >>= 7;
			if (v) k |= 0x80;
			data.push_back(k);
			if (!v) break;
		}
	}
	void VarInt32(int32_t v) {
		for (int i = 0; i < (32 + 6) / 7; i++) {
			uint8_t k = v & 0x7F;
			v >>= 7;
			if (v) k |= 0x80;
			data.push_back(k);
			if (!v) break;
		}
	}
	void VarInt64(int64_t v) {
		for (int i = 0; i < (64 + 6) / 7; i++) {
			uint8_t k = v & 0x7F;
			v >>= 7;
			if (v) k |= 0x80;
			data.push_back(k);
			if (!v) break;
		}
	}
	void Uint8(uint8_t v) {
		data.push_back(v);
	}
	void Uint16(uint16_t v) {
		uint8_t o[sizeof(v)];
		endianFix(&v, o, sizeof(v));
		data.append_range(o);
	}
	void Uint32(uint32_t v) {
		uint8_t o[sizeof(v)];
		endianFix(&v, o, sizeof(v));
		data.append_range(o);
	}
	void Uint64(uint64_t v) {
		uint8_t o[sizeof(v)];
		endianFix(&v, o, sizeof(v));
		data.append_range(o);
	}
	void Int8(int8_t v) {
		data.push_back((uint8_t)v);
	}
	void Int16(int16_t v) {
		uint8_t o[sizeof(v)];
		endianFix(&v, o, sizeof(v));
		data.append_range(o);
	}
	void Int32(int32_t v) {
		uint8_t o[sizeof(v)];
		endianFix(&v, o, sizeof(v));
		data.append_range(o);
	}
	void Float(float v) {
		uint8_t o[sizeof(v)];
		endianFix(&v, o, sizeof(v));
		data.append_range(o);
	}
	void Double(double v) {
		uint8_t o[sizeof(v)];
		endianFix(&v, o, sizeof(v));
		data.append_range(o);
	}
	void String(std::string v) {
		VarUint32(v.size());
		for (int i = 0; i < v.size(); i++) {
			Uint8(v[i]);
		}
	}
	void String16(std::u16string v) {
		VarUint32(v.size());
		for (int i = 0; i < v.size(); i++) {
			Uint16(v[i]);
		}
	}
	void Bytes(void* source, size_t size) {
		data.insert(data.end(), (uint8_t*)source, (uint8_t*)source + size);
	}
};

class TCPServerClient;

class TCPServer {
	friend class TCPServerClient;
	std::thread thread;
	std::vector<std::shared_ptr<TCPServerClient>> clients;
	std::string port;
	SOCKET ListenSocket;
	ServerState state = ServerState::Uninitialized;


	static inline void ServerThread(TCPServer* self) {
		struct addrinfo* result = NULL;
		int iResult;

		self->ListenSocket = INVALID_SOCKET;
		self->state = ServerState::Initializing;

		// checking Winsock
		if (!winsock) return;

		struct addrinfo hints {};
		hints.ai_family = AF_INET;
		hints.ai_socktype = SOCK_STREAM;
		hints.ai_protocol = IPPROTO_TCP;
		hints.ai_flags = AI_PASSIVE;

		// Resolve the server address and port
		iResult = getaddrinfo(NULL, self->port.c_str(), &hints, &result);
		if (iResult != 0) {
			self->state = ServerState::Failed;
			WSACleanup();
			STAMPSTACK();
			STAMPDMSG("network::TCPServer - getaddrinfo failed with error: " << iResult);
			return;
		}

		// Create a SOCKET for the server to listen for client connections.
		self->ListenSocket = socket(result->ai_family, result->ai_socktype, result->ai_protocol);
		if (self->ListenSocket == INVALID_SOCKET) {
			freeaddrinfo(result);
			STAMPSTACK();
			STAMPDMSG("network::TCPServer - socket failed with error : " << WSAGetLastError());
			self->ListenSocket = INVALID_SOCKET;
			return;
		}

		freeaddrinfo(result);

		while (true) {
			iResult = listen(self->ListenSocket, SOMAXCONN);
			if (iResult == SOCKET_ERROR) {
				STAMPSTACK();
				STAMPDMSG("network::TCPServer - listen failed with error: "<< WSAGetLastError());
				self->ListenSocket = INVALID_SOCKET;
				return;
			}

			SOCKET  ClientSocket = accept(self->ListenSocket, NULL, NULL);
			if (ClientSocket == INVALID_SOCKET) {
				STAMPSTACK();
				STAMPDMSG("network::TCPServer -accept failed with error: " << WSAGetLastError());
				self->ListenSocket = INVALID_SOCKET;
				return;
			}

			if (self->clients.size() >= self->maxClients) {
				closesocket(ClientSocket);
			}
			else {
				//append socket
			}
		}
	}
protected:
	virtual int PacketRecieve(TCPServerClient& client, Packet& packet) { 
		return 0;
	}
	virtual void OnConnect(TCPServerClient& client) { }
	virtual void OnDisconnect(TCPServerClient& client) { }
	virtual void OnError(TCPServerClient& client, int errorCode) { }
public:
	int maxClients = 10;
	size_t maxPacketSize = 0xFFFF;

	TCPServer(std::string port) {
		this->port = port;
		thread = std::thread{ ServerThread, this};
	}
	TCPServer(const TCPServer&) = delete;
	TCPServer& operator =(const TCPServer&) = delete;

	ServerState State() {
		return state;
	}

	void SendToAllExcept(TCPServerClient& source, Packet& packet) {

	}
	void SendTo(TCPServerClient& dest, Packet& packet) {

	}
	void SendToAll(Packet& packet) {

	}
	virtual ~TCPServer() {
		delete &thread;
		thread = {};
		if(ListenSocket != INVALID_SOCKET) closesocket(ListenSocket);
	}
};

class TCPServerClient final {
	friend class TCPServer;
	static inline int idCount = 0;
	std::mutex lock;
	TCPServer* server;
	std::thread thread;
	SOCKET socket;
	int id;
	bool isClosed;
	//value of client

	ClientRecieveState RecieveBuffer(void* buffer, size_t length) {
		std::lock_guard _{ lock };
		int k = 0;
		while (k < length) {
			int iResult = recv(socket, (char*)buffer + k, length - k, 0);
			if (iResult == 0) return ClientRecieveState::Closing;
			if (iResult < 0) return ClientRecieveState::Failed;
			k += iResult;
		}

		return ClientRecieveState::OK;
	}

	//recieve packet function, auto allocates memory for packet

	static inline void ClientThread(TCPServerClient* self) {
		self->server->OnConnect(*self);
		uint32_t lenBuf = 0;
		std::vector<uint8_t> buffer{};
		buffer.reserve(1024);
		while (true) {
			ClientRecieveState crs = self->RecieveBuffer(&lenBuf, sizeof(lenBuf));
			if (crs != ClientRecieveState::OK) break;
			if (lenBuf > self->server->maxPacketSize) break;
			buffer.reserve(lenBuf);
			crs = self->RecieveBuffer(buffer.data(), lenBuf);
			if (crs != ClientRecieveState::OK) break;

			Packet p = Packet{ buffer };
			self->server->PacketRecieve(*self, p);
		}
	}

	TCPServerClient(SOCKET socket, TCPServer* server) {
		id = ++idCount;
		this->socket = socket;
		thread = std::thread{ ClientThread, this };
		this->server = server;
	}
	void SendPacket(std::vector<uint8_t>& packet) {
		std::lock_guard _{ lock };
		int iSendResult = send(socket, (char*)packet.data(), packet.size(), 0);
	}
public:
	int ID() {
		return id;
	}
	bool IsClosed() {
		return isClosed;
	}

	~TCPServerClient() {
		server->OnDisconnect(*this);
		if (socket) {
			closesocket(socket);
			socket = 0;
		}
	}
};