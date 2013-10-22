#include "PDebugger.h"

PDebugger::PDebugger(Ogre::SceneManager *mgr, PLevel *lv, PPlayer *pl) :
mNode(NULL), mLevel(lv), mPlayer(pl)
{
	mMObject = new Ogre::ManualObject("PLevelDebug");
	Ogre::MaterialPtr mat = Ogre::MaterialManager::getSingleton().create("matDebug","Grup_prova");
	mat->setReceiveShadows(false);
	mat->getTechnique(0)->setLightingEnabled(true);
	mat->getTechnique(0)->getPass(0)->setDiffuse(0,1,0,0);
	mat->getTechnique(0)->getPass(0)->setAmbient(0,1,0);
	mat->getTechnique(0)->getPass(0)->setSelfIllumination(0,1,0);
	mMObject->begin("matDebug", Ogre::RenderOperation::OT_LINE_LIST); 
	//comencem indexacio
	cpShape *shape;
	cpSegmentShape *s;
	cpVect v;
	const Ogre::Real zeta = -7.0f;
	for(int i=0;;i++)
	{
		shape = mLevel->getSegment(i);
		if(shape==NULL) break; //ja hem acabat
		v = cpSegmentShapeGetA(shape);
		mMObject->position(v.x, v.y, zeta);
		std::cerr << v.x << "  " << v.y << std::endl;
		v = cpSegmentShapeGetB(shape);
		mMObject->position(v.x, v.y, zeta);
		std::cerr << v.x << "  " << v.y << std::endl;
	}
		
	mMObject->end();
	mNode = mgr->getRootSceneNode()->createChildSceneNode("PLevelDebugNode");
	mNode->attachObject(mMObject);
}

PDebugger::~PDebugger(void)
{
	delete mMObject;
	delete mNode;
}

void PDebugger::update(Ogre::Real dt)
{
	;
}
