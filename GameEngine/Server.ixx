module;

#include <cstdint>

#include <windows.h>
#include <winsock2.h>
#include <ws2tcpip.h>
#include <stdlib.h>
#include <stdio.h>


#pragma comment (lib, "Ws2_32.lib")
#pragma comment (lib, "Mswsock.lib")
#pragma comment (lib, "AdvApi32.lib")

export module network;

import std;
import "debug.h";

//initialize server
//packet management

class Packet final {
	std::vector<BYTE> data{};
	int dataIndex;
	int packetID;

	void reverseBytes(void* begin, void* end, void* dest) {
		for (BYTE* i = ((BYTE*)end - 1), *j = (BYTE*)dest; i >= begin; i--, j++) {
			*j = *i;
		}
	}

public:
	Packet(const std::vector<BYTE>& data) {
		this->data = data;
		packetID = GetInt32();
	}
	int getPacketID() {
		return packetID;
	}
	int32_t GetInt32() {
		if (data.size() - dataIndex <= sizeof(int)) STAMPERROR("Packet::GetInt32 - out of bounds.");
		int32_t k = (int32_t*)(data[dataIndex]);
		dataIndex += sizeof(int);
		if (std::endian::native == std::endian::little) {

		}
	}
};

struct TCPClient final {
	std::thread managementThread;
	int id;
	//value of client
};



class TCPServer {
	std::vector<std::shared_ptr<TCPClient>> clients;
protected:
	virtual int PacketRecieve(Packet& packet) {

	}
	virtual void OnConnect(std::shared_ptr<TCPClient> client) { }
	virtual void OnDisconnect(std::shared_ptr<TCPClient> client) { }
	virtual void OnError(std::shared_ptr<TCPClient> client, int errorCode) { }
public:
	virtual ~TCPServer() {}
};