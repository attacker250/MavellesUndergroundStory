#include "Inventory.h"
#include "Game.h"

std::vector<Weapon*> Inventory::weaponList;

void Inventory::initWeaponList(std::vector<Weapon*> mainWeaponList)
{
	for (int i = 0; i < mainWeaponList.size(); i++) {
		weaponList.push_back(mainWeaponList[i]);
	}
}

void Inventory::addItem(std::string itemName){
	Consumables* consumable;
	consumable = new Consumables(Game::itemList[getConsumableID(itemName)].itemType, Game::itemList[getConsumableID(itemName)].itemID);
	consumableStorage.push_back(consumable);
}

void Inventory::addItem(int itemID) {
	Consumables* consumable;
	consumable = new Consumables(Game::itemList[itemID].itemType, Game::itemList[itemID].itemID);
	consumableStorage.push_back(consumable);
}

void Inventory::consumeItem(int itemID, int &hp, int &dmgBuff)
{
	if (consumableStorage[itemID]->itemType == "Healing") {
		hp += consumableStorage[itemID]->itemEffectiveness;
	}
	else if (consumableStorage[itemID]->itemType == "Buff") {
		dmgBuff += consumableStorage[itemID]->itemEffectiveness;
	}
	consumableStorage[itemID]->consume(1);
}

//checks if item is in storage. If its in storage remove it and return true. (CAN BE USED FOR TRADERS/KEYS)
bool Inventory::removeItem(std::string itemName){
	bool isIn = false;
	for (int i = 0; i < storage.size(); i++) {
		if (storage[i] == itemName){
			isIn = true;
			storage.erase(storage.begin() + i);
		}
	}
	return isIn;
}

int Inventory::getWeaponID(std::string weaponName)
{
	int weaponIndex = 0;
	for (int i = 0; i < weaponList.size(); i++) {
		if (weaponList[i]->name == weaponName) {
			weaponIndex = i;
		}
	}
	return weaponIndex;
}

void Inventory::addWeapon(std::string weaponName)
{
	weaponStorage.push_back(weaponList[getWeaponID(weaponName)]);
}


int Inventory::getConsumableID(std::string name)
{
	int consumableIndex = 0;

	for (int i = 0; i < Game::itemList.size(); i++) {
		Consumables consumable(Game::itemList[i].itemType, Game::itemList[i].itemID);
		if (consumable.name == name) {
			consumableIndex = i;
		}
	}
	return consumableIndex;
}


