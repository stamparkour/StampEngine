#version 450

const float eps = 0.2;
const vec3 lightSource = normalize(vec3(2,1,0));

layout(binding = 1) uniform sampler2D noise;
layout(std140, binding = 1) uniform ST_Object {
	mat4 transform;
	float time;
	int width;
	int height;
	int Vy;
	int count;
	float scale;
	float vertOffset;
	vec3 origin;
} object;
layout(std140, binding = 0) uniform ST_Camera {
	mat4 transform;
	mat4 perspective;
	mat4 UI;
	vec3 position;
} camera;

float getHeight(vec2 v) {
	return pow(texture(noise,v / 82 + vec2(0.01,0.02) * object.time).r,3) * 2 + texture(noise,v / 23 + vec2(0.2,0.07) + vec2(0.03,0.01) * object.time).g * 0.6 - 0.6;
}

vec3 getNormal(vec2 v) {
	float A = getHeight(v);
	float B = getHeight(v+vec2(eps,0));
	float C = getHeight(v+vec2(0,eps));
	vec3 o = vec3((B-A)/eps,1,(C-A)/eps);
	return normalize(o);
}

#ifdef VERTEX_SHADER

out vec3 worldPos;
out vec3 localPos;

void main() {
	vec2 position_v = vec2(-gl_VertexID/object.Vy + object.width / 2.0, - object.height / 2.0);
	float k = mod(gl_VertexID, object.Vy);
	if(abs(k - (object.Vy - 2)) < eps) {
		position_v += vec2(-1,object.height);
	}
	else if(abs(k - (object.Vy - 1)) < eps) {
		position_v += vec2(-1,0);
	}
	else {
		position_v += vec2(-mod(k, 2), floor(k / 2));
	}
	position_v *= object.scale;


	/*if(abs(position_v.x) >= curveLimit) {
		position_v.x = position_v.x * position_v.x * sign(position_v.x) / curveLimit;
	}
	if(abs(position_v.y) >= curveLimit) {
		position_v.y = position_v.y * position_v.y * sign(position_v.y) / curveLimit;
	}*/

	vec4 wp = object.transform * vec4(position_v.x, 1, position_v.y,1);
	
	if(object.scale < 64) wp.y = getHeight(wp.xz) * wp.y + object.vertOffset;
	else wp.y = -0.5;
	worldPos = wp.xyz;
	localPos = wp.xyz - object.origin;
	gl_Position = camera.perspective * camera.transform * wp;
}

#endif

#ifdef FRAGMENT_SHADER

layout(location = 0) out vec4 diffuseColor;
in vec3 worldPos;
in vec3 localPos;
const vec4 color = vec4(0.11,0.17,0.74,1);
void main() {
	vec3 normal = getNormal(worldPos.xz);
	vec3 viewNormal = normalize(worldPos - camera.position);
	vec3 reflectionNormal = normalize(viewNormal - 2 * dot(viewNormal, normal) * normal);
	float spectral = dot(reflectionNormal, lightSource);
	float aura = max(0.4,dot(reflectionNormal, viewNormal));
	spectral = (spectral - 0.985) / (0.996 - 0.985);
	spectral = clamp(spectral, 0, 1);
	diffuseColor = color * aura + spectral; //* (localPos.y +  6.0 / 25) * 25 / 12;
	if(object.scale < 64) diffuseColor.a = ( object.width * object.scale / 2 - length(localPos) ) ;
	else diffuseColor.a = 1;
}


#endif
