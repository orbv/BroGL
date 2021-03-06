#pragma once

#include "BShared.h"

#define SHADER_MAX_VERTICES 1000
#define SHADER_MAX_INDICES (6*SHADER_MAX_VERTICES)
#define MAX_ENTITIES 100
#define MAX_POLYS 1000
#define MAX_POLYVERTS 5000
#define MAX_DRAWSURFS 0x1000

typedef float color4f_t[4];

typedef struct {
	glm::vec3 xyz;
	glm::vec3 normal;
	color4f_t color;
} vert;

typedef struct {
	glm::vec3 origin; // world coordinates
	glm::mat4 axis; // world orientation
	glm::vec3 viewOrigin; // origin in local coordinates
	glm::mat4 modelMatrix;
} orientation_t;

typedef struct {
	orientation_t or;
	orientation_t world;
	int viewPortX, viewPortY, viewPortWidth, viewPortHeight;
	float fovX, fovY;
	glm::mat4 projectionMatrix;
} viewParms_t;

// TODO: Using this temporarily to try and make sense of the Q3 renderer
typedef struct {
	glm::vec4 xyz[SHADER_MAX_VERTICES];
	glm::vec3 normal[SHADER_MAX_VERTICES];
	color4f_t vertexColors[SHADER_MAX_VERTICES];
	glIndex_t indexes[SHADER_MAX_INDICES];
	
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

typedef struct {
	surfaceType_t surfaceType;

	int numIndices;
	int *indices;

	int numVerts;
	vert *verts;
} triangles_t;