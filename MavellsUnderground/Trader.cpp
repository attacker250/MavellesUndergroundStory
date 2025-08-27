#include "Trader.h"
#include "Consumables.h"
#include <ctime>

Trader::Trader(std::vector<Weapon*> weaponsList)
{
	srand(time(0));
	icon = 'S';
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
		
		if (ifWeaponInventory <= 10 && i == traderInvSize - 1) {
			int randomWeapon = rand() % weaponList.size();
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
	curScreenState = TRADING;

}
