#include "Consumables.h"
#include <fstream>
#include "json.hpp"
//Misc
#include <vector>

Consumables::Consumables(std::string type, int itemID) {
	std::ifstream fItem("ItemData.json");
	auto ItemJson = nlohmann::json::parse(fItem);
	name = ItemJson[type][itemID]["Name"];
	description = ItemJson[type][itemID]["Description"];
	itemDurability = ItemJson[type][itemID]["Durability"];
	itemEffectiveness = ItemJson[type][itemID]["Effectiveness"];
	itemValue = ItemJson[type][itemID]["Value"];
	itemType = type;
	broken = false;
}

void Consumables::consume(int consumeAmt)
{
	itemDurability -= consumeAmt;
	if (itemDurability <= 0) {
		broken = true;
	}
}
