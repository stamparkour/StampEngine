#version 450

layout(location = 1) uniform mat4 transform;
layout(std140) uniform ST_Camera {
	mat4 transform;
	mat4 perspective;
	mat4 UI;
	vec3 position;
} camera;

layout(std140) uniform ST_UIMAT {
	bool texture0;
} uiMat;

layout(location = 20) uniform sampler2D texture0;

#ifdef VERTEX_SHADER

layout(location = 1) in vec3 position_v;
layout(location = 2) in vec3 normal_v;
layout(location = 3) in vec2 uv_v;
layout(location = 4) in vec4 color_v;

out vec3 worldPos;
out vec4 color;
out vec2 uv;

void main() {
	vec4 wp = transform * vec4(position_v,1);
	worldPos = wp.xyz;
	gl_Position = camera.UI * wp;
	color = color_v;
	uv = uv_v;
}

#endif

#ifdef FRAGMENT_SHADER

layout(location = 0) out vec4 diffuseColor;
in vec3 worldPos;
in vec4 color;
in vec2 uv;

void main() {
	diffuseColor = color * (uiMat.texture0 ? texture(texture0, uv) : vec4(1,1,1,1));
}


#endif
