#pragma once
#include "Entity.h"
#include <string>
#include <vector>

class Enemy : public Entity
{
public:

	void interact() override;
	Enemy(std::string map);
	~Enemy(){
		/*mapData[y][x] = ' ';*/
		
	}
};

