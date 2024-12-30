#version 450

const float eps = 0.01;
const vec3 lightSource = normalize(vec3(2,1,0));

layout(location = 1) uniform mat4 transform;
layout(std140) uniform ST_Camera {
	mat4 transform;
	mat4 perspective;
	mat4 UI;
	vec3 position;
} camera;
layout(std140) uniform ST_Ocean {
	float time;
	int width;
	int height;
	int Vy;
	int count;
	float scale;
	float vertOffset;
} ocean;

float getHeight(vec2 v) {
	return (sin(v.x*1.94 + ocean.time * 2.81) * 0.14 + sin(v.x*-0.74 + v.y*0.36 + ocean.time *1.74) * 0.3 + sin(0.52 * v.y + 0.54 * v.x + 0.74 * ocean.time) * 0.63) / 4;
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
		position_v += vec2(-mod(k, 2), floor(k / 2));
	}
	position_v *= ocean.scale;


	/*if(abs(position_v.x) >= curveLimit) {
		position_v.x = position_v.x * position_v.x * sign(position_v.x) / curveLimit;
	}
	if(abs(position_v.y) >= curveLimit) {
		position_v.y = position_v.y * position_v.y * sign(position_v.y) / curveLimit;
	}*/

	vec4 wp = transform * vec4(position_v.x, 1, position_v.y,1);
	
	wp.y = getHeight(wp.xz) * wp.y + ocean.vertOffset;
	worldPos = wp.xyz;
	gl_Position = camera.perspective * camera.transform * wp;
}

#endif

#ifdef FRAGMENT_SHADER

layout(location = 0) out vec4 diffuseColor;
in vec3 worldPos;
const vec4 color = vec4(0.1,0.2,0.7,1);
void main() {
	vec3 normal = getNormal(worldPos.xz);
	vec3 viewNormal = normalize(worldPos - camera.position);
	vec3 reflectionNormal = normalize(viewNormal - 2 * dot(viewNormal, normal) * normal);
	float spectral = dot(reflectionNormal, lightSource);
	float aura = max(0.5,dot(reflectionNormal, viewNormal));
	spectral = (spectral - 0.985) / (0.992 - 0.985);
	spectral = clamp(spectral, 0, 1);
	diffuseColor = color * aura + spectral; //* (worldPos.y +  6.0 / 25) * 25 / 12;
	if(ocean.scale < 64) diffuseColor.a = ( ocean.width * ocean.scale / 2 - max(abs(worldPos.x), abs(worldPos.z)) ) ;
	else diffuseColor.a = 1;
	//diffuseColor = vec4(normal.x,0,normal.z,1);
}


#endif
