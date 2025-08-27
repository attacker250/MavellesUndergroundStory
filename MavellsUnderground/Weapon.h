#pragma once
#include <string>

#include "Enemy.h"


class Weapon
{
public:
	//Player* player;
	//static void setPlayer(Player* player);
	virtual void move1(Enemy* enemy);
	virtual void move2(Enemy* enemy);
	virtual void move3(Enemy* enemy);
	virtual void move4(Enemy* enemy);
	virtual void setPlayerAttacks();
	int itemValue = 0;
	bool inUse = false;
	std::string name = "";
	std::string description = "";
};

