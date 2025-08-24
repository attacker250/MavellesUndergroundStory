#include "Healing.h"
#include <fstream>
#include "json.hpp"
//Misc
#include <vector>


Healing::Healing(std::string itemName) {
	std::ifstream fItem("ItemData.json");
	auto ItemJson = nlohmann::json::parse(fItem);
	name = itemName;
	description = ItemJson["Healing"][itemName]["Description"];
	healing = ItemJson["Healing"][itemName]["Restoration"];
}