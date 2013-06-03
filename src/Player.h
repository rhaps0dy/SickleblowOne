#ifndef _Player_h_
#define _Player_h_

#include "Interface.h"
#include <OgreMath.h>
#include <OgreVector2.h>
#include <OgreLogManager.h>

class Player
{
protected:
	Ogre::Real mX;
	Ogre::Real mY;
	char mirant; //1 dreta, 0 esquerra
	
	char animacioCorrent; //una d'un enum d'animacions, definit a les subclasses.
	char primerFrameAnim;
	Ogre::Real velAnim; //multiplicador de vel. d'animacio
	
	static const Ogre::Real maxHealth;
	Ogre::Real health;
	static const Ogre::Real maxUltCD;
	Ogre::Real ultCD;
	
	Interface *mInterface;
	
public:
	Player(Interface *iface);
	~Player(void);
	
	inline Ogre::Real getX(void) { return mX; }
	inline Ogre::Real getY(void) { return mY; }
	inline Ogre::Vector2 getPos(void) { return Ogre::Vector2(mX, mY); }
	
	virtual void setX(const Ogre::Real &x, bool rel=false);
	virtual void setY(const Ogre::Real &y, bool rel=false);
	virtual void setPos(const Ogre::Vector2 &pos, bool rel=false);
	
	virtual void update(Ogre::Real dt);
};

#endif //_Player_h_
