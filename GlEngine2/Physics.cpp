#include "gamecore.h"

class ChargedParticle : public game::core::Component {
	Component_Requirements(ChargedParticle)
		inline static std::vector<ChargedParticle*> particles;
public:
	float charge;
	game::math::Vec3 velocity;

	ChargedParticle(float charge = 0) {
		this->charge = charge;
	}
	void Awake() override {
		particles.push_back(this);
	}
	void OnDestroy() override {
		int index = -1;
		for (int i = 0; i < particles.size(); i++) {
			if (particles[i] == this) {
				index = i;
			}
		}
		if (index != -1) particles.erase(particles.begin() + index);
	}
	void Update() override {
		game::math::Vec3 force = {};
		for (int i = 0; i < particles.size(); i++) {
			if (particles[i] == this) continue;
			game::math::Vec3 elec = particles[i]->getElecticField(selfObject()->transform.position);
			game::math::Vec3 mag = particles[i]->ElectricToMagnetic(elec, selfObject()->transform.position);
			force += elec + game::math::Vec3::Cross(velocity, mag);
		}
		force *= charge;
		velocity += force * game::core::TimeManager::DeltaTime();
		selfObject()->transform.position += velocity * game::core::TimeManager::DeltaTime();

		for (int i = 0; i < particles.size(); i++) {
			if (particles[i] == this) continue;
			auto vec = particles[i]->selfObject()->transform.position - selfObject()->transform.position;
			float mag = vec.Magnitude();
			auto norm = vec / mag;
			if (mag > 0.1 && mag < 2) {
				float dist = (2 - mag) / 2;
				particles[i]->selfObject()->transform.position += vec * dist;
				selfObject()->transform.position -= vec * dist;
				auto ine = (velocity + particles[i]->velocity) / 2;
				auto velo = particles[i]->velocity - velocity;
				auto ela = norm * game::math::Vec3::Dot(norm, velo);
				float elastisity = 0.9;
				velocity = ine + (ela + velocity - ine) * elastisity;
				particles[i]->velocity = ine + (-ela + particles[i]->velocity - ine) * elastisity;
				particles[i]->charge = charge = (particles[i]->charge + charge) / 2;
			}
		}
	}

	game::math::Vec3 getElecticField(game::math::Vec3 pos) {
		float SpeedOfLight = 299792458;
		float vacuumPermittivity = 8.854187818814e-12;
		pos = selfObject()->transform.position - pos;
		float dist = pos.Magnitude();
		if (dist < 0.1) return {};
		float c = -charge / (4 * PI * vacuumPermittivity);
		float d3 = pow(dist, 3);
		float d5 = pow(dist, 5);
		float d7 = pow(dist, 7);
		auto A = pos / d3;
		auto B = (game::math::Vec3{ 1 / d3 - 3 * (float)pow(pos.x,2) / d5, 1 / d3 - 3 * (float)pow(pos.y,2) / d5, 1 / d3 - 3 * (float)pow(pos.z,2) / d5 }) * dist / SpeedOfLight;
		auto C = (game::math::Vec3{ 3 * pos.x * (5 * (float)pow(pos.x,2) / d7 - 3 / d5),3 * pos.y * (5 * (float)pow(pos.y,2) / d7 - 3 / d5),3 * pos.z * (5 * (float)pow(pos.z,2) / d7 - 3 / d5) }) * dist / SpeedOfLight;
		return (A + B + C) * c;
	}
	game::math::Vec3 ElectricToMagnetic(game::math::Vec3 elec, game::math::Vec3 pos) {
		pos = selfObject()->transform.position - pos;
		float SpeedOfLight = 299792458;
		return game::math::Vec3::Cross(-pos.Normal(), elec / SpeedOfLight);
	}
};