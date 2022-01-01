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

Menu MenuStateMachine::handleTopLevelMenu()
{

	vector<string> choiceString;
	choiceString.push_back("�鿴");
	choiceString.push_back("ʹ����Ʒ");
	choiceString.push_back("�ƶ�");
	int input = printChoiceList("����Ҫ��ʲô��", choiceString, true);

	switch (input) 
	{
	case 0:
		return MENU_INSPECT;
	case 1:
		return MENU_USEITEM;
	case 2:
		return MENU_MOVE;

	default:
		return MENU_TOP_LEVEL;
	}
}

Menu MenuStateMachine::handleMoveMenu()
{

	vector<Location>::size_type sz = gameData->locations.size();
	vector<string> locationString;
	for (int i = 0; i < sz; i++)
	{
		locationString.push_back(gameData->locations[i].name);
	}

	int itemNumberOfBack = printChoiceList("����Ҫ�ƶ��������أ�", locationString);

	if (itemNumberOfBack >= 0) 
	{
		interaction->moveTo(gameData->locations[itemNumberOfBack]);
	}
	return MENU_TOP_LEVEL;
}

Menu MenuStateMachine::handleInspectMenu()
{
	vector<Item>::size_type sz = gameData->items.size();
	vector<string> itemsString;
	vector<Item*> items;
	int playerLocation = gameData->player.locationID;
	for (unsigned i = 0; i < sz; i++)
	{
		if (playerLocation == gameData->items[i].locationID) {
			itemsString.push_back(gameData->items[i].name);
			items.push_back(&(gameData->items[i]));
		}
	}

	int itemIndex = printChoiceList("����Ҫ�鿴ʲô��", itemsString);
	if (itemIndex >= 0)
	{
		Item* item = items[itemIndex];
		printItemsMessage(*item);
		if (item->containsItem)
		{
			if (item->containedItems.size() > 0)
			{
				cout << endl << "���";
			}

			for (unsigned i = 0; i < item->containedItems.size(); i++)
			{
				cout << item->containedItems[i].name;
				if (i == item->containedItems.size() - 1)
				{
					cout << "��������" << endl;
				}
				else if (i == item->containedItems.size() - 2)
				{
					cout << "��";
				}
				else
				{
					cout << "��";
				}
			}

			interaction->moveContainedItemsToBackpack(*item);

		}

	}

	return MENU_TOP_LEVEL;
}

Menu MenuStateMachine::useToItem()
{
	vector<string> displayItemName;
	for (unsigned i = 0; i < gameData->player.backpack.size(); i++)
	{
		displayItemName.push_back(gameData->player.backpack[i].name);
	}
	
	int toolItemIndex = printChoiceList("����ʹ��ʲô��Ʒ��", displayItemName);
	if (toolItemIndex < 0)
	{
		return MENU_TOP_LEVEL; 
	}
	
	vector<string> itemsString;
	vector<Item> items;
	int playerLocation = gameData->player.locationID;
	for (unsigned i = 0; i < gameData->items.size(); i++)
	{
		if (playerLocation == gameData->items[i].locationID) {
			itemsString.push_back(gameData->items[i].name);
			items.push_back((gameData->items[i]));
		}
	}

	int targetItemIndex = printChoiceList("�����ʲô��Ʒʹ��" + displayItemName[toolItemIndex] + "��", itemsString);
	if (targetItemIndex < 0)
	{
		return MENU_TOP_LEVEL;
	}
	
	interaction->interactWithItem(gameData->player.backpack[toolItemIndex], items[targetItemIndex]);

	return MENU_TOP_LEVEL;
}

int MenuStateMachine::printChoiceList(string prompt, vector<string> choices, bool topLevel) {
	cout << endl;
	cout << prompt << endl;
	if (!topLevel) {
		cout << "0. ����" << endl;
	}

	for (unsigned i = 0; i < choices.size(); i++)
	{
		cout << i + 1 << ". " << choices[i] << endl;
	}
	cout << "��ѡ��";
	int input;
	cin >> input;
	//if (cin.fail())
	//{
	//	cout << "���������кţ�" << endl;
	//	cin.clear();
	//	
	//	return 0;
	//}
	return input - 1;
}

//int MenuStateMachine::isDigit(string str)
//{
//	string inputIsDigit;
//
//	for (unsigned i = 0; i < str.length(); i++)
//	{
//		if (!isdigit(str[i])) {
//			cout << "������ѡ������֣�" << endl;
//			cout << "��ѡ��";
//			cin >> inputIsDigit;
//			isDigit(inputIsDigit);
//		}
//		else {
//			return 0;
//		}
//	}
//}

void MenuStateMachine::printItemsMessage(Item items) {
	cout << items.message << endl;
}

void MenuStateMachine::Run() {

	while (keepRunning)
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
		case MENU_USEITEM:
			currentMenu = useToItem();
			break; 
		default:
			cout << "��δ�����½���";

		}
	}
}

