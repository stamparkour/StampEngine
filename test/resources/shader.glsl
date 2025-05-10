#version 450

const vec3 lightSource = normalize(vec3(2,1,0));

layout(std140) uniform ST_Object {
	mat4 transform;
} object;

layout(std140) uniform ST_Camera {
	mat4 transform;
	mat4 perspective;
	mat4 UI;
	vec3 position;
} camera;

layout(location = 10) uniform sampler2D normalMap;
layout(location = 20) uniform sampler2D texture0;

#define CAMERA_UP vec3(camera.transform[0][1], camera.transform[1][1], camera.transform[2][1])
#define CAMERA_RIGHT vec3(camera.transform[0][0], camera.transform[1][0], camera.transform[2][0])
#define CAMERA_FORWARD vec3(camera.transform[0][2], camera.transform[1][2], camera.transform[2][2])
#define TRANSFORM_POSITION vec3(object.transform[3][0], object.transform[3][1], object.transform[3][2])

#ifdef VERTEX_SHADER

layout(location = 1) in vec3 position_v;
layout(location = 2) in vec3 normal_v;
layout(location = 3) in vec2 uv_v;
layout(location = 4) in vec4 color_v;
layout(location = 5) in vec3 tangent_v;
layout(location = 6) in vec3 bitangent_v;

out vec3 worldPos;
out vec2 uv;
out vec3 normal;
out vec3 tangent;
out vec3 bitangent;

void main() {
	uv = uv_v;
	normal = (object.transform * vec4(normal_v, 0)).xyz;
	tangent = (object.transform * vec4(tangent_v, 0)).xyz;
	bitangent = (object.transform * vec4(bitangent_v, 0)).xyz;
	vec4 wp = object.transform * vec4(position_v,1);
	worldPos = wp.xyz;
	gl_Position = camera.perspective * camera.transform * wp;

	//billboard
	// normal = (object.transform * vec4(normal_v, 0)).xyz;
	// vec3 wp1 = TRANSFORM_POSITION + CAMERA_UP * position_v.y + CAMERA_RIGHT * position_v.x;
	// vec4 wp = vec4(wp1, 1);
	// worldPos = wp.xyz;
	// gl_Position = camera.perspective * camera.transform * wp;

}

#endif

#ifdef FRAGMENT_SHADER

layout(location = 0) out vec4 diffuseColor;
in vec3 worldPos;
in vec2 uv;
in vec3 normal;
in vec3 tangent;
in vec3 bitangent;
const vec4 color = vec4(0.7,0.4,0,1);

void main() {
	vec3 localNormal = texture(normalMap, uv).xyz * 2 - 1;
	localNormal = localNormal.x * 2 * tangent + localNormal.y * bitangent + localNormal.z * normal;
	localNormal = normalize(localNormal);

	vec3 viewNormal = normalize(worldPos - camera.position);
	vec3 reflectionNormal = normalize(viewNormal - 2 * dot(viewNormal, localNormal) * localNormal);
	float spectral = dot(reflectionNormal, lightSource);
	spectral = (spectral - 0.995) / (0.998 - 0.995);
	spectral = clamp(spectral, 0, 1);
	spectral *= 0.05;
	float diffuse = max(dot(localNormal, lightSource),0) * 0.8 + 0.2;
	diffuse *= max(min(worldPos.y + 0.2, 1),0.2);
	diffuseColor = color * diffuse + spectral; //* (localPos.y +  6.0 / 25) * 25 / 12;
	//diffuseColor = vec4(localNormal,0);
}


#endif
