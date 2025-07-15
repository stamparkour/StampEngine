#include <string>
#include <Windows.h>
#include <stamp/math/vector.h>

int WINAPI wWinMain(_In_ HINSTANCE hInstance, _In_opt_ HINSTANCE hPrevInstance, _In_ PWSTR pCmdLine, _In_ int nCmdShow) {
	stamp::math::Vector2<float> v1(3.0f, 4.0f);
	float i = stamp::math::magnitude(v1);
}