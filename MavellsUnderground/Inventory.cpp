#include "Inventory.h"
#include <string>


void Inventory::addItem(std::string itemName){
	storage.push_back(itemName);
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