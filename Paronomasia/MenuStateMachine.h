#pragma once
#include "InteractionService.h"
#include "Place.h"
#include "GameData.h"
#include <locale>

enum Menu {
	MENU_TOP_LEVEL,
	MENU_MOVE,
	MENU_INSPECT
};

class MenuStateMachine
{
private:
	Menu currentMenu;
	bool keepRunning;
	InteractionService* interaction;
	GameData* gameData;
public:
	MenuStateMachine(InteractionService* interaction, GameData* gameData);
	Menu handleTopLevelMenu();
	Menu handleMoveMenu();
	Menu handleInspectMenu();
	int printChoiceList(string prompt, vector<string> choices, bool topLevel = false);
	void printItemsMessage(Item items);
	int isDigit(string str);

	void Run();
};

