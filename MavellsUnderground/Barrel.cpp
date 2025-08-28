#include "Barrel.h"
#include "Player.h"
#include <iostream>
#include "Cutscenes.h"
#include "Effects.h"

Barrel::Barrel() {
	icon = 'B';
	desc = "A barrel";
}


void Barrel::interact() {
	Cutscenes::key = "Barrel";
	if (!firstInteraction) {
		Cutscenes::InteractionKey = "First";
		cutscenes.ZoomOut();
		curScreenState = CUTSCENE;
		while (!cutscenes.PlayScene())Effects::ClearScreen();
		system("cls");
		firstInteraction = true;
		curScreenState = MAP_RENDER;
		//Give Sword

		Player::playerInventory.addWeapon("Sword");
	}
	

	//Give items based on Entity Data(PLEASE)








	//Consumables* newConsumable;
	//curScreenState = TRADING;
	//for (int i = 0; i < 5; i++) {
	//	newConsumable = new Consumables(itemList[i].itemType, itemList[i].itemID);
	//	Player::playerInventory.consumableStorage.push_back(newConsumable);
	//}

	//Spear* sword;
	//sword = new Spear;
	////sword->setPlayerAttacks();

	//Player::playerInventory.weaponStorage.push_back(sword);
	//std::cout << "BARREL INTERACT";
		
}

