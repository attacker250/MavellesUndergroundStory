#pragma once

#include "Entity.h"

class Door : public Entity
{	
public:
	Door(){
		icon = '=';
		type = "Door";
		desc = "The way out.Blocked";
	}
	int doorLvl = 0;
	bool opened = false;
	void interact() override;
};

