#pragma once
#include "Entity.h"
#include "Inventory.h"


#include <vector>
#include <string>

class Padlock : public Entity {
public:
	//Inventory barrelinventory;
	Padlock();
	void interact();
	//Check what stage of interaction
	bool secret = false;
	bool firstInteraction = false;
};

