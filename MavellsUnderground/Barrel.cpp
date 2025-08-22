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

	curScreenState = CUTSCENE;


	





	//std::cout << "BARREL INTERACT";
		
}

