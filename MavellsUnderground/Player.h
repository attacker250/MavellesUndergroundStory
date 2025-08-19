#pragma once
#include "Entity.h"
#include <vector>
#include <string>

class Player: public Entity
{
public:
	//store name of items as string then access the item json data

	static std::vector<std::string> inventory;	
	int xmov = 0;
	int ymov = 0;

	bool move() override;
	Player() {
		icon = 'P';
	}
};

