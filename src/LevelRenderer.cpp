#include "LevelRenderer.h"

LevelRenderer::LevelRenderer(Level *lv, Ogre::Root *root, Ogre::Camera *cam, Ogre::SceneManager *mgr) :
mLevel(lv), mRoot(root), mCamera(cam), mSceneMgr(mgr),
mLevelEnt(0), mLevelNode(0)
{
	mLevelEnt = mSceneMgr->createEntity("CProves", "Temple.mesh");
	mLevelNode = mSceneMgr->getRootSceneNode()->createChildSceneNode("CProvesNode", Ogre::Vector3(0.0f, 0.0f, 0.0f));
	mLevelNode->attachObject(mLevelEnt);
	mLevelNode->setScale(.1f, .1f, .1f);
	//mLevelNode->setDirection(-1.0f, 0.0f, 0.0f);

	mTerra =  mSceneMgr->getRootSceneNode()->createChildSceneNode("TerraNode", Ogre::Vector3(0.0f, 0.0f, 0.0f));
}

LevelRenderer::~LevelRenderer(void)
{
	mSceneMgr->destroyEntity(mLevelEnt);
	mSceneMgr->destroySceneNode(mLevelNode);
	mSceneMgr->destroySceneNode(mTerra);
	mLevelEnt = 0;
	mLevelNode = 0;
}

void LevelRenderer::update(void)
{
	;//no facis res :D
}
