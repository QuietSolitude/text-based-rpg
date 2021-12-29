#include "InteractionService.h"
#include <iostream>
using namespace std;

InteractionService::InteractionService(GameData* gameData) {
	this->gameData = gameData;
}

void InteractionService::MoveTo(Location location) {
	gameData->player.locationID = location.id;
	cout << location.introduction << endl;
}

void InteractionService::AddcontainsItem(Item addItem) {
	vector<Item>::size_type sz = addItem.containedItems.size();
	for (unsigned i = 0; i < sz; i++)
	{
		gameData->player.backpack.push_back(addItem.containedItems[i]);
	}
	addItem.containedItems.clear();
}