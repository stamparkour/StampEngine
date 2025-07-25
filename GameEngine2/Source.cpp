#include <string>
#include <iostream>
#include <utility>
#include <stamp/math/vector.h>
#include <stamp/math/quaternion.h>
#include <stamp/math/matrix.h>

#include <Windows.h>

using namespace stamp::math;

int WINAPI wWinMain(_In_ HINSTANCE hInstance, _In_opt_ HINSTANCE hPrevInstance, _In_ PWSTR pCmdLine, _In_ int nCmdShow) {
	
	::Vector2<float> v1(3.0f, 4.0f);
	::Vector2<float> v2(5.0f, 4.0f);
	std::swap(v1, v2);

	::Vector<float, 2> v3{ 0 };
	auto k = static_cast<::Vector<int, 3>>(v3);

	//Matrix<float, 2, 2> m1{ 2, 3 };
	//Matrix<float, 2, 1> m2{ v2 };
	//auto m3 = m1 * m2; // Matrix multiplication

	float i = magnitude(v2);

	Vector3ld myVector = Vector3ld(5, 4, 3);
	Vector3ld forward = Vector3ld::FORWARD;
	auto q = cross(myVector, forward);
	auto t = (myVector + 3.0l) / 5.0l;
	i++;
}