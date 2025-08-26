#pragma once
#include "Entity.h"
#include <fstream>
#include "json.hpp"
#include "Trader.h"
#include "Inventory.h"


class Trader : public Entity
{

public:
	Inventory traderInventory;
	Trader();
	void interact();
	const int traderInvSize = 5;
};

