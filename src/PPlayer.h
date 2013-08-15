#ifndef _PPlayer_h_
#define _PPlayer_h_

#include <chipmunk.h>
#include "Player.h"

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

class PPlayer : public Player
{
public:
	Player(Interface *iface);
	virtual ~Player(void);
	

#endif //_PPlayer_h_
