#pragma once
#include <vector>
#include <string>

class Inventory
{
public:
	std::vector<std::string> storage;
	void addItem(std::string itemName);
	bool removeItem(std::string itemName);
	int coins = 0;
};

