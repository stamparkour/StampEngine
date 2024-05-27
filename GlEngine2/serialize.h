#pragma once
#include <stdint.h>
#include <memory>
#include <vector>
//networking
//serializable object
//serializedata/packet

class SerializeData {
	std::shared_ptr<char> buffer;
	uint32_t length = 0;
	size_t index = 0;
public:
	SerializeData(std::shared_ptr<char> buffer) : buffer(buffer) {
		length = Uint32();
	}
	uint8_t Uint8() {
		auto v = *(uint8_t*)(buffer.get() + index);
		index += sizeof(uint8_t);
		return v;
	}
	uint16_t Uint16() {
		auto v = *(uint16_t*)(buffer.get() + index);
		index += sizeof(uint16_t);
		return v;
	}
	uint32_t Uint32() {
		auto v = *(uint32_t*)(buffer.get() + index);
		index += sizeof(uint32_t);
		return v;
	}
	uint64_t Uint64() {
		auto v = *(uint64_t*)(buffer.get() + index);
		index += sizeof(uint64_t);
		return v;
	}
	char Char() {
		auto v = *(char*)(buffer.get() + index);
		index += sizeof(char);
		return v;
	}
	int8_t Int8() {
		auto v = *(int8_t*)(buffer.get() + index);
		index += sizeof(int8_t);
		return v;
	}
	int16_t Int16() {
		auto v = *(int16_t*)(buffer.get() + index);
		index += sizeof(int16_t);
		return v;
	}
	int32_t Int32() {
		auto v = *(int32_t*)(buffer.get() + index);
		index += sizeof(int32_t);
		return v;
	}
	int64_t Int64() {
		auto v = *(int64_t*)(buffer.get() + index);
		index += sizeof(int64_t);
		return v;
	}
	float Float() {
		auto v = *(float*)(buffer.get() + index);
		index += sizeof(float);
		return v;
	}
	double Double() {
		auto v = *(double*)(buffer.get() + index);
		index += sizeof(double);
		return v;
	}
	std::shared_ptr<char> String() {
		uint32_t l = Uint32();
		char* v = new char[l];
		for (int i = 0; i < l; i++) {
			v[i] = Char();
		}
		return std::shared_ptr<char>{ v };
	}
	std::shared_ptr<char> Array(size_t l) {
		char* v = new char[l];
		for (int i = 0; i < l; i++) {
			v[i] = Char();
		}
		return std::shared_ptr<char>{ v };
	}
};

class SerializeDataVector {
	std::vector<char> data;
public:
	void Uint8(uint8_t v) {
		data.insert(data.end(), sizeof(uint8_t), v);
	}
	void Uint16(uint16_t v) {
		data.insert(data.end(), sizeof(uint16_t), v);
	}
	void Uint32(uint32_t v) {
		data.insert(data.end(), sizeof(uint32_t), v);
	}
	void Uint64(uint64_t v) {
		data.insert(data.end(), sizeof(uint64_t), v);
	}
	void Char(char v) {
		data.insert(data.end(), sizeof(char), v);
	}
	void Int8(int8_t v) {
		data.insert(data.end(), sizeof(int8_t), v);
	}
	void Int16(int16_t v) {
		data.insert(data.end(), sizeof(int16_t), v);
	}
	void Int32(int32_t v) {
		data.insert(data.end(), sizeof(int32_t), v);
	}
	void Int64(int64_t v) {
		data.insert(data.end(), sizeof(int64_t), v);
	}
	void Float(float v) {
		data.insert(data.end(), sizeof(float), v);
	}
	void Double(double v) {
		data.insert(data.end(), sizeof(double), v);
	}
	void String(const char* v) {
		Uint32(strlen(v));
		while (*v) {
			data.push_back(*v);
		}
	}
	void Array(const char* v, size_t c) {
		data.insert(data.end(), c, *v);
	}
	SerializeData toData() const {
		int length = data.size();
		char* v = new char[length+sizeof(uint32_t)];
		*(int*)v = length+sizeof(uint32_t);
		for (int i = 0; i < length; i++) {
			v[i + sizeof(uint32_t)] = data[i];
		}
		return { std::shared_ptr<char>{v} };
	}
};

class Serializable {
public:
	virtual SerializeData Serialize() = 0;
	virtual void Deserialize(SerializeData& data) = 0;
};