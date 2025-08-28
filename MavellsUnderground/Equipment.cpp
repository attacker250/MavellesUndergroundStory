#include "Equipment.h"
#include "conio.h"
#include "Game.h"
#include "Player.h"

void Equipment::printEquipment()
{
	system("cls");
	for (int i = 0; i < inventoryWidth + 2; i++) {
		std::cout << '-';
	}
	std::cout << "\n|";
	std::cout << "Equipment Menu";
	fitBox(inventoryWidth, "Equipment Menu");
	std::cout << "|\n";
	for (int i = 0; i < inventoryWidth + 2; i++) {
		std::cout << '-';
	}
	std::cout << '\n';
	for (int i = 0; i < Player::playerInventory.weaponStorage.size(); i++) {
		if (Player::playerInventory.weaponStorage[i]->inUse == true) {
			changeColor(FOREGROUND_RED);
		}
		std::string name = "";
		if (selectedObj == i) {
			
			name += '>';
		}
		name += Player::playerInventory.weaponStorage[i]->name;
		std::cout << '|' << name;
		changeColor(7);
		fitBox(inventoryWidth, name);
		std::cout << "|\n";
	}
	std::cout << '|';
	std::string backText = "";
	if (selectedObj == Player::playerInventory.weaponStorage.size()) {
		backText += ">";
	}
	backText += "Back";
	std::cout << backText;
	fitBox(inventoryWidth, backText);
	std::cout << "|\n";
	for (int i = 0; i < inventoryWidth + 2; i++) {
		std::cout << '-';
	}
	std::cout << '\n';
	if (selectedObj != Player::playerInventory.weaponStorage.size()) {
		std::string typeText = "|Type: " + Player::playerInventory.weaponStorage[selectedObj]->type;
		std::cout << typeText;
		fitBox(inventoryWidth + 1, typeText);
		std::cout << "|\n";
		std::cout << "|Description:";
		fitBox(inventoryWidth, "|Description:");
		std::cout << " |\n";
		std::cout << "|" << Player::playerInventory.weaponStorage[selectedObj]->description;
		fitBox(inventoryWidth, Player::playerInventory.weaponStorage[selectedObj]->description);
		std::cout << "|\n|";
		for (int i = 0; i < inventoryWidth; i++) {
			std::cout << '-';
		}
		std::cout << "|";
	}
}

void Equipment::equipmentSelection()
{
	printEquipment();
	char getBtn = _getch();
	switch (getBtn) {
	case 'w':
	case 'W':
		selectedObj--;
		break;
	case 's':
	case 'S':
		selectedObj++;
		break;
	case '\r':
		if (selectedObj < Player::playerInventory.weaponStorage.size() && selectedObj >= 0) {
			for (int i = 0; i < Player::playerInventory.weaponStorage.size(); i++) {
				Player::playerInventory.weaponStorage[i]->inUse = false;
			}
			Player::playerInventory.weaponStorage[selectedObj]->inUse = true;
			Player::playerInventory.weaponStorage[selectedObj]->setPlayerAttacks();
		}
			
		
		else {
			Game::curScreenState = 0;
			system("cls");
		}
	}

	//make it so that the player can see the attack list in desc with their respective damage and stuff
	//std::cout << selectedObj << ' ' << Player::playerInventory.weaponStorage.size() << "HIII";
	if (selectedObj < 0) {
		selectedObj = Player::playerInventory.weaponStorage.size();
	}
	else if (selectedObj > Player::playerInventory.weaponStorage.size()) {
		selectedObj = 0;
		//std::cout << selectedObj << ' ' << Player::playerInventory.consumableStorage.size();
	}


}


