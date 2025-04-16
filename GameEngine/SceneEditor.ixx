export module SceneEditor;

import engine;
import math;
import gamerender;
import winmanager;

export namespace sceneEditor{

	class SceneEditor : wm::RawSceneBase {
		std::shared_ptr<engine::SceneBase> scene;
		SceneEditor(wm::Window* window, std::shared_ptr<engine::SceneBase> scene) : wm::RawSceneBase(window) {
			this->scene = scene;
		}
		virtual void Start() {
		
		}
		virtual void End() {
		
		}
		virtual void Update() {
		
		}
		virtual void SyncUpdate() {
		
		}
		virtual void Render() {
			wm::RawSceneBase::Render();
		}
		virtual void Resize(long width, long height) {
		
		}
	};
};