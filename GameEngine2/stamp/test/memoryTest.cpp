#include <stamp/define.h>
#ifdef STAMP_MICROSOFT_UNITTEST

#include <stamp/memory.h>
#include <CppUnitTest.h>

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace STAMP_NAMESPACE;
using namespace std;

namespace Memory {

TEST_CLASS(ThreadSafePointer) {
public:
	TEST_METHOD(DefaultConstructor) {
		threadsafe_ptr<int> ptr;
		Assert::IsTrue(!ptr);
	}
	TEST_METHOD(Constructor) {
		threadsafe_ptr<int> ptr{ new int(7) };
		Assert::IsTrue((bool)ptr);
		Assert::AreEqual(*ptr.get_readonly(), 7);
	}
	TEST_METHOD(MakeThreadSafe) {
		threadsafe_ptr<int> ptr = make_threadsafe<int>(3);
		Assert::AreEqual(*ptr.get_readonly(), 3);
	}
	TEST_METHOD(ReadWrite) {
		threadsafe_ptr<int> ptr = make_threadsafe<int>(3);
		Assert::AreEqual(*ptr.get_readonly(), 3);
		{
			auto w = ptr.get();
			*w = 5;
		}
		Assert::AreEqual(*ptr.get_readonly(), 5);
	}
	TEST_METHOD(SharedCount) {
		threadsafe_ptr<int> ptr = make_threadsafe<int>(3);
		Assert::AreEqual((int)ptr.use_count(), 1);
		{
			threadsafe_ptr<int> ptr2 = ptr;
			Assert::AreEqual((int)ptr.use_count(), 2);
		}
		Assert::AreEqual((int)ptr.use_count(), 1);
		Assert::AreEqual(*ptr.get_readonly(), 3);
	}
};

//TEST_CLASS(Benchmark) {
//public:
//	TEST_METHOD(SharedPointer) {
//		for (int i = 0; i < STAMP_BENCHMARK_LOOPCOUNT; ++i) {
//			shared_ptr<int> ptr = make_shared<int>(i);
//		}
//	}
//	TEST_METHOD(ThreadSafePointer) {
//		for (int i = 0; i < STAMP_BENCHMARK_LOOPCOUNT; ++i) {
//			threadsafe_ptr<int> ptr = make_threadsafe<int>(i);
//		}
//	}
//};
}

#endif