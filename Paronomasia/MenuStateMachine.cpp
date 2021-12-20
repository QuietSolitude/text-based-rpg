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
	cout << "����Ҫ�ƶ��������أ�" << endl;

	for (unsigned i = 0; i < sz; i++)
	{
		cout << i + 1 << ". " << gameData->locations[i].name << endl;
	}
	int itemNumberOfBack = gameData->locations.size() + 1;
	cout << itemNumberOfBack << ". ����" << endl;
	cout << "��ѡ��";
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
	cout << "�����ڵص�������Ʒ��" << endl;
	int playerLocation = gameData->player.locationID;
	for (unsigned i = 0; i < sz; i++)
	{
		if (gameData->items[i].locationID == playerLocation)
		{
			cout << i + 1 << ". " << gameData->items[i].name << endl;
		}
	}
	int backMenu;
	cout << "������2����" << endl;
	cin >> backMenu;

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

