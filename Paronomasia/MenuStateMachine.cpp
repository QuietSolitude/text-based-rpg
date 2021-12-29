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
	choiceString.push_back("查看");
	choiceString.push_back("物品");
	choiceString.push_back("移动");
	int input = printChoiceList("你想要做什么？", choiceString, true);
	
	switch (input) {
	case 0:
		return MENU_INSPECT;
		break;
	case 1:
		cout << "待完成功能";
		break;
	case 2:
		return MENU_MOVE;
		break;

	default:
		cout << "请更具选项的顺序输入数字序列";
	}
}

Menu MenuStateMachine::handleMoveMenu() {

	vector<Location>::size_type sz = gameData->locations.size();
	vector<string> locationString;
	for (int i = 0; i < sz; i++)
	{
		locationString.push_back(gameData->locations[i].name);
	}
	
	int itemNumberOfBack = printChoiceList("你想要移动到哪里呢？",locationString);

	if (itemNumberOfBack >= 0){
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
	int itemIndex = printChoiceList("你想要查看什么？", itemsString);
	if (itemIndex >= 0)
	{
		printItemsMessage(items[itemIndex]);
		if (items[itemIndex].containsItem)
		{
			interaction->AddcontainsItem(items[itemIndex]);
		}
	}
	
	return MENU_TOP_LEVEL;
}

int MenuStateMachine::printChoiceList(string prompt, vector<string> choices, bool topLevel) {
	cout << endl;
	cout << prompt << endl;
	if (!topLevel) {
		cout << "0. 返回" << endl;
	}

	for (unsigned i = 0; i < choices.size(); i++)
	{
		cout << i + 1 << ". " << choices[i] << endl;
	}
	cout << "请选择：";
	int input;
	cin >> input;
	//if (cin.fail())
	//{
	//	cout << "请输入序列号：" << endl;
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
//			cout << "请输入选项的数字：" << endl;
//			cout << "请选择：";
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
			cout << "暂未开放新界面";

		}
	}
}

