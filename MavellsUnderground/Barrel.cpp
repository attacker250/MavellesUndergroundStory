#include "Barrel.h"
#include "Player.h"
#include <iostream>
#include "Cutscenes.h"
#include "Spear.h"
#include "Effects.h"

Barrel::Barrel() {
	icon = 'B';
	desc = "A barrel";
}


void Barrel::interact() {
	Cutscenes::key = "Barrel";
	if (!firstInteraction) {
		Cutscenes::InteractionKey = "First";
		Cutscenes zoom;
		zoom.ZoomOut();
		curScreenState = CUTSCENE;
		while (!zoom.PlayScene())Effects::ClearScreen();
		system("cls");
		curScreenState = MAP_RENDER;


		//firstInteraction = true;
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

