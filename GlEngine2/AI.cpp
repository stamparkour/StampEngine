#include <vector>
#include <stdint.h>
#include <random>

struct Connection {
	float weight;
	unsigned short inIndex;
	unsigned short outIndex;

	bool matchNeuron(const Connection& b) const {
		return inIndex == b.inIndex && outIndex == outIndex;
	}
};

class NEAT_AI {
	std::vector<Connection> connections;
	std::vector<float> bias;
	std::vector<float> neurons;
	unsigned short inputs;
	unsigned short outputs;
	unsigned short hidden;

	unsigned short total() {
		return inputs + outputs + hidden;
	}

	float Rand(float min, float max) {
		static std::default_random_engine e;
		static std::uniform_real_distribution<> dis(min, max);
		return dis(e);
	}
	int RandInt(int min, int max) {
		static std::default_random_engine e;
		static std::uniform_int_distribution<> dis(min, max);
		return dis(e);
	}

	float (*Activation)(float v);
public:
	void Interprate(const float(&input)[], float(&output)[]) {
		for (int i = 0; i < inputs; i++) {
			neurons[i] = input[i];
		}
		for (int i = inputs; i < neurons.size(); i++) {
			neurons[i] = bias[i];
		}
		for (int i = 0; i < connections.size(); i++) {
			auto c = connections[i];
			neurons[c.outIndex] += Activation(neurons[c.inIndex]) * c.weight;
		}
		for (int i = 0; i < outputs; i++) {
			output[i] = neurons[i + inputs];
		}
	}
	NEAT_AI evolve(float rate) {
		for (int i = 0; i < connections.size(); i++) {
			float t = Rand(0, 1);
			if (t < 0.05 / (1 + 5 * connections[i].weight)) {
				connections.erase(connections.begin() + i);
			}
			else {
				connections[i].weight += Rand(-rate, rate);
			}
		}
		while (Rand(0, 1) < 0.1) {
			int in = RandInt(0, inputs + hidden);
			if (in > inputs) in += outputs;
			connections.push_back(Connection{ Rand(-rate, rate), (unsigned short)in, (unsigned short)RandInt(inputs, total()) });
		}
		for (int i = 0; i < neurons.size(); i++) {
			bias[i] += Rand(-rate, rate);
		}
	}
	NEAT_AI(int inputs, int outputs, int hidden, float (*Activation)(float v)) {
		this->Activation = Activation;
		this->inputs = inputs;
		this->outputs = outputs;
		this->hidden = hidden;
		neurons = std::vector<float>(inputs + outputs, 0);
		connections = std::vector<Connection>();
		for (unsigned short i = 0; i < outputs; i++) {
			for (unsigned short j = 0; j < inputs; j++) {
				connections.push_back(Connection{ Rand(-1,1),j,i });
			}
		}
	}
};