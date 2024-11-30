export module testScene;

import "glm.h";
import engine;
import gamerender;
import swm;
import math;

export class InitScene : public engine::Scene {
public:

    InitScene() {}
    virtual void Initialize() {
        using namespace engine;
        using namespace engine::component;

        glClearColor(0.6f, 0.2f, 0.8f, 1.0f);
        glClearStencil(0);
        glClearDepth(1);
        glDepthFunc(GL_LEQUAL);
        //glEnable(GL_STENCIL_TEST);
        glEnable(GL_CULL_FACE);
        glEnable(GL_DEPTH_TEST);
        glEnable(GL_BLEND);
        glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
        
        std::shared_ptr<render::SolidMaterial> material{ new render::SolidMaterial() };
        std::fstream shaderFile{ "resources\\shader.glsl" };
        material->shader = render::RenderShaderProgram::ParseStream_glsl(shaderFile, { 0 }, { {"test"}});

        std::shared_ptr<GameObject> cameraObj = CreateObject("Camera");
        std::shared_ptr<Camera> camera = cameraObj->AddComponent<Camera>(Camera::CameraType::Main);
        cameraObj->transform.position = { 0,0,-5 };

        std::shared_ptr<GameObject> testObj = CreateObject("TestMesh");
        std::shared_ptr<MeshRenderer> meshRenderer = testObj->AddComponent<MeshRenderer>();
        meshRenderer->mesh = std::shared_ptr<render::Mesh>( new render::Mesh() );
        std::fstream meshFile{"resources\\mesh.obj"};
        meshRenderer->mesh->set(render::PointP3NUC::ParseStream_obj(meshFile));
        meshRenderer->material = material;

        engine::Scene::Initialize();
    }
    virtual void PreRender(int phase) {
        engine::Scene::PreRender(phase);
    }
    virtual void PostRender(int phase) {
        engine::Scene::PostRender(phase);
    }
    virtual void Resize(long width, long height) {
        engine::Scene::Resize(width, height);
    }
    ~InitScene() {}
};