module;

#include "debug.h"
#include "glm.h"

export module testScene;

import std;
import engine;
import gamerender;
import swm;
import math;

class ControlComponent : public engine::Component {
    math::Vec2f direction{};
    //sync safe
    virtual void Start() {}
    //unsafe
    virtual void Update() {
        math::Vec2f cursor{(float)swm::getCursorDeltaX(), (float)swm::getCursorDeltaY()};
        cursor *= 0.002;
        direction += cursor;
        GameObject()->transform.rotation = math::Quatf::RotationZXY(direction.y, direction.x,0);
        float speed = 5;
        if (swm::isKeyHold(swm::VertKey::W)) {
            GameObject()->transform.position += GameObject()->Forward() * swm::DeltaTime() * speed;
        }
        if (swm::isKeyHold(swm::VertKey::S)) {
            GameObject()->transform.position += GameObject()->Back() * swm::DeltaTime() * speed;
        }
        if (swm::isKeyHold(swm::VertKey::D)) {
            GameObject()->transform.position += GameObject()->Right() * swm::DeltaTime() * speed;
        }
        if (swm::isKeyHold(swm::VertKey::A)) {
            GameObject()->transform.position += GameObject()->Left() * swm::DeltaTime() * speed;
        }
        if (swm::isKeyHold(swm::VertKey::E)) {
            GameObject()->transform.position += math::Vec3f(0,1,0) * swm::DeltaTime() * speed;
        }
        if (swm::isKeyHold(swm::VertKey::Q)) {
            GameObject()->transform.position += math::Vec3f(0, -1, 0) * swm::DeltaTime() * speed;
        }
        static int i = 0;
        if (i++ % 30 == 0) {
            std::cout << "pos x: " << GameObject()->transform.position.x << ", z: " << GameObject()->transform.position.z << std::endl;
        }


    }
    //gl context safe
    virtual void Render(int phase) {
        if(phase == 0)
        if (swm::isKeyDown(swm::VertKey::F1)) {
            static bool k = true;
            if (k)
                render::TriangleOutline();
            else
                render::TriangleFill();
            k = !k;
        }
    }
    //sync safe
    virtual void SyncUpdate() {}
    //sync safe
    virtual void OnEnable() {}
    //sync safe
    virtual void OnDisable() {}
    //sync safe
    virtual void OnDestroy() {}
};

export class InitScene : public engine::Scene {
public:
    InitScene() {}
    virtual void Initialize() {
        using namespace engine;
        using namespace engine::component;

        swm::setCursorVisibility(false);
        swm::setCursorConstraint(swm::CursorConstraintState::Frozen);

        glClearColor(135.0f/255, 206.0f/255, 235.0f/255, 0.0f);
        glClearStencil(0);
        glClearDepth(0);
        glDepthFunc(GL_GEQUAL);
        glEnable(GL_DEPTH_TEST);
        //glEnable(GL_STENCIL_TEST);
        glEnable(GL_CULL_FACE);
        glCullFace(GL_FRONT);
        glEnable(GL_DEPTH_TEST);
        glEnable(GL_BLEND);
        glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
        glStencilMask(0xFF);
        glDepthMask(GL_TRUE);
        glColorMask(GL_TRUE, GL_TRUE, GL_TRUE, GL_TRUE);
        
        std::shared_ptr<render::SolidMaterial> material{ new render::SolidMaterial() };
        std::fstream shaderFile{ "resources\\shader.glsl" };
        material->shader = render::RenderShaderProgram::ParseStream_glsl(shaderFile, { 0 }, { {"test"}});
        std::shared_ptr<GameObject> cameraObj = CreateObject("Camera");
        std::shared_ptr<Camera> camera = cameraObj->AddComponent<Camera>(Camera::CameraType::Main);
        camera->scalePercent = 1.2;
        std::shared_ptr<ControlComponent> controller = cameraObj->AddComponent<ControlComponent>();
        cameraObj->transform.position = { 0,0,-5 };

        std::shared_ptr<GameObject> testObj = CreateObject("TestMesh");
        testObj->transform.position = { 0,0,0 };
        std::shared_ptr<MeshRenderer> meshRenderer = testObj->AddComponent<MeshRenderer>();
        meshRenderer->mesh = std::shared_ptr<render::Mesh>( new render::Mesh() );
        std::fstream meshFile{"resources\\mesh.mesh"};
        math::Mat4f meshTmpTranform = math::Mat4f::RotationY(-math::DEGTORAD * 90);
        meshRenderer->mesh->set(render::PointP3NUC::ParseStream_obj(meshFile, &meshTmpTranform));
        meshRenderer->material = material;
        std::shared_ptr<GameObject> oceanObj = CreateObject("Ocean");
        testObj->transform.position = { 0,0,0 };
        std::shared_ptr<OceanRenderer> oceanRenderer2 = oceanObj->AddComponent<OceanRenderer>();
        std::shared_ptr<OceanRenderer> oceanRenderer1 = oceanObj->AddComponent<OceanRenderer>();
        std::fstream oceanShaderFile{ "resources\\oceanShader.glsl" };
        oceanRenderer2->ocean.shader = oceanRenderer1->ocean.shader = render::RenderShaderProgram::ParseStream_glsl(oceanShaderFile, { 0 }, {});
        oceanRenderer2->ocean.scale = 256;
        oceanRenderer2->ocean.width = oceanRenderer2->ocean.height = 6;
        oceanRenderer2->ocean.vertOffset = -1;
        engine::Scene::Initialize();
    }
    virtual void Iterate() {
    }
    virtual void PreRender(int phase) {
        if (phase == 0) {
            glClear(GL_DEPTH_BUFFER_BIT | GL_STENCIL_BUFFER_BIT | GL_COLOR_BUFFER_BIT);
            //unsigned int clearColor[] = { engine::FloatToUN8(0.6f), engine::FloatToUN8(0.2f), engine::FloatToUN8(0.8f), engine::FloatToUN8(0.0f) };
            //glClearBufferuiv(GL_COLOR,0, clearColor);
            GLSTAMPERROR;
        }
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