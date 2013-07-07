#include "CameraMan.h"

CameraMan::CameraMan(Ogre::SceneNode *pl, Ogre::SceneNode *cam) :
mPlayerNode(pl), mCamNode(cam)
{
}

CameraMan::~CameraMan(void)
{
}

void CameraMan::update(void)
{
	Ogre::Vector3 pos(mPlayerNode->getPosition());
	pos.z = mCamNode->getPosition().z;
	pos.y += 2.0f;
	mCamNode->setPosition(pos);
}
