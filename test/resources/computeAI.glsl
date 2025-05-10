#version 450

struct Neuron_t {
	float decayRate;
	float threshhold;
	struct {
		uint id;
		float weight;
	} synapses[4];
};

layout(std430) buffer Brain_t {
	uint count;
	Neuron_t neurons[];
} brain;

#ifdef InterpAI
void main() {
	
}
#endif

#ifdef MRI
//generates int2d texture of magnitude of brain activity
void main() {
	
}
#endif
#ifdef graphicMRI
//transforms MRI into a prettier virsion
void main() {
	
}
#endif