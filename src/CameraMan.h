#ifndef _CameraMan_h_
#define _CameraMan_h_

#include <OgreSceneNode.h>
#include <OISMouse.h>

#ifndef SKBLCORE
	#if OGRE_PLATFORM == OGRE_PLATFORM_WIN32
		#ifdef BUILDING_SKBLCORE
			#define SKBLCORE __declspec(dllexport)
		#else
			#define SKBLCORE __declspec(dllimport)
		#endif
	#else
		#define SKBLCORE
	#endif
#endif

//Classe que controla la posicio de camara
class SKBLCORE CameraMan: public OIS::MouseListener
{
protected:
	Ogre::SceneNode *mPlayerNode;
	Ogre::SceneNode *mCamNode;
	Ogre::SceneNode *mCamDummy;
	OIS::Mouse *mMouse;
public:
	CameraMan(Ogre::SceneNode *pl, Ogre::SceneNode *cam, OIS::Mouse *mus);
	~CameraMan(void);
	void update(void);
	bool mouseMoved (const OIS::MouseEvent &arg);
	bool mousePressed (const OIS::MouseEvent &arg, OIS::MouseButtonID id);
	bool mouseReleased (const OIS::MouseEvent &arg, OIS::MouseButtonID id);
};
#endif // _CameraMan_h_
