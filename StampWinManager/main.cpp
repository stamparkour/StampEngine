// dllmain.cpp : Defines the entry point for the DLL application.
#include <Windows.h>
#include "SE\stampengine.hpp"
#include "math.hpp"
/*BOOL APIENTRY DllMain(HMODULE hModule, DWORD  ul_reason_for_call, LPVOID lpReserved) {
    switch (ul_reason_for_call)
    {
    case DLL_PROCESS_ATTACH:
        break;
    case DLL_THREAD_ATTACH:
        break;
    case DLL_THREAD_DETACH:
        break;
    case DLL_PROCESS_DETACH:
        break;
    }
    return TRUE;
}*/

namespace win::event {
    void Start(double time);
    void Update(double time);
    void SyncUpdate(double time);
    void Render(double time);
    void Resize(double time, long width, long height);
    void Keydown(swm::VertKey key);
    void Keyup(swm::VertKey key);
    extern swm::StampWindowDesc WIN_DESC;
}

swm::StampWindowDesc win::event::WIN_DESC{
    L"test window.",
    swm::SWDF::DepthBuffer | swm::SWDF::StencilBuffer,
    0,0, //width, height
    { win::event::Start, win::event::Update, win::event::SyncUpdate, win::event::Render, win::event::Resize, win::event::Keydown, win::event::Keyup}
};

int WINAPI wWinMain(_In_ HINSTANCE hInstance, _In_opt_ HINSTANCE hPrevInstance, _In_ PWSTR pCmdLine, _In_ int nCmdShow) {
    swm::initializeSWM(hInstance, { swm::SWIF::Debug });
    auto w = swm::SWHWND(&win::event::WIN_DESC,hInstance);
    w.sleepUntilWindowTerminate();
}

void win::event::Start(double time) {

}
void win::event::Update(double time) {

}
void win::event::SyncUpdate(double time) {

}
void win::event::Render(double time) {

}
void win::event::Resize(double time, long width, long height) {

}
void win::event::Keydown(swm::VertKey key) {

}
void win::event::Keyup(swm::VertKey key) {

}