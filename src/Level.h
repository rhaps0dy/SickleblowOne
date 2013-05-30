#ifndef _Level_h_
#define _Level_h_
#include <OgreMath.h>
#include <vector>

#include "Player.h"

class Level
{
protected:
	std::vector<Player*> mRegPlayers; //llista de jugadors a actualitzar
	
public:
	Level(void);
	~Level(void);
	
	virtual void registerPlayer(Player *pl);
	virtual void unregisterPlayer(Player *pl);
	
	virtual void update(Ogre::Real dt);
};
#endif //_Level_h_
