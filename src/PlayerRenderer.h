#ifndef _PlayerRenderer_h_
#define _PlayerRenderer_h_

#include "Player.h"

#include <OgreRoot.h>
#include <OgreSceneManager.h>
#include <OgreRenderWindow.h>
#include <OgreCamera.h>
#include <OgreEntity.h>

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

class SKBLCORE PlayerRenderer
{
protected:
	char mAnimPlaying;
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

	static const char numAnims = 3;
	Ogre::String mAnimacions[numAnims];

inline Ogre::SceneNode* getPlayerNode(void) { return mPlayerNode; }
};
#endif //_PlayerRenderer_h_
