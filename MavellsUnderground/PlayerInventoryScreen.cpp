#include "PlayerInventoryScreen.h"

#include "conio.h"
#include "Game.h"

void PlayerInventoryScreen::printInventory()
{
	system("cls");
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
		std::cout << Player::playerInventory.consumableStorage[selectedObj]->description;
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
			Player::playerInventory.consumeItem(selectedObj);
			if (Player::playerInventory.consumableStorage[selectedObj]->broken) {
				delete Player::playerInventory.consumableStorage[selectedObj];
				Player::playerInventory.consumableStorage.erase(Player::playerInventory.consumableStorage.begin() + selectedObj);
			}
		}
		else {
			Game::curScreenState = 0;
			system("cls");
		}
	}

	std::cout << selectedObj << ' ' << Player::playerInventory.consumableStorage.size() << "HIII";
	if (selectedObj < 0) {
		selectedObj = Player::playerInventory.consumableStorage.size();
	}
	else if (selectedObj > Player::playerInventory.consumableStorage.size()) {
		selectedObj = 0;
		std::cout << selectedObj << ' ' << Player::playerInventory.consumableStorage.size();
	}
	

}


