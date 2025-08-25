#pragma once
#include "Entity.h"
#include <string>
#include <vector>

class Enemy : public Entity
{
public:

	void interact() override;
	Enemy();
	~Enemy(){
		mapData[y][x] = ' ';
	}
};

