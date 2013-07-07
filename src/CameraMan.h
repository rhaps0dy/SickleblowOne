#ifndef _CameraMan_h_
#define _CameraMan_h_

#include <OgreSceneNode.h>

//Classe que controla la posicio de camara
class CameraMan
{
protected:
	Ogre::SceneNode *mPlayerNode;
	Ogre::SceneNode *mCamNode;
public:
	CameraMan(Ogre::SceneNode *pl, Ogre::SceneNode *cam);
	~CameraMan(void);
	void update(void);
};
#endif // _CameraMan_h_
