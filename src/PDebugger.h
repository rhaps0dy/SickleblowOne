#ifndef _PDebugger_h_
#define _PDebugger_h_

#include "GameSetup.h"
#include <OgreManualObject.h>
#include <OgreMaterialManager.h>

#include <chipmunk.h>

class PDebugger
{
protected:
	Ogre::SceneNode *mNode;
	PLevel *mLevel;
	PPlayer *mPlayer;
	Ogre::ManualObject *mMObject;
public:
	PDebugger(Ogre::SceneManager *mgr, PLevel *lv, PPlayer *pl);
	virtual ~PDebugger(void);

	void update(Ogre::Real dt);
};

#endif //_PDebugger_h_
