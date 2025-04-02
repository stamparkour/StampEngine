#version 450

const vec3 lightSource = normalize(vec3(2,1,0));

layout(location = 1) uniform mat4 transform;
layout(std140) uniform ST_Camera {
	mat4 transform;
	mat4 perspective;
	mat4 UI;
	vec3 position;
} camera;

#ifdef VERTEX_SHADER

layout(location = 1) in vec3 position_v;
layout(location = 2) in vec3 normal_v;
layout(location = 3) in vec2 uv_v;
layout(location = 4) in vec4 color_v;

out vec3 worldPos;
out vec3 normal;

void main() {
	normal = (transform * vec4(normal_v, 0)).xyz;
	vec4 wp = transform * vec4(position_v,1);
	worldPos = wp.xyz;
	gl_Position = camera.perspective * camera.transform * wp;
}

#endif

#ifdef FRAGMENT_SHADER

layout(location = 0) out vec4 diffuseColor;
in vec3 worldPos;
in vec3 normal;
const vec4 color = vec4(0.7,0.4,0,1);

void main() {
	vec3 viewNormal = normalize(worldPos - camera.position);
	vec3 reflectionNormal = normalize(viewNormal - 2 * dot(viewNormal, normal) * normal);
	float spectral = dot(reflectionNormal, lightSource);
	spectral = (spectral - 0.992) / (0.998 - 0.992);
	spectral = clamp(spectral, 0, 1);
	spectral *= 0.03;
	float diffuse = max(dot(normal, lightSource),0) * 0.8 + 0.2;
	diffuse *= max(min(worldPos.y + 0.2, 1),0.2);
	diffuseColor = color * diffuse + spectral; //* (localPos.y +  6.0 / 25) * 25 / 12;

}


#endif
