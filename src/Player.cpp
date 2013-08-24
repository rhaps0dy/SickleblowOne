#include "Player.h"

Player::Player(Interface *iface)
: mX(0.0f), mY(0.0f), mInterface(iface), mDirection(0), mCurAnim(0),
velAnim(1.0f), health(maxHealth), ultCD(0.0f)
{
    #ifndef NO_LOGS
	Ogre::LogManager::getSingletonPtr()->logMessage("Creant Player");
    #endif
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
    char movX = (mInterface->getJoyX() < -Interface::JOY_TH || mInterface->getJoyX() > Interface::JOY_TH);
    char movY = (mInterface->getJoyY() < -Interface::JOY_TH || mInterface->getJoyY() > Interface::JOY_TH); 

    mInterface->update();
    if(movX)
    {
	mCurAnim = 2;
	setX((Ogre::Real)mInterface->getJoyX()*RUN_SPEED*dt, true);	
	if(mDirection && mInterface->getJoyX() < -Interface::JOY_TH)
	    mDirection = 0;
	if(!mDirection && mInterface->getJoyX() > Interface::JOY_TH)
	    mDirection = 1;
    }
    else
    {
	mCurAnim = 0;
    }

    if(movY)
    {
	setY((Ogre::Real)mInterface->getJoyY()*RUN_SPEED*dt, true);
    }
}
