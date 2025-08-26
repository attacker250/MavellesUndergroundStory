#pragma once
#include <vector>
#include <string>
#include "Consumables.h"
#include "Weapon.h"

class Inventory
{
public:
	std::vector<std::string> storage;
	std::vector <Consumables*> consumableStorage;
	std::vector<Weapon*> weaponStorage;
	void addItem(std::string itemName);
	void consumeItem(int itemIndex);
	bool removeItem(std::string itemName);
	int coins = 0;
};

