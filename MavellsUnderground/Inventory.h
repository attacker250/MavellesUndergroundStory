#pragma once
#include <vector>
#include <string>
#include "Consumables.h"

class Inventory
{
public:
	std::vector<std::string> storage;
	std::vector <Consumables*> consumableStorage;
	void addItem(std::string itemName);
	bool removeItem(std::string itemName);
	int coins = 0;
};

