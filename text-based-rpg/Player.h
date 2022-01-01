#pragma once
#include "Location.h"
#include "Item.h"
#include <vector>

class Player
{
public:
	int locationID;
	vector<Item> backpack;
	Player(int locationID);
};

