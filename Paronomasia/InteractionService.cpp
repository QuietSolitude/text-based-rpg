#include "InteractionService.h"
#include <iostream>

using namespace std;

InteractionService::InteractionService(GameData* gameData)
{
	this->gameData = gameData;
}

void InteractionService::moveTo(Location location)
{
	gameData->player.locationID = location.id;
	cout << location.introduction << endl;


}

void InteractionService::moveContainedItemsToBackpack(Item& addItem)
{

	for (unsigned i = 0; i < addItem.containedItems.size(); i++)
	{
		gameData->player.backpack.push_back(addItem.containedItems[i]);
	}
	addItem.containedItems.clear();  
}

void InteractionService::interactWithItem(Item toolItem, Item targetItem)
{
	if (toolItem.id == 301 && targetItem.id == 209)
	{
		cout << "你突然意识到，原来纸条上画着的图案不是什么旗帜，而是浴帘和挂浴帘的杆子。你向着简笔画上箭头的位置看去，发现原来挂浴帘的杆子两头的金属球球是可以拆下来的。你拆掉了金属球，向着空心的杆子里面看去，发现了一张纸条，上面写了几个算式“9 - 7 = 2; 9 - 79 = 20; 9 - 7938528314 = ? ”。这些纸条到底是谁留下的呢？这几个算式有什么特殊的含义吗？不管怎样，还是先保存好纸条为妙。你停止了思绪，把纸条小心翼翼地收了起来。" << endl;
		Item noteWithNumbers = Item("写着算式的纸条", 302, 0, "", false);
		gameData->player.backpack.push_back(noteWithNumbers);
		cout << endl;
		cout << "你把写着算式的纸条收了起来" << endl;
	}
	
}