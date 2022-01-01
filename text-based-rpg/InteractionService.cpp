#include "InteractionService.h"
#include <iostream>

using namespace std;

InteractionService::InteractionService(GameData* gameData) :
	gameData(gameData)
{
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
		cout << endl;
		cout << "��ͻȻ��ʶ����ԭ��ֽ���ϻ��ŵ�ͼ������ʲô���ģ�����ԡ���͹�ԡ���ĸ��ӡ������ż�ʻ��ϼ�ͷ��λ�ÿ�ȥ������ԭ����ԡ���ĸ�����ͷ�Ľ��������ǿ��Բ������ġ������˽��������ſ��ĵĸ������濴ȥ��������һ��ֽ��������д�˼�����ʽ��9 - 7 = 2; 9 - 79 = 20; 9 - 7938528314 = ? ������Щֽ��������˭���µ��أ��⼸����ʽ��ʲô����ĺ����𣿲��������������ȱ����ֽ��Ϊ���ֹͣ��˼������ֽ��С�����������������" << endl;
		Item noteWithNumbers = Item("д����ʽ��ֽ��", 302, 0, "", false);
		gameData->player.backpack.push_back(noteWithNumbers);
		cout << endl;
		cout << "���д����ʽ��ֽ����������" << endl;
	}
	else if (toolItem.id == 302 && targetItem.id == 107)
	{
		cout << endl;
		cout << "�㿴��ֽ������ֵ���ʽ�����˵9 - 7 = 2������9 - 79 = 20�Ļ�����ô9 - 7938528314���Ϳ��Եó�2061471685���������һ���绰����������̽�Ŵ���һ��20614����绰���룬��Ȼ��ͨ�ˡ��绰������һͷ�ǵ绰��¼��¼��¼����¼������һ�����˴�����е������صƣ���صƣ��չ�ƣ��������ţ�¼���ͽ����ˡ����صƣ��չ�ƣ������������������̧ͷ���˿��컨���Ϸ����Ұ׹��ߵ��չ�ƣ�Ȼ����ʶ���������ǽ�����ƵĿ��ض�û�С�" << endl;
		gameData->playerHasMadeThePhoneCall = true;
	}
	else if (toolItem.id == 303 && targetItem.id == 110 && gameData->playerHasMadeThePhoneCall)
	{
		cout << endl;
		cout << "�㿴�˿���񵽵��ǽؽ����ܣ���ʶ����ؽ����ܿ��ܾ�����õ��չ�ƿ����ˡ���ѵ��Ӱ��˹�����վ�������ϣ�һ�ֻ����۾���һ�����Ž������������չ�Ƶĵƹܡ�ɲ�Ǽ�ڰ��������������䡣�����ԡ����͸�����ĵƹ�ӵ������������������ܵĺڰ����е�ʧ�䡣��Ϊ�ƺ�ʲô���鶼û�з�����" << endl;

		gameData->removeItemById(targetItem.id);

		for (vector<Item>::iterator it = gameData->items.begin(); it != gameData->items.end(); ++it)
		{
			if (it->id == 109)
			{
				it->message = "����¹�������˺ڰ�ʲô��û�С�ͻȻ�����ƺ���ʶ����ʲô�����ߵ��¹�һ�ԡ��þ�ȫ����������¹��Ƶ���һ�ߡ�ͻȻ���㷢���¹�����ǽ����ӫ��Ϳ�ϻ���һ��ͼ����ͼ���ﻭ������һ��Ф�񻭣�����һ���ķ��Ŀ������ʲݵػ���һ�����ˡ���һ����ͷָ���Ǹ�Ф�񻭡�";
				break;
			}
		}
		gameData->playerHasBrokenTheLight = true;
	}
	else if (toolItem.id == 303 && targetItem.id == 202 && gameData->playerHasInspectedTheCloset)
	{
		cout << endl;
		cout << "���ߵ�����ǰ��������������Լ���ͻȻ����ʶ����ԭ���¹���滭���Ƿ������Ǿ����е����Լ����뵽����������˽����ܣ��������ž���������Լ���ȥ������Ӧ�����ѡ��㷢�־��Ӻ����ǽ��ȱ��һ���ש����û�д�ש���Ǹ�ȱ������ҵ���һ��Կ�ס�" << endl;
	    
		gameData->removeItemById(targetItem.id);
		Item key = Item("����Կ��", 304, 0, "", false);
		gameData->player.backpack.push_back(key);
	}
	else if (toolItem.id == 304 && targetItem.id == 101)
	{
		cout << endl;
		cout << "���Ȳ��������ͳ�Կ�ף��ò������ְ�Կ�ײ��������ڡ�һת���žͿ��ˡ�ӭ�������һ����ֱ�����ȣ����ܿ������ȵľ�ͷ��һ���ҹյ�ͨ���������ڵķ��������ĵ����˳����������ս����ǽؽ�������һ�����ء��������������Ⱦ�ͷ��ת�ǡ���" << endl;
		gameData->gameOver = true;
	}
	else
	{
		cout << endl;
		cout << "�����" << targetItem.name << "ʹ��" << toolItem.name << "������ʲô��û�з���" << endl;
	}
}

void InteractionService::afterInspectItem(Item& inspectItem)
{
	if (inspectItem.id == 109 && gameData->playerHasBrokenTheLight)
	{
		gameData->playerHasInspectedTheCloset = true;
	}
}