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
	newConsumable = new Consumables(itemList[0].itemType,itemList[0].itemID);
	Player::playerInventory.consumableStorage.push_back(newConsumable);
	std::cout << Player::playerInventory.consumableStorage[0]->name;
	Sleep(1000);






	//std::cout << "BARREL INTERACT";
		
}

