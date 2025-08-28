#pragma once
#include "Entity.h"
#include "Inventory.h"


#include <vector>
#include <string>

class Skeleton : public Entity {
public:
	//Inventory barrelinventory;
	Skeleton();
	void interact();
	//Check what stage of interaction
	bool firstInteraction = false;
};

