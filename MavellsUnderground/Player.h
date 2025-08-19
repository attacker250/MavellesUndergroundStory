#pragma once
#include "Entity.h"
class Player: public Entity
{
public:
	int xmov = 0;
	int ymov = 0;

	void move() override;
	Player() {
		icon = 'P';
	}
};

