#include "PlayerInventoryScreen.h"

#include "conio.h"
#include "Game.h"
#include "Player.h"

void PlayerInventoryScreen::printInventory(){

	system("cls");
	//print out header
	for (int i = 0; i < inventoryWidth + 2; i++) {
		std::cout << '-';
	}
	std::cout << "\n|";
	std::cout << "Inventory Menu";
	fitBox(inventoryWidth, "Inventory Menu");
	std::cout << "|\n|";
	std::string thingy;
	thingy += "HP:";
	thingy += std::to_string(Player::hp);
	std::cout << thingy;
	fitBox(inventoryWidth, thingy);
	std::cout << "|\n";

	for (int i = 0; i < inventoryWidth + 2; i++) {
		std::cout << '-';
	}
	std::cout << '\n';
	for (int i = 0; i < Player::playerInventory.consumableStorage.size(); i++) {
		std::string name = "";
		if (selectedObj == i) {
			name += '>';
		}
		name += Player::playerInventory.consumableStorage[i]->name;
		std::cout << '|' << name;
		fitBox(inventoryWidth, name);
		std::cout << "|\n";
	}
	std::cout << '|';
	std::string backText = "";
	if (selectedObj == Player::playerInventory.consumableStorage.size()) {
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
	if (selectedObj != Player::playerInventory.consumableStorage.size()) {
		std::cout << "|Description:";
		fitBox(inventoryWidth, "|Description:");
		std::cout << " |\n";
		std::cout << "|" << Player::playerInventory.consumableStorage[selectedObj]->description;
		fitBox(inventoryWidth, Player::playerInventory.consumableStorage[selectedObj]->description);
		std::cout << "|\n|";
		for (int i = 0; i < inventoryWidth; i++) {
			std::cout << '-';
		}
		std::cout << "|";
		std::cout << "\n->Enter to activate/equip";

	}
}

void PlayerInventoryScreen::inventorySelection()
{
	printInventory();
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
		if (selectedObj < Player::playerInventory.consumableStorage.size()){
			Player::consumeItem(selectedObj);
		}
		else {
			Game::curScreenState = 0;
			system("cls");
		}
	}

	//std::cout << selectedObj << ' ' << Player::playerInventory.consumableStorage.size() << "HIII";
	if (selectedObj < 0) {
		selectedObj = Player::playerInventory.consumableStorage.size();
	}
	else if (selectedObj > Player::playerInventory.consumableStorage.size()) {
		selectedObj = 0;
		//std::cout << selectedObj << ' ' << Player::playerInventory.consumableStorage.size();
	}
	

}
