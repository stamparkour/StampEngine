module;

#include "debug.h"
#include "glm.h"

export module testPhysicsScene;

import std;
import engine;
import gamerender;
import winmanager;
import math;
import testScene;

namespace physicsTest {
    class ControlComponent : public engine::Component {
        math::Vec2f direction{};
        //sync safe
        virtual void Start() {}
        //unsafe
        virtual void Update() {
            math::Vec2f cursor = (math::Vec2f)wm::CurrentWindow()->Mouse()->GetVelocity();
            cursor *= 0.002;
            direction += cursor;
            GameObject()->transform.rotation = math::Quatf::RotationZXY(direction.y, direction.x, 0);
            float dt = 1.0 / 60;//wm::CurrentWindow()->DeltaTime();
            float speed = 5;
            if (wm::CurrentWindow()->Keyboard()->isKeyDown(wm::VertKey::Shift)) {
                speed *= 2;
            }
            if (wm::CurrentWindow()->Controls()->isActionDown(1)) {
                GameObject()->transform.position += GameObject()->Forward() * dt * speed;
            }
            if (wm::CurrentWindow()->Keyboard()->isKeyDown(wm::VertKey::S)) {
                GameObject()->transform.position += GameObject()->Back() * dt * speed;
            }
            if (wm::CurrentWindow()->Keyboard()->isKeyDown(wm::VertKey::D)) {
                GameObject()->transform.position += GameObject()->Right() * dt * speed;
            }
            if (wm::CurrentWindow()->Keyboard()->isKeyDown(wm::VertKey::A)) {
                GameObject()->transform.position += GameObject()->Left() * dt * speed;
            }
            if (wm::CurrentWindow()->Keyboard()->isKeyDown(wm::VertKey::E)) {
                GameObject()->transform.position += math::Vec3f(0, 1, 0) * dt * speed;
            }
            if (wm::CurrentWindow()->Keyboard()->isKeyDown(wm::VertKey::Q)) {
                GameObject()->transform.position += math::Vec3f(0, -1, 0) * dt * speed;
            }
        }
        //gl context safe
        virtual void Render(engine::RenderLayer phase) {
            if (phase == engine::RenderLayer::MainScene)
                if (wm::CurrentWindow()->Keyboard()->isKeyPress(wm::VertKey::F1)) {
                    static bool k = true;
                    if (k)
                        render::TriangleOutline();
                    else
                        render::TriangleFill();
                    k = !k;
                }

        }
        //sync safe
        virtual void SyncUpdate() {
            if (wm::CurrentWindow()->Keyboard()->isKeyPress(wm::VertKey::F2)) {
                engine::component::Camera::ResizeScreen(1024, 512);
            }
            if (wm::CurrentWindow()->Keyboard()->isKeyPress(wm::VertKey::F3)) {
                wm::CurrentWindow()->SetScene<test::InitScene>();
            }
            if (wm::CurrentWindow()->Keyboard()->isKeyPress(wm::VertKey::F4)) {
                wm::CurrentWindow()->Mouse()->Visibility(true);
                wm::CurrentWindow()->Mouse()->ConstrainCursor(wm::ConstrainCursorState::Free);
            }
            if (wm::CurrentWindow()->Keyboard()->isKeyPress(wm::VertKey::F5)) {
                wm::CurrentWindow()->SetTimeScale(wm::CurrentWindow()->GetTimeScale() / 2);
            }

            static int i = 0;
            if (i++ == 15) {
                std::cout << (1 / wm::CurrentWindow()->DeltaTime()) << std::endl;
                i = 0;
            }
        }
        //sync safe
        virtual void OnEnable() {}
        //sync safe
        virtual void OnDisable() {}
        //sync safe
        virtual void OnDestroy() {}
    };

    class ObjectTestComponent : public engine::Component {
        std::shared_ptr<engine::component::MeshRigidBody> rigidBody;
        math::Vec3f initPos;
        virtual void Start() {
            initPos = GameObject()->transform.position;
            rigidBody = GameObject()->GetComponent<engine::component::MeshRigidBody>();
        }
        //unsafe
        virtual void Update() {
        }
        //gl context safe
        virtual void Render(engine::RenderLayer phase) {}
        //sync safe
        virtual void SyncUpdate() {
            GameObject()->transform.position = math::Vec3f(12, 0, 0) * sin(wm::CurrentWindow()->Time() * 0.3f)
                + math::Vec3f(0, 20, 0) * powf(sin(wm::CurrentWindow()->Time() * 0.4), 8);
            rigidBody->UpdateTransform(true);
        }
        //sync safe
        virtual void OnEnable() {}
        //sync safe
        virtual void OnDisable() {}
        //sync safe
        virtual void OnDestroy() {}
    };

    class ObjectCuller : public engine::Component {
        std::shared_ptr<engine::component::MeshRigidBody> rigidBody;
        virtual void Start() {
            rigidBody = GameObject()->GetComponent<engine::component::MeshRigidBody>();
        }
        //unsafe
        virtual void Update() {
        }
        //gl context safe
        virtual void Render(engine::RenderLayer phase) {}
        //sync safe
        virtual void SyncUpdate() {
            if (GameObject()->transform.position.y < -20) {
                GameObject()->transform.position = math::Vec3f{ 0, 30, 0 };
                rigidBody->velocity = {};
                rigidBody->UpdateTransform();
                rigidBody->UpdateVelocity(true);
            }
        }
        //sync safe
        virtual void OnEnable() {}
        //sync safe
        virtual void OnDisable() {}
        //sync safe
        virtual void OnDestroy() {}
    };

    export class PhysicsScene : public engine::SceneBase {
    public:
        PhysicsScene(wm::Window* window) : engine::SceneBase(window) {}
        virtual void Initialize() {
            using namespace engine;
            using namespace engine::component;
            engine::SceneBase::Initialize();

            wm::CurrentWindow()->Mouse()->Visibility(false);
            wm::CurrentWindow()->Mouse()->ConstrainCursor(wm::ConstrainCursorState::Freeze);

            glClearColor(135.0f / 255, 206.0f / 255, 235.0f / 255, 0.0f);
            glClearStencil(0);
            glClearDepth(0);
            glDepthFunc(GL_GEQUAL);
            glEnable(GL_DEPTH_TEST);
            //glEnable(GL_STENCIL_TEST);
            glEnable(GL_CULL_FACE);
            glCullFace(GL_FRONT);
            glEnable(GL_DEPTH_TEST);
            glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
            glStencilMask(0xFF);
            glDepthMask(GL_TRUE);
            glColorMask(GL_TRUE, GL_TRUE, GL_TRUE, GL_TRUE);
            glLineWidth(0.5f);

            std::shared_ptr<GameObject> cameraObj = CreateObject("Camera");
            std::shared_ptr<Camera> camera = cameraObj->AddComponent<Camera>();
            camera->SetMainCamera();
            camera->isPerspective = true;
            camera->scalePercent = 1;
            std::shared_ptr<ControlComponent> controller = cameraObj->AddComponent<ControlComponent>();
            cameraObj->transform.position = { 0,20,-30 };

            std::shared_ptr<render::SolidMaterial> material = std::make_shared<render::SolidMaterial>();
            std::fstream shaderFile{ "resources\\shader.glsl" };
            material->shader = render::RenderShaderProgram::ParseStream_glsl(shaderFile, { 0 }, { {"test"} });
            material->normalMap = engine::resource::ResourceManager::GetTexture("stamp:normal")->getSamplerTexture2d();

            for (int i = 0; i < 400; i++) {
                std::shared_ptr<GameObject> myObj = CreateObject("TestMesh");
                myObj->AddComponent< ObjectCuller>();
                myObj->transform.position = math::Vec3f{ 0, 5.0f + i * 2, 0 } + math::Vec3f{ engine::RandomFloat(-2, 2), 0, engine::RandomFloat(-2, 2) };
                myObj->transform.rotation = math::Quatf::RotationZXY(engine::RandomFloat(0, 2 * math::PI), engine::RandomFloat(0, 2 * math::PI), engine::RandomFloat(0, 2 * math::PI));
                std::shared_ptr<MeshRenderer> mr = myObj->AddComponent<MeshRenderer>();
                mr->mesh = engine::resource::ResourceManager::GetMesh("stamp:boat")->GetMesh();
                mr->material = material;
                std::shared_ptr<MeshRigidBody> rb = myObj->AddComponent<MeshRigidBody>();
                rb->mesh = engine::resource::ResourceManager::GetMesh("stamp:boat")->GetRawMesh();
            }

            std::shared_ptr<GameObject> coneObj = CreateObject("ConeMesh");
            coneObj->AddComponent<ObjectTestComponent>();
            coneObj->transform.position = { 0,0,0 };
            coneObj->transform.scale = { 10, 2, 10 };
            std::shared_ptr<MeshRenderer> mr2 = coneObj->AddComponent<MeshRenderer>();
            mr2->mesh = engine::resource::ResourceManager::GetMesh("stamp:cone")->GetMesh();
            mr2->material = material;
            std::shared_ptr<MeshRigidBody> rb2 = coneObj->AddComponent<MeshRigidBody>();
            rb2->isConvex = false;
            rb2->layer = engine::physics::Layer::NonMoving;
            rb2->movementType = engine::physics::MovementType::Kinematic;
            rb2->mesh = engine::resource::ResourceManager::GetMesh("stamp:cone")->GetRawMesh();
        }
        virtual void Iterate() {
            engine::SceneBase::Iterate();
        }
        virtual void PreRender(engine::RenderLayer renderLayer) {
            engine::SceneBase::PreRender(renderLayer);
            if (renderLayer == engine::RenderLayer::MainScene) {
                //unsigned int clearColor[] = { engine::FloatToUN8(0.6f), engine::FloatToUN8(0.2f), engine::FloatToUN8(0.8f), engine::FloatToUN8(0.0f) };
                //glClearBufferuiv(GL_COLOR,0, clearColor);
                GLSTAMPERROR;
            }
        }
        virtual void PostRender(engine::RenderLayer renderLayer) {
            engine::SceneBase::PostRender(renderLayer);
        }
        virtual void Resize(long width, long height) {
            engine::SceneBase::Resize(width, height);
        }
        ~PhysicsScene() {}
    };
}