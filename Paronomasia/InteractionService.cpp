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
