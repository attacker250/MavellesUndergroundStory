#pragma once

#include "Entity.h"

class Door : public Entity
{	
public:
	Door(){
		icon = '=';
	}
	int doorLvl = 0;
	void openDoor();
	void closeDoor();
};

