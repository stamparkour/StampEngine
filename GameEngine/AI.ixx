module;

#include <cstdint>
#include <vector>

export module AI;
import math;

struct Synaps {
	uint32_t index;
	float weight;
};
struct Neuron {
	math::Vec3<int16_t> pos;
	float potential;
	float threshold;
	float decay;
	Synaps synapses[4];
};
struct Region {
	std::vector<Neuron*> refrences{};
};
struct RegionManager {
	int size;
	int count;
};