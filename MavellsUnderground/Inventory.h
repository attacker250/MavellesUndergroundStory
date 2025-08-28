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
	static std::vector<Weapon*> weaponList;

	static void initWeaponList(std::vector<Weapon*> mainWeaponList);

	void addItem(std::string itemName);
	void addItem(int itemID);
	
	void consumeItem(int itemIndex, int& hp, int& dmgBuff);
	bool removeItem(std::string itemName);
	int getWeaponID(std::string weaponName);
	int getConsumableID(std::string name);
	void addWeapon(std::string weaponName);
	

	int coins = 0;
};

