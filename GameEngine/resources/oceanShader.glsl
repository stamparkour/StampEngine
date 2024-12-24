#version 450

const float curveLimit = 8;
const float eps = 0.001;

layout(location = 1) uniform mat4 transform;
layout(std140) uniform ST_Camera {
	mat4 transform;
	mat4 perspective;
	mat4 UI;
} camera;
layout(std140) uniform ST_Ocean {
	float time;
	int width;
	int height;
	int Vy;
	int count;
} ocean;

#ifdef VERTEX_SHADER

out vec3 worldPos;

float getHeight(vec2 v) {
	return (sin(v.x*1.9 + ocean.time * 1.8) * 0.2 + sin(v.y + ocean.time * 2) * 1 + sin(1.2 * v.y + 1.5 * v.x + 0.4 * ocean.time) * 0.4) / 5;
}

void main() {
	vec2 position_v = vec2(-gl_VertexID/ocean.Vy + ocean.width / 2.0, - ocean.height / 2.0);
	float k = mod(gl_VertexID, ocean.Vy);
	if(abs(k - (ocean.Vy - 2)) < eps) {
		position_v += vec2(-1,ocean.height);
	}
	else if(abs(k - (ocean.Vy - 1)) < eps) {
		position_v += vec2(-1,0);
	}
	else {
		position_v += vec2(-mod(k, 2),floor(k / 2));
	}
	position_v *= 0.5;

	float len = length(position_v);

	if(len > curveLimit) {
		position_v = position_v * len / curveLimit;
	}

	/*if(abs(position_v.x) >= curveLimit) {
		position_v.x = position_v.x * position_v.x * sign(position_v.x) / curveLimit;
	}
	if(abs(position_v.y) >= curveLimit) {
		position_v.y = position_v.y * position_v.y * sign(position_v.y) / curveLimit;
	}*/

	vec4 wp = transform * vec4(position_v.x, 1, position_v.y,1);
	
	wp.y = getHeight(wp.xz) * wp.y;
	worldPos = wp.xyz;
	gl_Position = camera.perspective * camera.transform * wp;
}

#endif

#ifdef FRAGMENT_SHADER

layout(location = 0) out vec4 diffuseColor;
in vec3 worldPos;

void main() {
	diffuseColor = vec4(0.1,0.2,0.7,1); //* (worldPos.y +  6.0 / 25) * 25 / 12;
}


#endif
