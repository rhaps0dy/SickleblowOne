#ifndef _Player_h_
#define _Player_h_

#include "Level.h"
#include "Interface.h"
#include <OgreMath.h>
#include <OgreVector2.h>

class Player
{
protected:
	Ogre::Real mX;
	Ogre::Real mY;
	Level *mParentLevel;
	Interface *mInterface;
	
public:
	Player(Level *plvl, Interface *iface); //crea el jugador i registra'l al nivell
	~Player(void);
	
	inline Ogre::Real getX(void) { return mX; }
	inline Ogre::Real getY(void) { return mY; }
	inline Ogre::Vector2 getPos(void) { return Ogre::Vector2(mX, mY); }
	
	virtual void setX(const Ogre::Real &x, bool rel=false);
	virtual void setY(const Ogre::Real &y, bool rel=false);
	virtual void setPos(const Ogre::Vector2 &pos, bool rel=false);
};

#endif //_Player_h_
