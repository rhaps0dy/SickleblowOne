#include "Player.h"

Player::Player(Level *plvl, Interface *iface)
: mParentLevel(plvl), mInterface(iface), mX(0.0f), mY(0.0f)
{
	mParentLevel->registerPlayer(this);
}

Player::~Player(void)
{
	mParentLevel->unregisterPlayer(this);
}

void Player::setX(const Ogre::Real &x, bool rel)
{
	if(rel)
	{
		mX += x;
		return;
	}
	mX = x;
}

void Player::setY(const Ogre::Real &y, bool rel)
{
	if(rel)
	{
		mY += y;
		return;
	}
	mY = y;
}

void Player::setPos(const Ogre::Vector2 &pos, bool rel)
{
	if(rel)
	{
		mX += pos.x;
		mY += pos.y;
		return;
	}
	mX = pos.x;
	mY = pos.y;
}
