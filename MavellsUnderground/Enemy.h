#pragma once
#include "Entity.h"
#include <string>
#include <vector>


enum EnemyState {
	Patrol,
	Chase,
	Return
};

class Enemy : public Entity
{
	int patrolMove = 1;
	int patrolCounter = 0;
	int patrolMax = 5;


public:
	//Enemy Attack List (??????)
	std::vector<std::string> atkList;

	int dropAmt = 0;

	//bool move() override;
	void nextMove(int x, int y, int boardHeight, int boardWidth) override;
	void interact() override;
	Enemy(std::string map);
	//void nextMove(Player* userPos, int boardHeight, int boardWidth);
	~Enemy();
};

