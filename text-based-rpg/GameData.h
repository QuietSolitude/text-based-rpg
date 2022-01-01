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
	bool gameOver;
	bool playerHasMadeThePhoneCall;
	bool playerHasInspectedTheCloset;
	bool playerHasBrokenTheLight;

	GameData(Player player);

	void removeItemById(int itemId);
	
};

