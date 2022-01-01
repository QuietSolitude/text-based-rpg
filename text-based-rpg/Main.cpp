#include <iostream>
#include "MenuStateMachine.h"
#include "InteractionService.h"
#include "GameData.h"
#include "Player.h"
#include "Location.h"

int main() 
{
    Location bedroom = Location(1, "����", "��һ�������������Լ���һ��İ���ķ������Ŭ�����룬ȴ����˯��ǰ������ʲô���飬��������ô�����������ġ������Լ���ʲô���֣�˭��������Ѷ��Ѿ������ˡ������˴���վ�ڴ��߻������ܡ���������һ���õꡣ������Ķ������ٺܼ�࣬�������ֻ�����Ŵ���һ����ͷ��һ���¹񣬴�ͷ���������һ̨�е���ʽ�ĵ绰�����Ա߻���һ���е��ƾɵ�ľ�����ӡ������ǽ��û�д������컨�����е��Ͼɵ��չ���������������䡣");
    Location washroom = Location(2, "ԡ��", "�������ԡ�ҡ�ԡ�Ҳ����󣬵��ǿռ�Ҳ�㹻�ŵ���һ��ϴ��̨����Ͱ��һ��ԡ���ˡ���ש����ɫ�ǵ����ĺ�ɫ��ͷ������һյ�׳�ƣ���һ�����߹��ţ�û�е��֡��������Ĺ�â�ܻ谵����������ɫ��ůɫ��������ﲻ�ɵض���һ˿ů�⡣");

    Item frontDoor = Item("����", 101, bedroom.id, "�������ȣ��������˴��űߡ��㳢���Ŵ��ţ��������ƺ�����ס�ˡ��㳢�����š��������С�����ײ�ŵ��Ƕ��޼����¡��ܿ�������ף������ҵ�Կ�ף�������ͻᱻ��������������", false);
    Item doorOfTheWashroom = Item("ԡ����", 102, bedroom.id, "�����Ա���һ���ţ����ƿ��ţ�������һ��ԡ�ҡ�", false);
    Item bed = Item("��", 103, bedroom.id, "�������ź���ͨ��ľ�Ƶ��˴���������Ӳ���У��൱����������˴�������ʹ��ף�����һ������", false);
    Item pillow = Item("��ͷ", 104, bedroom.id, "ÿ�Ŵ��Ϸ���һ����ͷ����ͷ̫���ˣ�һ������֮����Ĳ��Ӹо���Щ��ʹ������ϸ�������ͷ���棬����ͷ���棬����һ������", false);
    Item quilt = Item("����", 105, bedroom.id, "ÿ�Ŵ��Ϸ���һ�����ӡ�����û��˯�����Ŵ��ϣ����ӵ��ŵ��������롣�������ζ������Ψһһ�������������˯�������ˡ�����ϸ�ؼ�������Ŵ��ϵı��ӣ�����˱��ӵ����棬����һ������", false);
    Item nightTable = Item("��ͷ��", 106, bedroom.id, "��ͷ���������������롣�������˵�һ��������տ���Ҳ�������������˵ڶ������룬�ڶ�����������˻��Ļҳ��ȵ�һ����������⣬����Ҳ��ʲô������û�С�������ϵڶ��������ʱ��ͻȻ����������β�����ʲô�����������ֽ�ȥ���ڵ�һ������ĵײ�������һ�ż��ŵ�ֽ����ֽ�������ʲݵıʼ�����һ����ʻ�������һ��������һ���Ķ���������ˡ���Ʈ����죬����һ����ͷָ�����ĵ���ˡ����ֽ��С�ĵ�����������һ�����룬ֽ���ϻ���ͼ��������ʲô��˼����������˭����������ֽ���أ�", true);
    nightTable.containedItems.push_back(Item("����ͼ����ֽ��", 301, 0, "", false));
    Item telephone = Item("�绰��", 107, bedroom.id, "������绰�Ļ�Ͳ����Ͳ�д��������ķ��������绰�ƺ���������ʹ�ã�������һ���绰���붼�벻�����ˡ��㳢�Բ���110��119��120�����Ƕ�û�취��ͨ���������Ҳ��˼������룬û��һ�������ܽ�ͨ��", false);
    Item chair = Item("����", 108, bedroom.id, "ľ�Ƶ������е��ϣ�����������һЩ��ù�ĺۼ�������ϸ��������ӵĸ������֣�����һ������", false);
    Item closet = Item("�¹�", 109, bedroom.id, "ľ�Ƶ��¹�����Ŀռ��൱���������˶�����վ������ȥ��������һ�׵�������������·����ӡ�����ϸ�ؼ�����¹�����ĸ������䣬������·����ӵĿڴ������Ƕ�һ�����񡣲���һ�߼�飬��һ����ʶ�������Լ������ϳ������¿�����ʲô��û�д�����������·��Ϳ��Ӵ������Լ����ϣ��ǳ�����", false);
    Item light = Item("�չ�ƹ�", 110, bedroom.id, "�չ���е�ɣ����Ҳ������Ŀ���������������Ĺ����ǲҰ׵���ɫ������Щ��˸�����˿��ŷǳ��������", false);

    Item doorToTheBedroom = Item("������", 201, washroom.id, "����������Ψһһ����ͨ�����ң���ով��Ǵ������Ž���ԡ����ġ��Ų�û��ʲô��һ���ĵط�������ϸ������ţ�����һ������", false);
    Item mirror = Item("����", 202, washroom.id, "Ҫ����ϴ�ּ�������һ�澵�ӣ��㶼���������Լ��ĳ��ࡣ�����е��˿���������ô��İ��������ž����������֣��·����ž����еľ�����һ����������ݿ������൱�㲣��������磬ͷ��������ġ�", false);
    Item washbasin = Item("ϴ�ֳ�", 203, washroom.id, "���ӵ��������ϴ�ֳأ�����̽�Եش���ˮ��ͷ��ˮ��ͷ�������������峺��ˮ���������ʶ������촽һֱ�ܸ�����������촽�����˼����ˮ������ˮϴ��һ�������������ھ������������΢������һЩ��", false);
    Item toilet = Item("��Ͱ", 204, washroom.id, "ϴ�ֳص��Ա߾�����Ͱ��û��ʲô�ر�ĵط�����Ͱ��ˢ���൱�ɾ�������ϸ�������Ͱ���ִ�����Ͱ��ˮ�䣬����һ������", false);
    Item toiletPaper = Item("����ֽ", 205, washroom.id, "��Ͱ�Ե�ǽ����һ������ֽ������ֽ��ûʲô�ر�ġ��������ֽȫ����ֽͲ�ϳ�����������ͼ������ֽ���ҵ�ʲô������ȴһ������", false);
    Item bathtub = Item("ԡ��", 206, washroom.id, "ԡ�ײ�С������������ԡ�����涼û�����⡣ԡ������һ�ؽ����ܡ�������������ϸ���꣬���ƺ�����һ����ͨ��ˮ�ܶ��ѡ����������Ķ�����������ô�ɾ���ԡ�������������Щ�Ի���ѽ������պã��ּ����ԡ�׵����ܣ���û�з����κ�������", true);
    bathtub.containedItems.push_back(Item("������", 303, 0, "", false));
    Item showerHead = Item("��ԡ��ͷ", 207, washroom.id, "ԡ�׵�������һ����ԡ��ͷ�������Ŵ���ˮ��ͷ��������Ҳ������峺��ˮ����ˮ��ůů�ģ��ǳ������", false);
    Item showerCurtain = Item("ԡ��", 208, washroom.id, "ԡ����ԡ�����洹���������ȸոպó���ԡ�׵����ء��������������ֹ��ԡ��ͷ��ˮ����ԡ������ȥ�ġ�", false);
    Item showerCurtainRod = Item("��ԡ���ĸ���", 209, washroom.id, "��ԡ���ĸ��ӹ̶����컨���ϣ�����ȥû��ʲô����ĵط���", false);


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