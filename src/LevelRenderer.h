#ifndef _LevelRenderer_h_
#define _LevelRenderer_h_

#include "Level.h"

#include <OgreRoot.h>
#include <OgreSceneManager.h>
#include <OgreRenderWindow.h>
#include <OgreCamera.h>
#include <OgreEntity.h>

//Classe que dibuixa en la pantalla un nivell
class LevelRenderer
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

	inline Ogre::SceneNode* getTerra(void) { return mTerra; }
};

#endif //_LevelRenderer_h_
