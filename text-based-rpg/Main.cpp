#include <iostream>
#include "MenuStateMachine.h"
#include "InteractionService.h"
#include "GameData.h"
#include "Player.h"
#include "Location.h"

int main() 
{
    Location bedroom = Location(1, "卧室", "你一觉醒来，发现自己身处一个陌生的房间里。你努力回想，却忘了睡觉前发生了什么事情，忘记了怎么来到这个房间的。就连自己叫什么名字，谁是你的朋友都已经忘记了。你下了床，站在床边环顾四周。这里像是一个旅店。屋子里的东西很少很简洁，房间里就只有两张床、一个床头柜、一个衣柜，床头柜上面摆了一台有点老式的电话机，旁边还有一张有点破旧的木制椅子。房间的墙上没有窗户，天花板上有点老旧的日光灯照亮了整个房间。");
    Location washroom = Location(2, "浴室", "你进入了浴室。浴室并不大，但是空间也足够放得下一个洗手台、马桶和一个浴缸了。瓷砖的颜色是淡淡的褐色，头顶上是一盏白炽灯，用一根电线挂着，没有灯罩。它发出的光芒很昏暗，但至少颜色是暖色。你的心里不由地多了一丝暖意。");

    Item frontDoor = Item("大门", 101, bedroom.id, "穿过门廊，你来到了大门边。你尝试着打开门，但是门似乎被锁住了。你尝试敲门、大声喊叫、用力撞门但是都无济于事。很快你就明白，除非找到钥匙，否则你就会被困死在这个房间里。", false);
    Item doorOfTheWashroom = Item("浴室门", 102, bedroom.id, "大门旁边有一扇门，你推开门，这里是一间浴室。", false);
    Item bed = Item("床", 103, bedroom.id, "这是两张很普通的木制单人床，床垫软硬适中，相当舒服。你检查了床垫下面和床底，但是一无所获。", false);
    Item pillow = Item("枕头", 104, bedroom.id, "每张床上放着一个枕头。枕头太软了，一觉醒来之后，你的脖子感觉有些酸痛。你仔细检查了枕头下面，和枕头里面，但是一无所获。", false);
    Item quilt = Item("被子", 105, bedroom.id, "每张床上放着一床被子。在你没有睡的那张床上，被子叠放得整整齐齐。这或许意味着你是唯一一个在这个房间里睡过觉得人。你仔细地检查了两张床上的被子，检查了被子的里面，但是一无所获。", false);
    Item nightTable = Item("床头柜", 106, bedroom.id, "床头柜上面有两个抽屉。你拉开了第一个，里面空空如也，于是你拉开了第二个抽屉，第二个抽屉里除了积的灰尘比第一个抽屉厚以外，里面也是什么东西都没有。在你关上第二个抽屉的时候，突然觉得它好像刮擦到了什么东西。你身手进去，在第一个抽屉的底部发现了一张夹着的纸条，纸条上用潦草的笔迹画了一幅简笔画，那是一个像旗帜一样的东西，有旗杆、有飘扬的旗，还有一个箭头指向旗帜的旗杆。你把纸条小心地收了起来，一边心想，纸条上画的图案究竟是什么意思？究竟又是谁留下了这张纸条呢？", true);
    nightTable.containedItems.push_back(Item("画着图案的纸条", 301, 0, "", false));
    Item telephone = Item("电话机", 107, bedroom.id, "你拿起电话的话筒，话筒中传来持续的蜂鸣音。电话似乎可以正常使用，但是你一个电话号码都想不起来了。你尝试拨打110、119和120，但是都没办法接通。你试着乱拨了几个号码，没有一个号码能接通。", false);
    Item chair = Item("椅子", 108, bedroom.id, "木制的椅子有点老，椅子上有了一些发霉的痕迹。你仔细检查了椅子的各个部分，但是一无所获。", false);
    Item closet = Item("衣柜", 109, bedroom.id, "木制的衣柜里面的空间相当大，你整个人都可以站到里面去。里面有一套叠得整整齐齐的衣服裤子。你仔细地检查了衣柜里面的各个角落，检查了衣服裤子的口袋，但是都一无所获。不过一边检查，你一边意识到，你自己的身上除了内衣裤以外什么都没有穿。于是你把衣服和裤子穿在了自己身上，非常合身。", false);
    Item light = Item("日光灯管", 110, bedroom.id, "日光灯有点旧，你找不到它的开关在哪里。它发出的光线是惨白的颜色，还有些闪烁，让人看着非常不舒服。", false);

    Item doorToTheBedroom = Item("卧室门", 201, washroom.id, "卫生间里面唯一一扇门通往卧室，你刚刚就是从这扇门进到浴室里的。门并没有什么不一样的地方。你仔细检查了门，但是一无所获。", false);
    Item mirror = Item("镜子", 202, washroom.id, "要不是洗手间里面有一面镜子，你都忘记了你自己的长相。镜子中的人看起来是那么的陌生，你对着镜子招了招手，仿佛不相信镜子中的就是你一样。你的面容看起来相当憔悴，胡子拉茬，头发乱蓬蓬的。", false);
    Item washbasin = Item("洗手池", 203, washroom.id, "镜子的下面就是洗手池，你试探性地打开了水龙头，水龙头里马上流出了清澈的水。你这才意识到你的嘴唇一直很干燥。你舔了舔嘴唇，喝了几大口水，又用水洗了一把脸。现在你在镜子里的面容稍微精神了一些。", false);
    Item toilet = Item("马桶", 204, washroom.id, "洗手池的旁边就是马桶，没有什么特别的地方。马桶被刷得相当干净。你仔细检查了马桶，又打开了马桶的水箱，但是一无所获。", false);
    Item toiletPaper = Item("卫生纸", 205, washroom.id, "马桶旁的墙上有一卷卫生纸。卫生纸上没什么特别的。你把卫生纸全都从纸筒上抽了下来，妄图在卫生纸上找到什么线索，却一无所获。", false);
    Item bathtub = Item("浴缸", 206, washroom.id, "浴缸不小，整个人坐到浴缸里面都没有问题。浴缸里有一截金属管。你拿起它来仔细端详，它似乎就是一段普通的水管而已。不过这样的东西出现在这么干净的浴缸中让你觉得有些迷惑。你把金属管收好，又检查了浴缸的四周，并没有发现任何异样。", true);
    bathtub.containedItems.push_back(Item("金属管", 303, 0, "", false));
    Item showerHead = Item("淋浴喷头", 207, washroom.id, "浴缸的上面有一个淋浴喷头，你试着打开了水龙头，从这里也喷出了清澈的水流。水流暖暖的，非常舒服。", false);
    Item showerCurtain = Item("浴帘", 208, washroom.id, "浴帘从浴缸上面垂下来，长度刚刚好超过浴缸的上沿。想必它是用来防止淋浴喷头的水溅到浴缸外面去的。", false);
    Item showerCurtainRod = Item("挂浴帘的杆子", 209, washroom.id, "挂浴帘的杆子固定在天花板上，看上去没有什么特殊的地方。", false);


    Player player = Player(bedroom.id);

    GameData gameData = GameData(player);

    gameData.locations.push_back(bedroom);
    gameData.locations.push_back(washroom);

    gameData.items.push_back(frontDoor);
    gameData.items.push_back(doorOfTheWashroom);
    gameData.items.push_back(bed);
    gameData.items.push_back(pillow);
    gameData.items.push_back(quilt);
    gameData.items.push_back(nightTable);
    gameData.items.push_back(telephone);
    gameData.items.push_back(chair);
    gameData.items.push_back(closet);
    gameData.items.push_back(light);

    gameData.items.push_back(doorToTheBedroom);
    gameData.items.push_back(mirror);
    gameData.items.push_back(washbasin);
    gameData.items.push_back(toilet);
    gameData.items.push_back(toiletPaper);
    gameData.items.push_back(bathtub);
    gameData.items.push_back(showerHead);
    gameData.items.push_back(showerCurtain);
    gameData.items.push_back(showerCurtainRod);

    InteractionService interactionService = InteractionService(&gameData);
    MenuStateMachine menuStateMachine = MenuStateMachine(&interactionService, &gameData);

    cout << bedroom.introduction << endl; 
    menuStateMachine.Run();

    system("pause");
    return 0;
}