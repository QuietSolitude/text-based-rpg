#pragma once
#include "GameData.h"
#include "Place.h"
#include "Location.h"

class InteractionService
{
private:
	GameData* gameData;
public:
	InteractionService(GameData* gameData);
	void MoveTo(Location location);
	
};

