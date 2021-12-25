#pragma once
#include<string>
using std::string;

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
	Item(string name, int id, int locationID, string message);
};

