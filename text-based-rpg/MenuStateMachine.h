#pragma once
#include "InteractionService.h"
#include "GameData.h"

enum Menu {
	MENU_TOP_LEVEL,
	MENU_MOVE,
	MENU_INSPECT,
	MENU_USEITEM
};

class MenuStateMachine
{
private:
	Menu currentMenu;
	InteractionService* interaction;
	GameData* gameData;
public:
	MenuStateMachine(InteractionService* interaction, GameData* gameData);
	Menu handleTopLevelMenu();
	Menu handleMoveMenu();
	Menu handleInspectMenu();
	Menu useToItem();
	int printChoiceList(string prompt, vector<string> choices, bool topLevel = false);
	void printItemsMessage(Item items);

	void Run();
};