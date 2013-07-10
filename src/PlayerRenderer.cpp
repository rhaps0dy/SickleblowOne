	#include "PlayerRenderer.h"

PlayerRenderer::PlayerRenderer(Player *pl, Ogre::SceneManager *mgr, Ogre::SceneNode *terra) :
mAnimPlaying(0), mAnimState(0), mPlayer(pl), mPrevDirection(0), 
mSceneMgr(mgr), mPlayerEnt(0), mPlayerNode(0), mTerra(terra)
{
	mAnimacions[0] = "parat_actiu";
	mAnimacions[1] = "parat_tranquil";
	mAnimacions[2] = "corrent";
	mPlayerEnt = mSceneMgr->createEntity("Boxejador", "Boxejador.mesh");
	mPlayerNode = mTerra->createChildSceneNode("Boxejador", Ogre::Vector3(0.0f, 0.0f, 0.0f));
	mPlayerNode->attachObject(mPlayerEnt);
	mPlayerNode->setDirection(0.0f, 0.0f, 1.0f);
	mPlayerNode->setScale(.15f, .15f, .15f);

	//inicialitzem totes les animacions a loop
	for(char i=0; i<numAnims; i++)
	{
		mAnimState = mPlayerEnt->getAnimationState(mAnimacions[mAnimPlaying]);
		mAnimState->setLoop(true);
	}

	//assegurem-nos que mAnimPlaying != mPlayer->getCurAnim()
	mAnimPlaying = mPlayer->getCurAnim() + 1;
	update(0.0f);
}

PlayerRenderer::~PlayerRenderer(void)
{
	mSceneMgr->destroyEntity(mPlayerEnt);
	mSceneMgr->destroySceneNode(mPlayerNode);
}

void PlayerRenderer::update(Ogre::Real dt)
{
	//posicio i orientacio
	mPlayerNode->setPosition(mPlayer->getX(), mPlayer->getY(), 0.0f);

	//a implementar canvis suaus de direccio
	if(!mPrevDirection && mPlayer->getDirection())
	{
		mPlayerNode->setDirection(-1.0f, 0.0f, 0.0f, Ogre::SceneNode::TS_WORLD);
	}
	else if (mPrevDirection && !mPlayer->getDirection()) 
	{
		mPlayerNode->setDirection(1.0f, 0.0f, 0.0f, Ogre::SceneNode::TS_WORLD);
	}

	std::cerr << mAnimPlaying << std::endl;
	//animacions
	if(mAnimPlaying != mPlayer->getCurAnim())
	{
		mAnimState->setEnabled(false);
		mAnimPlaying = mPlayer->getCurAnim();
		mAnimState = mPlayerEnt->getAnimationState(mAnimacions[mAnimPlaying]);
		mAnimState->setEnabled(true);
	}
	mAnimState->addTime(dt);
	mPrevDirection = mPlayer->getDirection();
}
