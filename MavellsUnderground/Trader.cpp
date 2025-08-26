#include "Trader.h"
#include "Consumables.h"
#include <ctime>

Trader::Trader()
{
	srand(time(0));
	icon = 'S';
	std::ifstream fTraderdata("TraderData/TraderData.json");
	auto TraderJson = nlohmann::json::parse(fTraderdata);
	for (int i = 0; i < TraderJson["Trader"]["Portrait"].size(); i++) {
		std::string row = "";
		row += TraderJson["Trader"]["Portrait"][i];

		portrait.push_back(row);
	}
	for (int i = 0; i < traderInvSize; i++) {
		int selectedObj = rand() % itemList.size();
		Consumables* consumable;
		consumable = new Consumables(itemList[selectedObj].itemType,itemList[selectedObj].itemID);
		traderInventory.consumableStorage.push_back(consumable);

	}
}

void Trader::interact() {
	curScreenState = TRADING;

}
