#pragma once
#include "Entity.h"
#include "Inventory.h"
#include "Sword.h"

#include <vector>
#include <string>

class Barrel: public Entity {
	public:
		//Inventory barrelinventory;
		Barrel();
		void interact();
		//Check what stage of interaction
		bool firstInteraction = false ;
};
	
