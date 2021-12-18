#pragma once
#include<string>
using std::string;

class Item
{
protected:
	string name;
	int id;
	int locationID;

public:
	virtual void displayMessage() = 0;
	Item(string name, int id);
};

