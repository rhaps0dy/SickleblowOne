#include "CameraMan.h"

CameraMan::CameraMan(Ogre::SceneNode *pl, Ogre::SceneNode *cam, OIS::Mouse *mus) :
mPlayerNode(pl), mCamNode(cam), mMouse(mus)
{
	mCamDummy = pl->createChildSceneNode("CameraControl");
	mCamDummy->setInheritScale(false);
	mCamDummy->setInheritOrientation(false);
	mCamDummy->addChild(mCamNode);
	mCamNode->setPosition(mCamNode->getPosition()+Ogre::Vector3(0, 0, 1000));
}

CameraMan::~CameraMan(void)
{
}

void CameraMan::update(void)
{;
/*	Ogre::Vector3 pos(mPlayerNode->getPosition());
	pos.z = mCamNode->getPosition().z;
	pos.y += 0.0f;
	mCamNode->setPosition(pos);*/
}
bool CameraMan::mouseMoved (const OIS::MouseEvent &arg)
{
	return true;
}
bool CameraMan::mousePressed (const OIS::MouseEvent &arg, OIS::MouseButtonID id)
{
	return true;
}
bool CameraMan::mouseReleased (const OIS::MouseEvent &arg, OIS::MouseButtonID id)
{
	return true;
}
