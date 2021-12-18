#include "Item.h"
#include <iostream>
using std::cout;
using std::endl;

Item::Item(string name, int id, int locationID)
{
		this->name = name;
		this->id = id;
		this->locationID = locationID;

}