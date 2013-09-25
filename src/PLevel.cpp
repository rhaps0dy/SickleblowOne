#include "PLevel.h"

PLevel::PLevel(void)
: mRegPlayers(0), mSpace(0), accDt(0.0f)
{
	mSpace = cpSpaceNew();
	mSpace->iterations = 10;
	mSpace->gravity = cpv(0, GRAVITY);

	FILE *lvcfile = fopen("media/levels/TempleSelva/TempleSelva.lvc", "r");
	float x1, y1, x2, y2;
	cpShape *shape;
	do
	{
		fscanf(lvcfile, "%f", &x1);
		fscanf(lvcfile, "%f", &y1);
		fscanf(lvcfile, "%f", &x2);
		fscanf(lvcfile, "%f", &y2);
		shape = cpSpaceAddShape(mSpace, cpSegmentShapeNew(mSpace->staticBody, cpv(x1*100,y1*100), cpv(x2*100,y2*100), 0.0f));
		shape->e = 1.0f;
		shape->u = 10.0f;
	}while(!feof(lvcfile));
	fclose(lvcfile);
}

PLevel::~PLevel(void)
{
	std::cerr << "anem a fer shapes" << std::endl;
	cpSpaceEachShape(mSpace, (cpSpaceShapeIteratorFunc)postShapeFree, mSpace);
	std::cerr << "anem a fer constraints" << std::endl;
	cpSpaceEachConstraint(mSpace, (cpSpaceConstraintIteratorFunc)postConstraintFree, mSpace);
	std::cerr << "anem a fer bodies" << std::endl;
	cpSpaceEachBody(mSpace, (cpSpaceBodyIteratorFunc)postBodyFree, mSpace);
	std::cerr << "anem a fer spacefree" << std::endl;
	cpSpaceFree(mSpace);
	std::cerr << "fi" << std::endl;
}

void PLevel::registerPlayer(PPlayer *pl)
{
	Level::registerPlayer(pl);
	cpSpaceAddBody(mSpace, pl->getBody());
	for(int i=0; i<PPlayer::numShapes; i++)
	{
		cpSpaceAddShape(mSpace, pl->getShape(i));
	}
}

void PLevel::unregisterPlayer(PPlayer *pl)
{
	cpSpaceRemoveBody(mSpace, pl->getBody());
	for(int i=0; i<PPlayer::numShapes; i++)
	{
		cpSpaceRemoveShape(mSpace, pl->getShape(i));
	}
	Level::unregisterPlayer(pl);
}

void PLevel::update(Ogre::Real dt)
{
	Level::update(dt);
	accDt += dt;
	while(accDt >= DTCHUNKSIZE)
	{
		accDt -= DTCHUNKSIZE;
		cpSpaceStep(mSpace, DTCHUNKSIZE);
	}
}
		
void PLevel::bodyFreeWrap(cpSpace *space, cpBody *body, void *unused)
{
	cpSpaceRemoveBody(space, body);
	cpBodyFree(body);
}

void PLevel::shapeFreeWrap(cpSpace *space, cpShape *shape, void *unused)
{
	cpSpaceRemoveShape(space, shape);
	cpShapeFree(shape);
}

void PLevel::constraintFreeWrap(cpSpace *space, cpConstraint *constraint, void *unused)
{
	cpSpaceRemoveConstraint(space, constraint);
	cpConstraintFree(constraint);
}
void PLevel::postBodyFree(cpBody *body, cpSpace *space)
{
	cpSpaceAddPostStepCallback(space, (cpPostStepFunc)bodyFreeWrap, body, NULL);
}
void PLevel::postConstraintFree(cpConstraint *constraint, cpSpace *space)
{
	cpSpaceAddPostStepCallback(space, (cpPostStepFunc)constraintFreeWrap, constraint, NULL);
}
void PLevel::postShapeFree(cpShape *shape, cpSpace *space)
{
	cpSpaceAddPostStepCallback(space, (cpPostStepFunc)shapeFreeWrap, shape, NULL);
}
