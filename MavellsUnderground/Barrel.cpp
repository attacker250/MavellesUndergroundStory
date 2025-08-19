#include "Barrel.h"
#include "Player.h"
#include <iostream>

Barrel::Barrel() {
	icon = 'B';
}


void Barrel::interact() {
	for (int i = 0 ; i < giveItems.size(); i++) {
		Player::playerInventory.storage.push_back(giveItems[i]);
	}
	for (int i = 0; i < Player::playerInventory.storage.size(); i++){
		std::cout << Player::playerInventory.storage[i] << " ";
	}
	curScreenState = INVENTORY;
	//std::cout << "BARREL INTERACT";

}

