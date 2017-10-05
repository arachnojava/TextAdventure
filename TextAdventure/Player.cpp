#include "Player.h"


Player::Player()
{
	setHealth(100);
	setCurrentRoom(0);
}



void Player::setCurrentRoom(int r)
{
	currentRoom = r;
}


int Player::getCurrentRoom()
{
	return currentRoom;
}