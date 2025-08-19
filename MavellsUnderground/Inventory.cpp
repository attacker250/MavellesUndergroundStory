#include "Inventory.h"
#include <string>

void Inventory::addItem(std::string itemName){
	storage.push_back(itemName);
}

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