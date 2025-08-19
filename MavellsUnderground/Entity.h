#pragma once

#include <string>
#include "Game.h"

class Entity: public Game
{
public:
	int x = 0;
	int y = 0;
	int hp = 0;
	bool alive = true;
	std::string type = "none";
	char icon = ' ';
	void updatePos(int movetox, int movetoy);
	virtual bool move();
	void spawn(int spawnx, int spawny);
	virtual void interact();
};

