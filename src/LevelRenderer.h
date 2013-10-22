#ifndef _LevelRenderer_h_
#define _LevelRenderer_h_

#include "Level.h"

#include <OgreRoot.h>
#include <OgreSceneManager.h>
#include <OgreRenderWindow.h>
#include <OgreCamera.h>
#include <OgreEntity.h>

#include <chipmunk.h>

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

//Classe que dibuixa en la pantalla un nivell
class SKBLCORE LevelRenderer
{
	protected:
		Level *mLevel; //nivell que estem representant
		Ogre::Root *mRoot;
		Ogre::Camera *mCamera;
		Ogre::SceneManager *mSceneMgr;
		Ogre::Entity *mLevelEnt;
		Ogre::SceneNode *mLevelNode;

	Ogre::SceneNode *mTerra;
	public:
		LevelRenderer(Level *lv, Ogre::Root *root, Ogre::Camera *cam, Ogre::SceneManager *mgr);
		virtual ~LevelRenderer(void);
		virtual void update(void);
};

#endif //_LevelRenderer_h_
