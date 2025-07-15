module;

#include "debug.h"
#include "glm.h"

export module ChemistrySimScene;

import std;
import engine;
import gamerender;
import winmanager;
import math;

namespace chemistry {

    double timescale = 1;

    //units:
    //mass = g/mol
	//distance = pm (picometer)
	//angle = radian
    struct AtomDescription {
        double mass; //mass = g/mol
        double radius; // (covalent radius)
        int valentElectrons;
        AtomDescription* sudonym;
    };
    struct BondDescription {
        const AtomDescription* atom1, * atom2;
        double length; // picometers
        double partialCharge; // in e (elementary charge)
        double bondEnthalpy; // in kJ/mol
    };

    namespace atom {
        AtomDescription Hydrogen1{ 1.0078, 0.53, 1 };
        AtomDescription Hydrogen2{ 2.0141, 0.53, 1, &Hydrogen1 };
		BondDescription H_HBond{ &Hydrogen1, &Hydrogen1, 72.0, 0, 436.0 };
    }

    class Atom {
		double charge = 0; // in e (elementary charge)
        std::vector<Atom*> bonds{};
    public:
        math::Vec3d position{};
        math::Vec3d momentum{};
        AtomDescription* desc;
    };

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
            static int i = 0;
            if (i++ >= 30) {
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