#ifndef _Level_h_
#define _Level_h_
class Player; //no volem referencies circulars!

class Level
{
public:
	Level(void);
	~Level(void);
	
	virtual void registerPlayer(Player *pl);
	virtual void unregisterPlayer(Player *pl);
};
#endif //_Level_h_
