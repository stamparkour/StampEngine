#pragma once
#include <stdint.h>
#include <vector>
//networking
//serializable object
//serializedata/packet

class SerializeData {

};

class SerializeDataVector {
	std::vector<char> data;
public:
	void add(uint8_t v) {
		data.insert(data.end(), sizeof(uint8_t), v);
	}
	void add(uint16_t v) {
		data.insert(data.end(), sizeof(uint16_t), v);
	}
	void add(uint32_t v) {
		data.insert(data.end(), sizeof(uint32_t), v);
	}
	void add(uint64_t v) {
		data.insert(data.end(), sizeof(uint64_t), v);
	}
	void add(int16_t v) {
		data.insert(data.end(), sizeof(int16_t), v);
	}
	void add(int8_t v) {
		data.insert(data.end(), sizeof(int8_t), v);
	}
	void add(int32_t v) {
		data.insert(data.end(), sizeof(int32_t), v);
	}
	void add(int64_t v) {
		data.insert(data.end(), sizeof(int64_t), v);
	}
	void add(float v) {
		data.insert(data.end(), sizeof(float), v);
	}
	void add(double v) {
		data.insert(data.end(), sizeof(double), v);
	}
	void add(char* v) {
		while (*v) {
			data.push_back(*v);
		}
		data.push_back(*v);
	}
	void add(char* v, size_t c) {
		data.insert(data.end(), c, *v);
	}
	SerializeData toData() {
		return {};
	}
};

class Serializable {
public:
	
};