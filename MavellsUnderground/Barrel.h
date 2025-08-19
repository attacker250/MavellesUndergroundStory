#pragma once
#include "Entity.h"
#include <vector>
#include <string>

class Barrel: public Entity {
	public:
		std::vector<std::string> giveItems = { "Sword" , "Bow"};
		Barrel();
		void interact();

};

