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
		cout << "��ͻȻ��ʶ����ԭ��ֽ���ϻ��ŵ�ͼ������ʲô���ģ�����ԡ���͹�ԡ���ĸ��ӡ������ż�ʻ��ϼ�ͷ��λ�ÿ�ȥ������ԭ����ԡ���ĸ�����ͷ�Ľ��������ǿ��Բ������ġ������˽��������ſ��ĵĸ������濴ȥ��������һ��ֽ��������д�˼�����ʽ��9 - 7 = 2; 9 - 79 = 20; 9 - 7938528314 = ? ������Щֽ��������˭���µ��أ��⼸����ʽ��ʲô����ĺ����𣿲��������������ȱ����ֽ��Ϊ���ֹͣ��˼������ֽ��С�����������������" << endl;
		Item noteWithNumbers = Item("д����ʽ��ֽ��", 302, 0, "", false);
		gameData->player.backpack.push_back(noteWithNumbers);
		cout << endl;
		cout << "���д����ʽ��ֽ����������" << endl;
	}
	
}