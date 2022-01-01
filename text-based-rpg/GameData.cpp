#include "GameData.h"

GameData::GameData(Player player) : 
	player(player), 
	locations(), 
	items(), 
	gameOver(false),
	playerHasMadeThePhoneCall(false), 
    playerHasInspectedTheCloset(false), 
	playerHasBrokenTheLight(false)
{
	
}

void GameData::removeItemById(int itemId)
{
	for (vector<Item>::iterator it = items.begin(); it != items.end(); ++it)
	{
		if (it->id == itemId)
		{
			items.erase(it);
			break;
		}
	}
}
