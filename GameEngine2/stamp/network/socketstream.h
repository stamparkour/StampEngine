//stamp/network/socketstream.h

#pragma once
#ifndef STAMP_NETWORK_SOCKETSTREAM_H
#define STAMP_NETWORK_SOCKETSTREAM_H

// Copyright 2025 Elijah Clark, Stamparkour
// 
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.


#include <stdio.h>
#include <istream>
#include <ostream>
#include <winsock2.h>
#include <ws2tcpip.h>
#include <stamp/memory.h>
#include <stamp/network/define.h>

#ifdef STAMP_COMPILER_MSVC
#pragma comment(lib, "Ws2_32.lib")
#endif

STAMP_NETWORK_NAMESPACE_BEGIN

//inline const WSADATA WSADATA_value = []() {
//	WSADATA wsaData;
//	int iResult = WSAStartup(MAKEWORD(2, 2), &wsaData);
//	if (iResult != 0) {
//		printf("WSAStartup failed: %d\n", iResult);
//		char c;
//		std::cin >> c;
//	}
//	return wsaData;
//}();

// WSAStartup
// WSACleanup


template<class CharT, class Traits>
class basic_socketStream : public std::basic_iostream< CharT, Traits>{
public:
	constexpr static std::streamsize buffer_size = BUFSIZ;
	using char_type = CharT;
	using traits_type = Traits;
	using int_type = Traits::int_type;
	using pos_type = Traits::pos_type;
	using off_type = Traits::off_type;
private:

public:
	// waits until a data stream has n bytes available to read
	bool wait(std::streamsize n = 0);
	bool waituntil(unsigned long long time, std::streamsize n = 0);
	bool waitfor(unsigned long long delay, std::streamsize n = 0);

};
class IPacker {};
class Packet {};

//Definitions

STAMP_NETWORK_NAMESPACE_END

#endif