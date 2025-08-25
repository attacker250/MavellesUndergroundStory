#pragma once

#include <string>

class Consumables
{
public:
	std::string name = "";
	std::string description = "";
	std::string itemType;
	int itemEffectiveness = 0;
	int itemDurability = 0;
	bool broken = 0;
	Consumables(std::string type, int itemID);
	void consume(int consumeAmt);
	
};


