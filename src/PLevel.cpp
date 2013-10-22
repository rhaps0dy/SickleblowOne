#include "PLevel.h"

PLevel::PLevel(void)
: mRegPlayers(0), mSpace(0), accDt(0.0f), mNumSegments(0), mSegments(0)
{
	mSpace = cpSpaceNew();
	mSpace->iterations = 10;
	mSpace->gravity = cpv(0, GRAVITY);

	FILE *lvcfile = fopen("media/levels/TempleSelva/TempleSelva.lvc", "r");
	float x1, y1, x2, y2;
	mSegments = (cpShape **) malloc(ALLOC_GRANULARITY*sizeof(cpShape *));
	do
	{
		mNumSegments++;
		if((mNumSegments%ALLOC_GRANULARITY == 1) && (mNumSegments > ALLOC_GRANULARITY))
			//necessitem augmentar la capacitat
			mSegments = (cpShape **) realloc(mSegments, (mNumSegments+ALLOC_GRANULARITY-1)*sizeof(cpShape *) );

		fscanf(lvcfile, "%f", &x1);
		fscanf(lvcfile, "%f", &y1);
		fscanf(lvcfile, "%f", &x2);
		fscanf(lvcfile, "%f", &y2);
		mSegments[mNumSegments-1] = cpSpaceAddShape(mSpace, cpSegmentShapeNew(mSpace->staticBody, cpv(x1,y1), cpv(x2,y2), 0.0f));
		mSegments[mNumSegments-1]->e = 1.0f;
		mSegments[mNumSegments-1]->u = 10.0f;
		
	}while(!feof(lvcfile));
	mSegments = (cpShape **) realloc(mSegments, mNumSegments*sizeof(cpShape *) );
	fclose(lvcfile);
}

PLevel::~PLevel(void)
{
	for(register int i=0; i<mNumSegments; i++)
	{
		cpSpaceRemoveShape(mSpace, mSegments[i]);
		cpShapeFree(mSegments[i]);
	}
	cpSpaceFree(mSpace);
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

cpShape *PLevel::getSegment(int i)
{
	if(i>=mNumSegments) return NULL;
	return mSegments[i];
}
