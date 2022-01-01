#pragma once
#include "GameData.h"
#include "Location.h"
#include <vector>
#include "Item.h"

class InteractionService
{
private:
	GameData* gameData;
public:
	InteractionService(GameData* gameData);
	void moveTo(Location location);
	void moveContainedItemsToBackpack(Item& addItem); 
	void interactWithItem(Item toolItem, Item targetItem); 
};

