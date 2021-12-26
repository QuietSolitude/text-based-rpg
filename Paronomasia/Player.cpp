#include "Player.h"

Player::Player(int locationID)
{
	this->locationID = locationID;
	this->backpack = vector<Item>();
}