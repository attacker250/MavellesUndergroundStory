#pragma once
#include <string>

#include "Enemy.h"

struct atkData {
	std::string name = "";
	std::string description = "";;
	int damage = 0;
};

class Weapon
{
public:
	//Player* player;
	//static void setPlayer(Player* player);
	virtual int move1(Enemy* enemy);
	virtual int move2(Enemy* enemy);
	virtual int move3(Enemy* enemy);
	virtual int move4(Enemy* enemy);
	virtual void setPlayerAttacks();
	Weapon(std::string weaponName);
	int itemValue = 0;
	bool inUse = false;
	std::string name = "";
	std::string description = "";
	std::string type = "";
	std::vector<atkData> weaponAtk;
};

