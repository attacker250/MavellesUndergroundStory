#pragma once
#include "Entity.h"
class Player: public Entity
{
public:
	int xmov = 0;
	int ymov = 0;
	int xpos, ypos;
	void move() override;
	
};

