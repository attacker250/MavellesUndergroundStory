#pragma once
#include "Player.h"
#include "Effects.h"
#include <string>

class PlayerInventoryScreen : public Effects
{
public:
	const int inventoryWidth = 40;
	int selectedObj = 0;
	void printInventory();
	void inventorySelection();
};

