#ifndef _Level_h_
#define _Level_h_
#include <OgreMath.h>
#include <vector>

#if OGRE_PLATFORM == OGRE_PLATFORM_WIN32
	#ifdef BUILDING_SKBLCORE
		#define SKBLCORE __declspec(dllexport)
	#else
		#define SKBLCORE __declspec(dllimport)
	#endif
#else
	#define SKBLCORE
#endif

#include "Player.h"

class SKBLCORE Level
{
protected:
	std::vector<Player*> mRegPlayers; //llista de jugadors a actualitzar
	
public:
	Level(void);
	virtual ~Level(void);
	
	virtual void registerPlayer(Player *pl);
	virtual void unregisterPlayer(Player *pl);
	
	virtual void update(Ogre::Real dt);
};
#endif //_Level_h_
