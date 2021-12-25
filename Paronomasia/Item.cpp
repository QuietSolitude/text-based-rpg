#include "Item.h"
#include <iostream>
using std::cout;
using std::endl;

Item::Item(string name, int id, int locationID, string message)
{
		this->name = name;
		this->id = id;
		this->locationID = locationID;
		this->message = message;
}
