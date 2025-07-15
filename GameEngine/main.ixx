// dllmain.cpp : Defines the entry point for the DLL application.
#include <Windows.h>
import "glm.h";

import winmanager;
import testScene;
import testPhysicsScene;
import std;


int WINAPI wWinMain(_In_ HINSTANCE hInstance, _In_opt_ HINSTANCE hPrevInstance, _In_ PWSTR pCmdLine, _In_ int nCmdShow) {
    //swm::StampWindowDesc WIN_DESC{
    //L"test window.",
    //swm::SWDF::DepthBuffer | swm::SWDF::StencilBuffer | swm::SWDF::Vsync | swm::SWDF::TitleBar | swm::SWDF::Maximizable,
    //1200,900, //width, height
    //};

    //swm::initializeSWM(&WIN_DESC, hInstance);
    
    //std::cout << std::filesystem::current_path().string() << std::endl;
    //swm::sleepUntilGLContext();
    //swm::initScene<InitScene>();
    //swm::sleepUntilWindowTerminate();



    wm::Window window("test window.", {});

    std::cout << "STAMP ENGINE - V1" << std::endl;
    std::cout << " -- Stamparkour" << std::endl;
    //wm::Window window2("test window2.", {});

    //window.SetWindowState(wm::ShowWindowState::Borderless);
    window.SetClientSize(1200, 900);
    window.SetGameRatioOptimal();
    //window2.SetClientSize(1300, 900);
    //window.Mouse()->Visibility(false);
    //window.Mouse()->ConstrainCursor(wm::ConstrainCursorState::Freeze);

	window.SetScene<physicsTest::PhysicsScene>();

    window.AwaitClose();
    //window2.AwaitClose();

}

