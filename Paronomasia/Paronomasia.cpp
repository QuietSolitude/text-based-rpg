// Paronomasia.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "MenuStateMachine.h"
#include "InteractionService.h"
#include "GameData.h"
#include "Place.h"
#include "Player.h"
#include "Location.h"
#include "Bedroom.h"
#include "Washroom.h"
#include "Bed.h"
#include "Pillow.h"


int main()
{
    std::cout << "Hello World!\n";
    Bedroom bedroom = Bedroom();
    Player player = Player(bedroom.id);
    Washroom washroom = Washroom();
    GameData gameData = GameData(player);
    gameData.locations.push_back(bedroom);
    gameData.locations.push_back(washroom);
    Bed bed = Bed();
    Pillow pillow = Pillow();
    gameData.items.push_back(bed);
    gameData.items.push_back(pillow);
    InteractionService interactionService = InteractionService(&gameData);
    MenuStateMachine menuStateMachine = MenuStateMachine(&interactionService, &gameData);
    menuStateMachine.Run();


    return 0;


}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
