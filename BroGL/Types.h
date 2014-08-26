#pragma once

#include "BShared.h"

#define SHADER_MAX_VERTICES 1000
#define SHADER_MAX_INDICES (6*SHADER_MAX_VERTICES)
#define MAX_ENTITIES 100

typedef struct {
	vec3 xyz;
	vec3 normal;
	byte color[4];
} vert;

typedef struct {
	vec3 origin; // world coordinates
	vec3 axis[3]; // world orientation
	vec3 viewOrigin; // origin in local coordinates
	float modelMatrix[16];
} orientation_t;

typedef struct {
	orientation_t or;
	orientation_t world;
	int viewPortX, viewPortY, viewPortWidth, viewPortHeight;
	float fovX, fovY;
	float projectionMatrix[16];
} viewParms_t;

// TODO: Using this temporarily to try and make sense of the Q3 renderer
typedef struct {
	glIndex_t indexes[SHADER_MAX_INDICES];
	vec4 xyz[SHADER_MAX_VERTICES];
	
	int numIndices;
	int numVertices;
} shaderCommands_t;

typedef enum {
	SF_POLY,
	SF_TRIANGLES,

	SF_MAX = 0x7fffffff // ensures that sizeof( surfaceType_t ) == sizeof( int )
} surfaceType_t;

typedef struct drawSurf_s {
	surfaceType_t *surface;
} drawSurf_t;

typedef struct poly_s {
	surfaceType_t surfaceType;
	int numVerts;
	vert *verts;
} poly_t;