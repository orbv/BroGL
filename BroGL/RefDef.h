#pragma once

#include "Camera.h"
#include "Entity.h"

class RefDef {
public:
	Camera *camera;

	int numEntities;
	Entity entities[MAX_ENTITIES];

	int numPolys;
	struct poly_s *polys;

	int numDrawSurfs;
	struct drawSurf_s *drawSurfs;

	RefDef();
	virtual ~RefDef();

	//************************************
	// Method:    AddDrawSurf
	// FullName:  RefDef::AddDrawSurf
	// Access:    public 
	// Returns:   int
	// Qualifier:
	// Parameter: surfaceType_t * surface
	//************************************
	int AddDrawSurf(surfaceType_t *surface);

	//************************************
	// Method:    AddEntity
	// FullName:  RefDef::AddEntity
	// Access:    public 
	// Returns:   int
	// Qualifier:
	// Parameter: Entity *
	//************************************
	int AddEntity(Entity*);
};
