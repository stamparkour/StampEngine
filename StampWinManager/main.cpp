// dllmain.cpp : Defines the entry point for the DLL application.
#include <Windows.h>
import "glm.h";
import <filesystem>;
import <iostream>;

import render;
import swm;
import testScene;

using namespace render;

int WINAPI wWinMain(_In_ HINSTANCE hInstance, _In_opt_ HINSTANCE hPrevInstance, _In_ PWSTR pCmdLine, _In_ int nCmdShow) {
    swm::StampWindowDesc WIN_DESC{
    L"test window.",
    swm::SWDF::DepthBuffer | swm::SWDF::StencilBuffer | swm::SWDF::Vsync | swm::SWDF::TitleBar | swm::SWDF::Maximizable | swm::SWDF::Borderless ,
    0,0, //width, height
    };

    swm::initializeSWM(&WIN_DESC, hInstance, { swm::SWIF::Debug });
    std::cout << "STAMP ENGINE - V1" << std::endl;
    std::cout << "GNU. Stamparkour" << std::endl;
    std::cout << std::filesystem::current_path().string() << std::endl;
    swm::sleepUntilGLContext();
    swm::initScene<InitScene>();
    swm::sleepUntilWindowTerminate();
}

