#pragma once
#include "Entity.h"
class Player: public Entity
{
public:
	int xmov = 0;
	int ymov = 0;

	bool move() override;
	Player() {
		icon = 'P';
	}
};

