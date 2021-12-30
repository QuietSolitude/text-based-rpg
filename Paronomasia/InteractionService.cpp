#include "InteractionService.h"
#include <iostream>
using namespace std;

InteractionService::InteractionService(GameData* gameData)
{
	this->gameData = gameData;
}

void InteractionService::MoveTo(Location location)
{
	gameData->player.locationID = location.id;
	cout << location.introduction << endl;

	vector<Item>::size_type sz = gameData->player.backpack.size();

}

void InteractionService::MoveContainedItemsToBackpack(Item& addItem)
{

	for (unsigned i = 0; i < addItem.containedItems.size(); i++)
	{
		gameData->player.backpack.push_back(addItem.containedItems[i]);
	}
	addItem.containedItems.clear();  
}