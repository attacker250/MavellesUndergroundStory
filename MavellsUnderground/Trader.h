#pragma once
#include "Entity.h"
#include <fstream>
#include "json.hpp"
#include "Trader.h"
#include "Inventory.h"
#include <vector>
#include "Weapon.h"


class Trader : public Entity
{

public:
	Inventory traderInventory;
	std::vector<Weapon*> weaponList;
	Trader(std::vector<Weapon*> weaponsList);
	void interact() override;
	const int traderInvSize = 5;
};

