#ifndef _PLevel_h_
#define _PLevel_h_

#include <chipmunk.h>
#include <cstdio>

#include "Level.h"
#include "PPlayer.h"

#ifndef SKBLCORE
	#if OGRE_PLATFORM == OGRE_PLATFORM_WIN32
		#ifdef BUILDING_SKBLCORE
			#define SKBLCORE __declspec(dllexport)
		#else
			#define SKBLCORE __declspec(dllimport)
		#endif
	#else
		#define SKBLCORE
	#endif
#endif

class SKBLCORE PLevel : public Level
{
protected:
	std::vector<PPlayer*> mRegPlayers; //llista de jugadors a actualitzar
	cpSpace *mSpace;
	cpFloat accDt;
	int mNumSegments;
	static constexpr int ALLOC_GRANULARITY = 100;
	cpShape **mSegments;
	static constexpr cpFloat DTCHUNKSIZE = 0.0055555555555555555556f; // 1/(60*3)
	
public:
	PLevel(void);
	virtual ~PLevel(void);
	
	virtual void registerPlayer(PPlayer *pl);
	virtual void unregisterPlayer(PPlayer *pl);
	
	virtual void update(Ogre::Real dt);

	cpShape *getSegment(int i);

	//constants del nivell
	static constexpr cpFloat GRAVITY = -981.f;

};
#endif //_PLevel_h_
