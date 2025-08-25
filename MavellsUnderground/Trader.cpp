#include "Trader.h"

Trader::Trader()
{
	icon = 'S';
	std::ifstream fTraderdata("TraderData/TraderData.json");
	auto TraderJson = nlohmann::json::parse(fTraderdata);
	for (int i = 0; i < TraderJson["Trader"]["Portrait"].size(); i++) {
		std::string row = "";
		row += TraderJson["Trader"]["Portrait"][i];

		portrait.push_back(row);
	}
}

void Trader::interact() {
	curScreenState = TRADING;

}
