#pragma once
#include "Player.h"
#include <vector>
#include "Location.h"
#include "Item.h"

using namespace std;

class GameData
{
public:
	Player player;
	vector <Location> locations;
	vector<Item> items;

	GameData(Player player);
	
};

