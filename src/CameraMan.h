#ifndef _CameraMan_h_
#define _CameraMan_h_

#if OGRE_PLATFORM == OGRE_PLATFORM_WIN32
	#ifdef BUILDING_SKBLCORE
		#define SKBLCORE __declspec(dllexport)
	#else
		#define SKBLCORE __declspec(dllimport)
	#endif
#else
	#define SKBLCORE
#endif

#include <OgreSceneNode.h>

//Classe que controla la posicio de camara
class SKBLCORE CameraMan
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
