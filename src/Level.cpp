#include "Level.h"

Level::Level(void)
: mRegPlayers(0)
{
}

Level::~Level(void)
{
	mRegPlayers.clear();
}

inline
void Level::registerPlayer(Player *pl)
{
	mRegPlayers.push_back(pl);
}

void Level::unregisterPlayer(Player *pl)
{
	std::vector<Player*>::iterator i;
	for(i = mRegPlayers.begin(); i != mRegPlayers.end(); i++)
	{
		if((*i) == pl)
		{
			mRegPlayers.erase(i);
			break;
		}
	}
}

void Level::update(Ogre::Real dt)
{
	for(register int i = 0; i < mRegPlayers.size(); i++)
	{
		mRegPlayers[i]->update(dt);
	}
}
