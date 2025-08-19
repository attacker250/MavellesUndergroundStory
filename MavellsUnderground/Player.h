#pragma once
#include "Entity.h"
#include <vector>
#include <string>
#include "Inventory.h"



class Player: public Entity
{
public:
	//store name of items as string then access the item json data

	
	int xmov = 0;
	int ymov = 0;
	const int maxInvSize = 5;
	static Inventory playerInventory;

	std::string RoomDestination;
	std::string lastDoor;

	bool move() override;
	
	Player() {
		icon = 'P';
	}
};

