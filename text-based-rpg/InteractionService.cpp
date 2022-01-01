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
		cout << "你突然意识到，原来纸条上画着的图案不是什么旗帜，而是浴帘和挂浴帘的杆子。你向着简笔画上箭头的位置看去，发现原来挂浴帘的杆子两头的金属球球是可以拆下来的。你拆掉了金属球，向着空心的杆子里面看去，发现了一张纸条，上面写了几个算式“9 - 7 = 2; 9 - 79 = 20; 9 - 7938528314 = ? ”。这些纸条到底是谁留下的呢？这几个算式有什么特殊的含义吗？不管怎样，还是先保存好纸条为妙。你停止了思绪，把纸条小心翼翼地收了起来。" << endl;
		Item noteWithNumbers = Item("写着算式的纸条", 302, 0, "", false);
		gameData->player.backpack.push_back(noteWithNumbers);
		cout << endl;
		cout << "你把写着算式的纸条收了起来" << endl;
	}
	else if (toolItem.id == 302 && targetItem.id == 107)
	{
		cout << endl;
		cout << "你看着纸条上奇怪的算式，如果说9 - 7 = 2，又有9 - 79 = 20的话，那么9 - 7938528314不就可以得出2061471685了吗？这会是一串电话号码吗？你试探着打了一下20614这个电话号码，果然接通了。电话的另外一头是电话答录机录的录音。录音里有一个男人大声吼叫道：“关灯！快关灯！日光灯！”紧接着，录音就结束了。“关灯？日光灯？”你自言自语道。你抬头看了看天花板上发出惨白光线的日光灯，然后意识到，这里的墙上连灯的开关都没有。" << endl;
		gameData->playerHasMadeThePhoneCall = true;
	}
	else if (toolItem.id == 303 && targetItem.id == 110 && gameData->playerHasMadeThePhoneCall)
	{
		cout << endl;
		cout << "你看了看你捡到的那截金属管，意识到这截金属管可能就是最好的日光灯开关了。你把凳子搬了过来，站到凳子上，一手护着眼睛，一手拿着金属管砸碎了日光灯的灯管。刹那间黑暗笼罩了整个房间。你借着浴室里透出来的灯光从凳子上下来，望着四周的黑暗，有点失落。因为似乎什么事情都没有发生。" << endl;

		gameData->removeItemById(targetItem.id);

		for (vector<Item>::iterator it = gameData->items.begin(); it != gameData->items.end(); ++it)
		{
			if (it->id == 109)
			{
				it->message = "你打开衣柜，里面除了黑暗什么都没有。突然，你似乎意识到了什么。你走到衣柜一旁。用尽全身的力量把衣柜推到了一边。突然，你发现衣柜后面的墙上用荧光涂料画了一幅图案。图案里画的像是一幅肖像画，它有一个四方的框，里面潦草地画着一个男人。有一个箭头指向那副肖像画。";
				break;
			}
		}
		gameData->playerHasBrokenTheLight = true;
	}
	else if (toolItem.id == 303 && targetItem.id == 202 && gameData->playerHasInspectedTheCloset)
	{
		cout << endl;
		cout << "你走到镜子前，望向镜子里的你自己。突然你意识到，原来衣柜后面画得那幅画就是镜子中的你自己。想到这里，你拿起了金属管，用力向着镜子里的你自己挥去，镜子应声破裂。你发现镜子后面的墙上缺了一块瓷砖，在没有瓷砖的那个缺口里，你找到了一把钥匙。" << endl;
	    
		gameData->removeItemById(targetItem.id);
		Item key = Item("大门钥匙", 304, 0, "", false);
		gameData->player.backpack.push_back(key);
	}
	else if (toolItem.id == 304 && targetItem.id == 101)
	{
		cout << endl;
		cout << "你迫不及待地掏出钥匙，用颤抖的手把钥匙插入锁孔内。一转，门就开了。迎接你的是一条笔直的走廊，你能看到走廊的尽头是一条右拐的通道。你从漆黑的房间中悄悄地走了出来，手里握紧了那截金属棒。一步步地、慢慢地走向走廊尽头的转角……" << endl;
		gameData->gameOver = true;
	}
	else
	{
		cout << endl;
		cout << "你对着" << targetItem.name << "使用" << toolItem.name << "，但是什么都没有发生" << endl;
	}
}

void InteractionService::afterInspectItem(Item& inspectItem)
{
	if (inspectItem.id == 109 && gameData->playerHasBrokenTheLight)
	{
		gameData->playerHasInspectedTheCloset = true;
	}
}