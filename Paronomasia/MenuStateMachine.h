#pragma once
#include "InteractionService.h"
#include "Place.h"
#include "GameData.h"
enum Menu {
	MENU_TOP_LEVEL,
	MENU_MOVE
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
	Menu displayItems();

	void Run();
};

