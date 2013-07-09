#ifndef _PlayerRenderer_h_
#define _PlayerRenderer_h_

#if OGRE_PLATFORM == OGRE_PLATFORM_WIN32
	#ifdef BUILDING_SKBLCORE
		#define SKBLCORE __declspec(dllexport)
	#else
		#define SKBLCORE __declspec(dllimport)
	#endif
#else
	#define SKBLCORE
#endif

#include "Player.h"

#include <OgreRoot.h>
#include <OgreSceneManager.h>
#include <OgreRenderWindow.h>
#include <OgreCamera.h>
#include <OgreEntity.h>

class SKBLCORE PlayerRenderer
{
protected:
	static const char numAnims = 3;
	char mAnimPlaying;
	Ogre::String mAnimacions[numAnims];
	Ogre::AnimationState *mAnimState;
	char mPrevDirection;

	Player *mPlayer; //nivell que estem representant
	Ogre::SceneManager *mSceneMgr;
	Ogre::Entity *mPlayerEnt;
	Ogre::SceneNode *mPlayerNode;
	Ogre::SceneNode *mTerra;

public:
	PlayerRenderer(Player *pl, Ogre::SceneManager *mgr, Ogre::SceneNode *terra);
	virtual ~PlayerRenderer(void);
	virtual void update(Ogre::Real dt);

inline Ogre::SceneNode* getPlayerNode(void) { return mPlayerNode; }
};
#endif //_PlayerRenderer_h_
