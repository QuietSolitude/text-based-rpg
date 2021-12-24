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

int InteractionService::PrintChoiceList(string prompt, vector<string> choices, bool topLevel){
	cout << endl;
	cout << prompt << endl;
	if (!topLevel) {
		cout << "0. ·µ»Ø" << endl; 
	}
	   
	for (unsigned i = 0; i < choices.size(); i++)
	{
		cout << i + 1 << ". " << choices[i] << endl;
	}
	cout << "ÇëÑ¡Ôñ£º";
	int input;
	cin >> input;
	return input - 1;
}

void InteractionService::PrintItemsMessage(Item items) {
	cout << items.message << endl;
}	