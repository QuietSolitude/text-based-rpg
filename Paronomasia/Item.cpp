#include "Item.h"
#include <iostream>
using std::cout;
using std::endl;

Item::Item(string name, int id, int locationID)
{
	if (!name.empty() && id >= 0 && locationID >= 0 )
	{
		this->name = name;
		this->id = id;
		this->locationID = locationID;
	}
	else
	{
		this->name = "ACE";
		this->id = 18;
		cout << "����û�����ֻ�����Ʒid����С����" << endl;
	}
}