#include "Barrel.h"
#include "Player.h"
#include <iostream>

Barrel::Barrel() {
	icon = 'B';
}


void Barrel::interact() {
	for (int i = 0 ; i < giveItems.size(); i++) {
		Player::inventory.push_back(giveItems[i]);
	}
	for (int i = 0; i < Player::inventory.size(); i++){
		std::cout << Player::inventory[i] << " ";
	}
	curScreenState = INVENTORY;
	//std::cout << "BARREL INTERACT";

}

