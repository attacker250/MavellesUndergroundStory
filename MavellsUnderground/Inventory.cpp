#include "Inventory.h"
#include "Player.h"


void Inventory::addItem(std::string itemName){
	storage.push_back(itemName);
}

void Inventory::consumeItem(int itemID)
{
	if (consumableStorage[itemID]->itemType == "Healing") {
		Player::hp += consumableStorage[itemID]->itemEffectiveness;
	}
	else if (consumableStorage[itemID]->itemType == "Buff") {
		Player::dmgModifier += consumableStorage[itemID]->itemEffectiveness;
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