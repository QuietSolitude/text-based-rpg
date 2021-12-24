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

	vector<string> choiceString;
	choiceString.push_back("�鿴");
	choiceString.push_back("��Ʒ");
	choiceString.push_back("�ƶ�");
	int input = interaction->PrintChoiceList("����Ҫ��ʲô��", choiceString, true);

	switch (input) {
	case 0:
		return MENU_INSPECT;
		break;
	case 1:
		cout << "����ɹ���";
		break;
	case 2:
		return MENU_MOVE;

	default:
		cout << "��δ���Ÿ��๦�ܣ���������ʾѡ���ֵ";
	}
}

Menu MenuStateMachine::handleMoveMenu() {

	vector<Location>::size_type sz = gameData->locations.size();
	vector<string> locationString;
	for (int i = 0; i < sz; i++)
	{
		locationString.push_back(gameData->locations[i].name);
	}
	
	int itemNumberOfBack = interaction->PrintChoiceList("����Ҫ�ƶ��������أ�",locationString);
	if (itemNumberOfBack >= 0)
	{
		interaction->MoveTo(gameData->locations[itemNumberOfBack]);
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
	vector<Item> items;
	int playerLocation = gameData->player.locationID;
	for (unsigned i = 0; i < sz; i++)
	{
		if (playerLocation == gameData->items[i].locationID) {
			itemsString.push_back(gameData->items[i].name);
			items.push_back(gameData->items[i]);
		}
	}
	int itemIndex = interaction->PrintChoiceList("����Ҫ�鿴ʲô��", itemsString);
	if (itemIndex >= 0)
	{
		interaction->PrintItemsMessage(items[itemIndex]);
	}
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
			break;
		default:
			cout << "��δ�����½���";

		}
	}
}

