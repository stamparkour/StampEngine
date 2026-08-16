// stamp/network/muxer.h

#ifndef STAMP_NETWORK_MUXER_H
#define STAMP_NETWORK_MUXER_H

#include <stamp/task/coroutine.h>

namespace stamp::network {
	class generic_muxer {
	public:
		using packet_t = char*; // get size and co_await pop front
		virtual stamp::task::coroutine<void> process(packet_t blob) = 0;
	};


}

#endif // STAMP_NETWORK_MUXER_H