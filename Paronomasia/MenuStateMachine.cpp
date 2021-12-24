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
	cout << "����Ҫ��ʲô��" << endl;

	cout << "1. �鿴" <<endl <<  "2. ��Ʒ" << endl << "3. �ƶ�" << endl;
	cout << "��ѡ��";
	cin >> input;

	switch (input) {
	case 1:
		return MENU_INSPECT;
		break;
	case 2:
		cout << "����ɹ���";
		break;
	case 3:
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
	int itemNumberOfBack = interaction->PrintChoiceList("�����ڵص�������Ʒ��", itemsString);
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
			cout << "��δ�����½���";

		}
	}
}

