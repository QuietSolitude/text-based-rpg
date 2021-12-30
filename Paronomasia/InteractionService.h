#pragma once
#include "GameData.h"
#include "Place.h"
#include "Location.h"
#include <vector>

class InteractionService
{
private:
	GameData* gameData;
public:
	InteractionService(GameData* gameData);
	void MoveTo(Location location);
	void MoveContainedItemsToBackpack(Item& addItem); 
	
};

