#include "Barrel.h"
#include "Player.h"
#include <iostream>
#include "Cutscenes.h"

Barrel::Barrel() {
	icon = 'B';
}


void Barrel::interact() {
	//for (int i = 0 ; i < barrelinventory.storage.size(); i++) {
	//	Player::playerInventory.storage.push_back(barrelinventory.storage[i]);
	//}
	//for (int i = 0; i < Player::playerInventory.storage.size(); i++){
	//	std::cout << Player::playerInventory.storage[i] << " ";
	//}
	//curScreenState = TRADING;

	//curScreenState = CUTSCENE;
	//Cutscenes::InteractionNo = interactions;
	//Cutscenes::key = "Barrel";
	//interactions++;
	Consumables* newConsumable;
	curScreenState = TRADING;
	for (int i = 0; i < 5; i++) {
		newConsumable = new Consumables(itemList[i].itemType, itemList[i].itemID);
		Player::playerInventory.consumableStorage.push_back(newConsumable);
	}

	//std::cout << "BARREL INTERACT";
		
}

