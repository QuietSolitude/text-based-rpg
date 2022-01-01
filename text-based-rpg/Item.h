#pragma once
#include<string>
#include<vector>
using std::string;
using std::vector;

class Item
{
//protected:
//	string name;
//	int id;
	

public:
	int locationID;
	//virtual void displayMessage()=0;
	string name;
	int id;
	string message;
	bool containsItem;
	vector<Item> containedItems;

	Item(string name, int id, int locationID, string message, bool containsItem);
};

