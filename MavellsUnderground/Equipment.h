#pragma once
#include "Effects.h"

class Equipment : public Effects
{
public:
	const int inventoryWidth = 40;
	int selectedObj = 0;
	void printEquipment();
	void equipmentSelection();
};

