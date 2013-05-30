#include "Player.h"

Player::Player(Interface *iface)
: mInterface(iface), mX(0.0f), mY(0.0f)
{
}

Player::~Player(void)
{
}

inline
void Player::setX(const Ogre::Real &x, bool rel)
{
	if(rel)
	{
		mX += x;
		return;
	}
	mX = x;
}

inline
void Player::setY(const Ogre::Real &y, bool rel)
{
	if(rel)
	{
		mY += y;
		return;
	}
	mY = y;
}

inline
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

void Player::update(Ogre::Real dt)
{
	mInterface->update();
	std::cerr << mInterface->getStatus() << std::endl;
}
