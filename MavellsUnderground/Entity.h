#pragma once

#include <string>

class Entity
{
public:
	int x = 0;
	int y = 0;
	int hp = 0;
	bool alive = true;
	std::string type = "none";
	char icon = ' ';
	void updatePos(int movetox, int movetoy, char mapData[12][40]);
	virtual void move();
	void spawn(int spawnx, int spawny, char mapData[12][40]);
};

