#include "Inventory.h"


std::vector<Weapon*> Inventory::weaponList;

void Inventory::initWeaponList(std::vector<Weapon*> mainWeaponList)
{
	for (int i = 0; i < mainWeaponList.size(); i++) {
		weaponList.push_back(mainWeaponList[i]);
	}
}

void Inventory::addItem(std::string itemName){
	storage.push_back(itemName);
}

void Inventory::consumeItem(int itemID)
{
	//if (consumableStorage[itemID]->itemType == "Healing") {
	//	Player::hp += consumableStorage[itemID]->itemEffectiveness;
	//}
	//else if (consumableStorage[itemID]->itemType == "Buff") {
	//	Player::dmgModifier += consumableStorage[itemID]->itemEffectiveness;
	//}
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
