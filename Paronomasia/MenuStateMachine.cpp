#include "MenuStateMachine.h"
#include <iostream>
using std::cout;
using std::cin;
using std::endl;

MenuStateMachine::MenuStateMachine(InteractionService* interaction, GameData* gameData)
{
	this->interaction = interaction;
	this->currentMenu = MENU_TOP_LEVEL;
	this->keepRunning = true;
	this->gameData = gameData;
	
}

Menu MenuStateMachine::handleTopLevelMenu() {
	int input;
	cout << "你想要做什么？" << endl;

	cout << "1. 查看" <<endl <<  "2. 物品" << endl << "3. 移动" << endl;
	cout << "请选择：";
	cin >> input;

	switch (input) {
	case 1:
		return MENU_INSPECT;
		break;
	case 2:
		cout << "待完成功能";
		break;
	case 3:
		return MENU_MOVE;

	default:
		cout << "暂未开放更多功能，请输入提示选项的值";
	}
}

Menu MenuStateMachine::handleMoveMenu() {

	vector<Location>::size_type sz = gameData->locations.size();
	vector<string> locationString;
	for (int i = 0; i < sz; i++)
	{
		locationString.push_back(gameData->locations[i].name);
	}
	
	int itemNumberOfBack = interaction->PrintChoiceList("你想要移动到哪里呢？",locationString);
	int input;
	cin >> input;
	if (input != itemNumberOfBack)
	{
		interaction->MoveTo(gameData->locations[input - 1]);
	}
	
	return MENU_TOP_LEVEL;
}

//Menu MenuStateMachine::displayItems()
//{
//	vector<Item>::size_type sz = gameData->items.size();
//}

Menu MenuStateMachine::handleInspectMenu()
{
	vector<Item>::size_type sz = gameData->items.size();
	vector<string> itemsString ;
	int playerLocation = gameData->player.locationID;
	int index = 1;
	for (unsigned i = 0; i < sz; i++)
	{
		itemsString.push_back(gameData->items[i].name);
	}
	int itemNumberOfBack = interaction->PrintChoiceList("你所在地的所有物品：", itemsString);
	int input;
	cin >> input;

	return MENU_TOP_LEVEL;
}

void MenuStateMachine::Run() {

	while(keepRunning)
	{
		switch (currentMenu)
		{
		case MENU_TOP_LEVEL:
			currentMenu = handleTopLevelMenu();
			break;

		case MENU_MOVE:
			currentMenu = handleMoveMenu();
			break;
		case MENU_INSPECT:
			currentMenu = handleInspectMenu();
		default:
			cout << "暂未开放新界面";

		}
	}
}

