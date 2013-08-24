#include "PPlayer.h"
PPlayer::PPlayer(Interface *iface) :
mBody(0), mGrounded(cpFalse), Player(iface)
{
	#ifndef NO_LOGS
		Ogre::LogManager::getSingletonPtr()->logMessage("Creant PPlayer");
	#endif
	mBody = cpBodyNew(mass, INFINITY);
	mBody->velocity_func = bodyUpdateVelocity;
	mBody->data = (cpDataPointer) this; // poder accedir al jugador des del cos
	mShapes[0] = cpCircleShapeNew(mBody, 25., cpvzero);
	mShapes[0]->e = 0.0f;
	mShapes[0]->u = 10.0f;
	mShapes[0]->collision_type = 1;
	cpBodySetPos(mBody, cpv(500, 100));
	update(0.0f);
} 

PPlayer::~PPlayer(void)
{
	for(int i=0; i<numShapes; i++)
	{
		cpShapeFree(mShapes[i]);
	}
	cpBodyFree(mBody);
}

static 
void SelectPlayerGroundNormal(cpBody *body, cpArbiter *arb, cpVect *groundNormal)
{
	cpVect n = cpvneg(cpArbiterGetNormal(arb, 0));

	if(n.y > groundNormal->y)
	{
		(*groundNormal) = n;
	}
}

void PPlayer::bodyUpdateVelocity(cpBody *body, cpVect gravity, cpFloat damping, cpFloat dt)
{
	PPlayer *jugador = (PPlayer *)body->data;
	if(!(jugador->mInterface->getActualCtlStatus() & Interface::SALT))
		jugador->mBoostTime = 0;
	else
		jugador->mBoostTime -= dt;
	//update normal, amb gravetat 0 si s'esta saltant
	cpBodyUpdateVelocity(body, (jugador->mBoostTime > 0 ? 
			cpvzero : gravity), damping, dt);	

	//determinem si esta tocant el terra
	cpVect groundNormal = cpvzero;
	cpBodyEachArbiter(body, 
		(cpBodyArbiterIteratorFunc)SelectPlayerGroundNormal,
		&groundNormal);
	jugador->mGrounded = groundNormal.y > 0;
	
	
	//actualitzem la velocitat de la superficie
	register int i;
	for(i=0; i<PPlayer::numShapes; i++)
	{
		jugador->getShape(i)->surface_v.x = RUN_SPEED_UNCORRECTED*jugador->mInterface->getJoyX();
	}
	if(!jugador->mGrounded) body->v.x = cpflerpconst(body->v.x, 
		RUN_SPEED_UNCORRECTED*jugador->mInterface->getJoyX(), RUN_ACCEL*dt);

	body->v.y = cpfclamp(body->v.y, -INFINITY, JUMP_SPEED);
}

void PPlayer::update(Ogre::Real dt)
{
	mInterface->update();
	if(mGrounded &&
		(mInterface->getActualCtlStatus() & mInterface->SALT) && 
		!(mInterface->getPrevCtlStatus() & mInterface->SALT)) 
	{
		mBody->v.y = JUMP_SPEED;
		mBoostTime = JUMP_BOOST_TIME;
	}

	if(!mGrounded)
		mCurAnim = 1;
	else if(mInterface->getJoyX() != 0)
	{
		mCurAnim = 2;
		if(mDirection && mInterface->getJoyX() < -Interface::JOY_TH)
	    		mDirection = 0;
		if(!mDirection && mInterface->getJoyX() > Interface::JOY_TH)
			mDirection = 1;
	}
	else
		mCurAnim = 0;

	mX = mBody->p.x / 100.;
	mY = mBody->p.y / 100.;
}
