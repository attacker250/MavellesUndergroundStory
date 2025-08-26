#include "Barrel.h"
#include "Player.h"
#include <iostream>
#include "Cutscenes.h"

Barrel::Barrel() {
	icon = 'B';
}


void Barrel::interact() {
	Cutscenes::key = "Barrel";
	if (!firstInteraction) {
		Cutscenes::InteractionKey = "First";
		Cutscenes zoom;
		zoom.ZoomOut();
		//firstInteraction = true;
		curScreenState = CUTSCENE;
	}
	

	//Give items based on Entity Data(PLEASE)

	//Consumables* newConsumable;
	//curScreenState = TRADING;
	//for (int i = 0; i < 5; i++) {
	//	newConsumable = new Consumables(itemList[i].itemType, itemList[i].itemID);
	//	Player::playerInventory.consumableStorage.push_back(newConsumable);
	//}

	//Sword* sword;
	//sword = new Sword;
	//sword->setPlayerAttacks();

	//Player::playerInventory.weaponStorage.push_back(sword);
	//std::cout << "BARREL INTERACT";
		
}

