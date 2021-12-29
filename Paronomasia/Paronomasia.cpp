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
    Bedroom bedroom = Bedroom();
    Player player = Player(bedroom.id);
    Washroom washroom = Washroom();

    GameData gameData = GameData(player);
    gameData.locations.push_back(bedroom);
    gameData.locations.push_back(washroom);

    Item mirror = Item("镜子", 3, washroom.id,"这是镜子", true);
    gameData.items.push_back(mirror);
    Item bed = Item("床", 1, washroom.id, "这是两张很普通的木制单人床，床垫软硬适中，相当舒服。你检查了床垫下面和床底，但是一无所获。", false);
    gameData.items.push_back(bed);
    Item quilt = Item("被子", 2, washroom.id, "每张床上放着一床被子。在你没有睡的那张床上，被子叠放得整整齐齐。这或许意味着你是唯一一个在这个房间里睡过觉得人。你仔细地检查了两张床上的被子，检查了被子的里面，但是一无所获。", false);
    gameData.items.push_back(quilt);
    Item pillow = Item("枕头", 4, washroom.id, "每张床上放着一个枕头。枕头太软了，一觉醒来之后，你的脖子感觉有些酸痛。你仔细检查了枕头下面，和枕头里面，但是一无所获。", false);
    gameData.items.push_back(pillow);
    Item nightTable = Item("床头柜", 5, washroom.id, "床头柜上面有两个抽屉。你拉开了第一个，里面空空如也，于是你拉开了第二个抽屉，第二个抽屉里除了积的灰尘比第一个抽屉厚以外，里面也是什么东西都没有。在你关上第二个抽屉的时候，突然觉得它好像刮擦到了什么东西。你身手进去，在第一个抽屉的底部发现了一张夹着的纸条，纸条上用潦草的笔迹画了一幅简笔画，那是一个像旗帜一样的东西，有旗杆、有飘扬的旗，还有一个箭头指向旗帜的旗杆。你把纸条小心地收了起来，一边心想，纸条上画的图案究竟是什么意思？究竟又是谁留下了这张纸条呢？", true);
    Item drawing = Item("图案纸", 6, washroom.id,"纸条上潦草地画着像是旗帜一样的东西，有旗杆，有飘扬的旗。有一个箭头指向旗帜的旗杆。",false);
    nightTable.containedItems.push_back(drawing);

    InteractionService interactionService = InteractionService(&gameData);
    MenuStateMachine menuStateMachine = MenuStateMachine(&interactionService, &gameData);

    cout << bedroom.introduction << endl; 
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
