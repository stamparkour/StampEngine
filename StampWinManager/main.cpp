// dllmain.cpp : Defines the entry point for the DLL application.
#include <Windows.h>
#include "SWM.hpp"
#include "math.hpp"
#include "render.hpp"
#include <filesystem>
#include <iostream>

using namespace render;

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
    swm::SWDF::DepthBuffer | swm::SWDF::StencilBuffer | swm::SWDF::Vsync,
    0,0, //width, height
    { win::event::Start, win::event::Update, win::event::SyncUpdate, win::event::Render, win::event::Resize, win::event::Keydown, win::event::Keyup}
};

int WINAPI wWinMain(_In_ HINSTANCE hInstance, _In_opt_ HINSTANCE hPrevInstance, _In_ PWSTR pCmdLine, _In_ int nCmdShow) {
    swm::initializeSWM(hInstance, { swm::SWIF::Debug });
    std::cout << "STAMP ENGINE - V1" << std::endl;
    std::cout << "GNU. Stamparkour" << std::endl;
    std::cout << std::filesystem::current_path().string() << std::endl;

    auto w = swm::SWHWND(&win::event::WIN_DESC,hInstance);
    w.sleepUntilWindowTerminate();
}
render::Mesh mesh{};
render::RenderShaderProgram shader{};
void win::event::Start(double time) {
    glClearColor(0.6f,0.2f,0.8f,1.0f);
    glClearStencil(0);
    glClearDepth(1);
    glDepthFunc(GL_LEQUAL);
    glDepthRange(0, 1);
    //glEnable(GL_STENCIL_TEST);
    //glEnable(GL_CULL_FACE);
    glEnable(GL_NORMALIZE);
    //glEnable(GL_DEPTH_TEST);
    glFogi(GL_FOG_MODE, GL_LINEAR);
    glFogf(GL_FOG_START, 0.5);
    glFogf(GL_FOG_END, 1.);
    //glFogfv(GL_FOG_COLOR, 0,0,0,0);
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

    std::vector<RawMeshP3NUC::Point> points{};
    points.push_back(RawMeshP3NUC::Point{ {0.5f,-0.5f,0},{},{1,0},{} });
    points.push_back(RawMeshP3NUC::Point{ {-0.5f,-0.5f,0},{},{0,0},{} });
    points.push_back(RawMeshP3NUC::Point{ {0,0.5f,0},{},{0.5,1},{} });
    RawMeshP3NUC m{ points };
    mesh.set(m);
    ShaderComponent vert{};
    vert.compile(ShaderComponent::ShaderType::VertexShader, R"CAT(#version 460
 layout(location = 0) in vec3 pos;
 layout(location = 1) in vec3 normal;
 layout(location = 2) in vec2 uv;
 layout(location = 3) in vec3 color;
out vec2 frag_uv;
void main() {
    gl_Position = vec4(pos,1);
    frag_uv = uv;
}
)CAT");
    ShaderComponent frag{};
    frag.compile(ShaderComponent::ShaderType::VertexShader, R"CAT(#version 460
in vec2 frag_uv;
layout(location = 0) out vec4 diffuseColor;
void main() {
    diffuseColor = vec4(0.5,0.2,0.5,1);
}
)CAT");
    vert.compile(ShaderComponent::ShaderType::VertexShader, R"CAT(
  
)CAT");
    shader.setShader(vert,frag);
    swm::checkOpenGLErrors();
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