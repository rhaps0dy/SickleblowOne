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

class SKBLCORE PPlayer : public Player
{
public:
	PPlayer(Interface *iface);
	virtual ~PPlayer(void);
	static void bodyUpdateVelocity(cpBody *body, cpVect gravity, cpFloat damping, cpFloat dt);
	virtual void update(Ogre::Real dt);

	inline cpBody *getBody(void){ return mBody;}
	inline cpShape *getShape(int i){ return mShapes[i];}

	static constexpr cpFloat mass = 1.0f;
	static constexpr int numShapes = 1;
	static constexpr Ogre::Real RUN_SPEED_UNCORRECTED = RUN_SPEED/Interface::MAX_JOY;
	static constexpr Ogre::Real RUN_ACCEL_TIME = 0.05f;
	static constexpr Ogre::Real RUN_ACCEL = RUN_SPEED/RUN_ACCEL_TIME;
	static constexpr Ogre::Real JUMP_SPEED = 400.0f; 
	static constexpr Ogre::Real JUMP_BOOST_TIME = 0.2f; 

protected:
	cpBody *mBody;
	cpShape *mShapes[numShapes];
	cpBool mGrounded;
	cpFloat mBoostTime;
};
#endif //_PPlayer_h_
