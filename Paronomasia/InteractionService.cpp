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

int InteractionService::PrintChoiceList(string prompt, vector<string> choices)
{
	cout << prompt << endl;
	for (unsigned i = 0; i < choices.size(); i++)
	{
		cout << i + 1 << ". " << choices[i] << endl;
	}
	int itemNumberOfBack = choices.size() + 1;
	cout << itemNumberOfBack << ". ·µ»Ø" << endl;
	cout << "ÇëÑ¡Ôñ£º";
	
	return itemNumberOfBack;
}