#version 450

layout(location = 1) uniform mat4 transform;
layout(std140) uniform ST_Camera {
	mat4 transform;
	mat4 perspective;
	mat4 UI;
} camera;

#ifdef VERTEX_SHADER

layout(location = 1) in vec3 position_v;
layout(location = 2) in vec3 normal_v;
layout(location = 3) in vec2 uv_v;
layout(location = 4) in vec4 color_v;

out vec3 worldPos;
out vec3 normal;

void main() {
	normal = normal_v;
	vec4 wp = transform * vec4(position_v,1);
	worldPos = wp.xyz;
	gl_Position = camera.perspective * camera.transform * wp;
}

#endif

#ifdef FRAGMENT_SHADER

layout(location = 0) out vec4 diffuseColor;
in vec3 worldPos;
in vec3 normal;

void main() {
	diffuseColor = mix(vec4((worldPos + 1) / 2,1), vec4(1,1,1,1) * (dot(normal,vec3(0,1,0)) + 1) / 2,0.5);
}


#endif
