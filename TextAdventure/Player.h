#include "GameActor.h"

class Player : public GameActor
{
public:

	Player();
	void setCurrentRoom(int r);
	int getCurrentRoom();

private:

	int currentRoom;


};