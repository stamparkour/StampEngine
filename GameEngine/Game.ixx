module;

#include "debug.h"
#include "glm.h"

export module Game;

import std;
import engine;
import gamerender;
import winmanager;
import math;

export namespace game {
	class Chunk : public engine::Component {
		virtual void Start() {
			
		}
		//unsafe
		virtual void Update() {}
		//gl context safe
		virtual void Render(engine::RenderLayer phase) {}
		//sync safe
		virtual void SyncUpdate() {
		}
		virtual void OnEnable() {}
		virtual void OnDisable() {}
		virtual void OnDestroy() {}

		//hightmap texture
		//influence map
		//uvs
	};

	class Player : public engine::Component {
		virtual void Start() {

		}
		//unsafe
		virtual void Update() {}
		//gl context safe
		virtual void Render(engine::RenderLayer phase) {}
		//sync safe
		virtual void SyncUpdate() {
		}
		virtual void OnEnable() {}
		virtual void OnDisable() {}
		virtual void OnDestroy() {}
	};
}