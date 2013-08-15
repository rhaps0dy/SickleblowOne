#include "PLevel.h"

PLevel::PLevel(void)
: mRegPlayers(0), space(0), accdt(0.0f)
{
	space = cpSpaceNew();
	space->iterations = 10;
	space->gravity = cpv(0, GRAVITY);

	FILE *lvcfile = fopen("media/levels/TempleSelva/TempleSelva.lvc", "r");
	float x1, y1, x2, y2;
	do
	{
		fscanf(lvcfile, "%f", &x1);
		fscanf(lvcfile, "%f", &y1);
		fscanf(lvcfile, "%f", &x2);
		fscanf(lvcfile, "%f", &y2);
		shape = cpSpaceAddShape(space, cpSegmentShapeNew(staticBody, cpv(x1,y1), cpv(x2,y2), 0.0f));
		shape->e = 1.0f; shape->u = 1.0f;
		shape->layers = NOT_GRABABLE_MASK;
	}while(!feof(lvcfile));
	fclose(lvcfile);
}

PLevel::~PLevel(void)
{
	cpSpaceEachShape(space, (cpSpaceShapeIteratorFunc)selfShapeFree, space);
	cpSpaceEachConstraint(space, (cpSpaceConstraintIteratorFunc)selfConstraintFree, space);
	cpSpaceEachBody(space, (cpSpaceBodyIteratorFunc)selfBodyFree, space);
	cpSpaceFree(space);
	Level::~Level();
}

void PLevel::registerPlayer(PPlayer *pl)
{
	Level::registerPlayer(pl);
	cpSpaceAddBody(space, pl->getBody);
	for(int i=0; i<pl->getNumShapes(); i++)
	{
		cpSpaceAddShape(space, pl->getShape(i));
	}
}

void PLevel::unregisterPlayer(PPlayer *pl)
{
	cpSpaceRemoveBody(space, pl->getBody);
	for(int i=0; i<pl->getNumShapes(); i++)
	{
		cpSpaceRemoveShape(space, pl->getShape(i));
	}
	Level::unregisterPlayer(pl);
}

void PLevel::update(Ogre::Real dt)
{
	Level::update(Ogre::Real dt);
	accDt += dt;
	while(accDt >= DTCHUNKSIZE)
	{
		accDt -= DTCHUNKSIZE;
		cpSpaceStep(space, DTCHUNKSIZE);
	}
}
		
void PLevel::selfBodyFree(cpBody *body)
{
	cpSpaceRemoveBody(space, body);
	cpBodyFree(body);
}
void PLevel::selfShapeFree(cpShape *shape)
{
	cpSpaceRemoveShape(space, shape);
	cpShapeFree(shape);
}
void PLevel::selfConstraintFree(cpConstraint *constraint)
{
	cpSpaceRemoveConstraint(space, constraint);
	cpConstraintFree(constraint);
}
