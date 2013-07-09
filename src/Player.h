#ifndef _Player_h_
#define _Player_h_

#if OGRE_PLATFORM == OGRE_PLATFORM_WIN32
	#ifdef BUILDING_SKBLCORE
		#define SKBLCORE __declspec(dllexport)
	#else
		#define SKBLCORE __declspec(dllimport)
	#endif
#else
	#define SKBLCORE
#endif

#include "Interface.h"
#include <OgreMath.h>
#include <OgreVector2.h>
#ifndef NO_LOGS
	#include <OgreLogManager.h>
#endif

class SKBLCORE Player
{
protected:
	Ogre::Real mX;
	Ogre::Real mY;
	char mDirection; //1 dreta, 0 esquerra
	
	int mCurAnim; //una d'un enum d'animacions, definit a les subclasses.
	Ogre::Real velAnim; //multiplicador de vel. d'animacio
	
	static constexpr Ogre::Real maxHealth=100.0;
	Ogre::Real health;
	static constexpr Ogre::Real maxUltCD=20.0;
	Ogre::Real ultCD;

	static constexpr Ogre::Real runSpeed = 2.0f/Interface::MAX_JOY;
	
	Interface *mInterface;
	
public:
	Player(Interface *iface);
	virtual ~Player(void);
	
	inline Ogre::Real getX(void) { return mX; }
	inline Ogre::Real getY(void) { return mY; }
	inline Ogre::Vector2 getPos(void) { return Ogre::Vector2(mX, mY); }
	inline char getCurAnim(void) { return mCurAnim; }
	inline char getDirection(void) { return mDirection; }
	
	virtual void setX(const Ogre::Real &x, bool rel=false);
	virtual void setY(const Ogre::Real &y, bool rel=false);
	virtual void setPos(const Ogre::Vector2 &pos, bool rel=false);
	
	virtual void update(Ogre::Real dt);
};

#endif //_Player_h_
