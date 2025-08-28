#include "Trader.h"
#include "Consumables.h"
#include <ctime>
#include "Player.h"
#include "Cutscenes.h"

Trader::Trader(std::vector<Weapon*> weaponsList)
{
	srand(time(0));
	icon = 'T';
	desc = "???";
	int ifWeaponInventory = rand() % 10;
	std::cout << ifWeaponInventory;
	//Sleep(3000);
	std::ifstream fTraderdata("TraderData/TraderData.json");
	auto TraderJson = nlohmann::json::parse(fTraderdata);
	for (int i = 0; i < weaponsList.size(); i++) {
		weaponList.push_back(weaponsList[i]);
	}
	for (int i = 0; i < TraderJson["Trader"]["Portrait"].size(); i++) {

		std::string row = "";
		row += TraderJson["Trader"]["Portrait"][i];

		portrait.push_back(row);
	}
	for (int i = 0; i < traderInvSize; i++) {
		int randomWeapon = rand() % weaponList.size();
		randomWeapon = 0;
		bool inInv = false;
		for (int f = 0; f < Player::playerInventory.weaponStorage.size(); f++) {
			if (weaponList[randomWeapon] == Player::playerInventory.weaponStorage[f]) {
				inInv = true;
			}
		}
		if (ifWeaponInventory <= 10 && i == traderInvSize - 1 && inInv == false) {

			traderInventory.weaponStorage.push_back(weaponList[randomWeapon]);
		}
		else {
			int selectedObj = rand() % itemList.size();
			Consumables* consumable;
			consumable = new Consumables(itemList[selectedObj].itemType, itemList[selectedObj].itemID);
			traderInventory.consumableStorage.push_back(consumable);
		}

	}
}

void Trader::interact() {
	curScreenState = CUTSCENE;
	Cutscenes::key = "Trader";
	Cutscenes::InteractionKey = "Intro";
	system("cls");
	cutscenes.ZoomOut();
	while (!cutscenes.PlayScene())Effects::ClearScreen();
	system("cls");
	cutscenes.ZoomIn();
	curScreenState = TRADING;

}
