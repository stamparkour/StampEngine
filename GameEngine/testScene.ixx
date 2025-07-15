module;

#include "debug.h"
#include "glm.h"

export module testScene;

import std;
import engine;
import gamerender;
import winmanager;
import math;

namespace test {
    class InitScene;

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
            float speed = 3;
            if (wm::CurrentWindow()->Keyboard()->isKeyDown(wm::VertKey::W)) {
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
                wm::CurrentWindow()->SetScene<InitScene>();
            }
            if (wm::CurrentWindow()->Keyboard()->isKeyPress(wm::VertKey::F4)) {
                wm::CurrentWindow()->Mouse()->Visibility(true);
                wm::CurrentWindow()->Mouse()->ConstrainCursor(wm::ConstrainCursorState::Free);
            }
            if (wm::CurrentWindow()->Keyboard()->isKeyPress(wm::VertKey::F5)) {
                wm::CurrentWindow()->SetTimeScale(wm::CurrentWindow()->GetTimeScale() / 2);
            }
            if (wm::CurrentWindow()->Keyboard()->isKeyPress(wm::VertKey::F6)) {
                STAMPSTACK();
                STAMPDMSG("dt: " << wm::CurrentWindow()->DeltaTime());
            }
            static int i = 0;
            if (i++ >= 15) {
                auto cursor = wm::CurrentWindow()->Mouse()->GetGameSpacePosition();
                text->text = std::to_string(cursor.x) + "\n" + std::to_string(cursor.y) + "\n";
                std::cout << (1 / wm::CurrentWindow()->DeltaTime()) << std::endl;
                i = 0;
            }
            text->UpdateText();
        }
        //sync safe
        virtual void OnEnable() {}
        //sync safe
        virtual void OnDisable() {}
        //sync safe
        virtual void OnDestroy() {}

    public:
        std::shared_ptr<engine::component::TextRendererUI> text;
    };

    class BoatComponent : public engine::Component {
        //sync safe
        virtual void Start() {}
        //unsafe
        virtual void Update() {
            math::Vec2f force{};
            float Torque = 0;
            math::Mat4f rot = math::Mat4f::RotationZ(angle);
            math::Vec2f dragN = (math::Vec2f)(rot * drag);
            dragN.x = abs(dragN.x);
            dragN.y = abs(dragN.y);
            math::Vec2f dragF = dragN * ((wind - velocity) + (current - velocity) * waterResistanceCo);
            force += dragF;
            math::Vec2f k = current - velocity;

            math::Vec2f rudderPos = (math::Vec2f)(rot * math::Vec2f(0, rudderOffset)) +
                math::Vec2f{ std::sin(rudderAngle + angle), -std::cos(rudderAngle + angle) } *rudderLength / 2;
            math::Vec2f rudderDragV = math::Vec2f{ std::cos(rudderAngle + angle), std::sin(rudderAngle + angle) } *rudderDrag;
            rudderDragV.x = abs(rudderDragV.x);
            rudderDragV.y = abs(rudderDragV.y);
            math::Vec2f rudderForce = rudderDragV * (current - velocity) * waterResistanceCo;

            force += rudderForce;
            Torque -= math::Cross(rudderPos, rudderForce);

            angularVelocity += Torque * wm::CurrentWindow()->DeltaTime() / anglularInertia;
            angularVelocity -= angularVelocity * wm::CurrentWindow()->DeltaTime() * drag.x;
            angle += angularVelocity * wm::CurrentWindow()->DeltaTime();
            velocity += force * wm::CurrentWindow()->DeltaTime() / mass;
            position += velocity * wm::CurrentWindow()->DeltaTime();
            GameObject()->transform.position = math::Vec3f(position.x, 0, position.y);
            GameObject()->transform.rotation = math::Quatf::RotationY(angle);

            /*static int i = 0;
            if (i++ % 15 == 0) {
                std::cout << "fps: " << (1/ wm::CurrentWindow()->DeltaTime()) << std::endl;
                std::cout << "vel x: " << velocity.x << ", z: " << velocity.y << std::endl;
                std::cout << "angVel : " << angularVelocity << std::endl;
                std::cout << std::endl;
            }*/
        }
        //gl context safe
        virtual void Render(engine::RenderLayer phase) {
        }
        //sync safe
        virtual void SyncUpdate() {}
        //sync safe
        virtual void OnEnable() {}
        //sync safe
        virtual void OnDisable() {}
        //sync safe
        virtual void OnDestroy() {}
    public:
        static inline math::Vec2f wind{ 8,0 };
        static inline math::Vec2f current = wind / 20;
        float mass = 20;
        float anglularInertia = 50;
        math::Vec2f position{};
        math::Vec2f velocity{ 1,1 };
        float angle;
        float angularVelocity;
        float rudderOffset = 1.2;
        float rudderLength = 0.14;
        float rudderDrag = 0.14;
        math::Vec2f drag{ 0.02,0.6 };
        float waterResistanceCo = 12;

        float rudderAngle;
        struct {
            float angle = 0;
            float drag = 0;
            float offset = 0;
            float activePercent = 0;
        } sails[8];
    };

    export class InitScene : public engine::SceneBase {
    public:
        InitScene(wm::Window* window) : engine::SceneBase(window) {}
        virtual void Initialize() {
            using namespace engine;
            using namespace engine::component;

            engine::SceneBase::Initialize();

            int maxUBO = 0;
            glGetIntegerv(GL_MAX_UNIFORM_BUFFER_BINDINGS, &maxUBO);
            std::cout << "max ubo: " << maxUBO << std::endl;

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

            std::fstream ariel_24 = std::fstream{ "resources\\ariel_24.fmp", std::ios::in };
            std::shared_ptr<render::FontMap> fontmap = render::FontMap::Parse_fmp(ariel_24);
            fontmap->texture = engine::resource::ResourceManager::GetTexture("stamp:ariel_24")->getSamplerTexture2d();

            std::shared_ptr<render::SolidMaterial> material = std::make_shared<render::SolidMaterial>();
            std::fstream shaderFile{ "resources\\shader.glsl" };
            material->shader = render::RenderShaderProgram::ParseStream_glsl(shaderFile, { 0 }, { {"test"} });
            material->normalMap = engine::resource::ResourceManager::GetTexture("stamp:normal")->getSamplerTexture2d();

            std::shared_ptr<GameObject> cameraObj = CreateObject("Camera");
            std::shared_ptr<Camera> camera = cameraObj->AddComponent<Camera>();
            camera->SetMainCamera();
            camera->isPerspective = true;
            camera->scalePercent = 1;
            std::shared_ptr<ControlComponent> controller = cameraObj->AddComponent<ControlComponent>();
            cameraObj->transform.position = { 0,0,-5 };

            std::shared_ptr<GameObject> testObj = CreateObject("TestMesh");
            std::shared_ptr<MeshRenderer> meshRenderer = testObj->AddComponent<MeshRenderer>();
            auto boatController = testObj->AddComponent<BoatComponent>();
            meshRenderer->mesh = engine::resource::ResourceManager::GetMesh("stamp:boat")->GetMesh();
            meshRenderer->material = material;

            for (int i = 0; i < 2000; i++) {
                std::shared_ptr<GameObject> myObj = CreateObject("TestMesh");
                std::shared_ptr<MeshRenderer> mr = myObj->AddComponent<MeshRenderer>();
                mr->mesh = engine::resource::ResourceManager::GetMesh("stamp:boat")->GetMesh();
                mr->material = material;
                myObj->transform.position.y = (i % 40) % 40;
                myObj->transform.position.x = (i / 40) % 40;
                myObj->transform.position.z = (i / 40) / 40;
            }

            std::shared_ptr<GameObject> oceanObj = CreateObject("Ocean", testObj);
            std::shared_ptr<OceanRenderer> oceanRenderer2 = oceanObj->AddComponent<OceanRenderer>();
            std::shared_ptr<OceanRenderer> oceanRenderer1 = oceanObj->AddComponent<OceanRenderer>();
            std::fstream oceanShaderFile{ "resources\\oceanShader.glsl" };
            oceanRenderer2->ocean.shader = oceanRenderer1->ocean.shader = render::RenderShaderProgram::ParseStream_glsl(oceanShaderFile, { 0 }, {});
            oceanRenderer2->ocean.scale = 256;
            oceanRenderer2->ocean.width = oceanRenderer2->ocean.height = 6;
            oceanRenderer2->ocean.vertOffset = -0.4;

            oceanRenderer2->ocean.noiseTexture = oceanRenderer1->ocean.noiseTexture = engine::resource::ResourceManager::GetTexture("stamp:perlin_noise")->getSamplerTexture2d();

            std::shared_ptr<GameObject> uiObj = CreateObject("uiThingy");
            std::shared_ptr<TransformUI> transformUI = uiObj->AddComponent<TransformUI>();
            transformUI->alignX = -1;
            transformUI->alignY = 1;
            transformUI->pivotX = -1;
            transformUI->pivotY = 1;
            transformUI->width = 100;
            transformUI->height = 100;
            transformUI->offsetX = 100;
            transformUI->offsetY = -100;
            std::shared_ptr<render::UIMaterial> uiMat = std::make_shared<render::UIMaterial>();
            std::fstream shaderUIFile{ "resources\\shaderUI.glsl" };
            uiMat->shader = render::RenderShaderProgram::ParseStream_glsl(shaderUIFile, { 0 }, {});
            uiMat->texture = engine::resource::ResourceManager::GetTexture("stamp:test")->getSamplerTexture2d();
            std::shared_ptr<ButtonUI> buttonUI = uiObj->AddComponent<ButtonUI>();
            buttonUI->actionID = 10;
            std::shared_ptr<ImageRendererUI> imageRendererUI = uiObj->AddComponent<ImageRendererUI>();
            imageRendererUI->material = uiMat;

            std::shared_ptr<GameObject> textObj = CreateObject("textThingy");
            std::shared_ptr<TransformUI> transformUI2 = textObj->AddComponent<TransformUI>();
            transformUI2->alignX = 1;
            transformUI2->pivotX = 1;
            transformUI2->pivotY = 1;
            transformUI2->offsetX = 0;
            transformUI2->offsetY = 100;
            transformUI2->height = 700;
            std::shared_ptr<TextRendererUI> textRen = textObj->AddComponent<TextRendererUI>();
            textRen->fontMap = fontmap;
            std::shared_ptr<render::UIMaterial> uiMat2 = std::make_shared<render::UIMaterial>();
            uiMat2->shader = uiMat->shader;
            uiMat2->color = math::Vec4f(0.5, 0.1, 0.2, 1);
            textRen->material = uiMat2;

            controller->text = textObj->GetComponent<TextRendererUI>();
        }
        virtual void Iterate() {
            engine::SceneBase::Iterate();
            /*double t = this->Window()->DeltaTime();
            int ms = (int)(t * 1000);
            std::cout << ms << "ms" << std::endl;*/
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
        ~InitScene() {}
    };
}