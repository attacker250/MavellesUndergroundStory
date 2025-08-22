#pragma once
#include "Enemy.h"
#include "Windows.h"
#include "conio.h"
#include "Entity.h"
#include "Player.h"
#include "Effects.h"
#include <string>

class Battle : public Effects
{
public:
	static int battleHp;
	const static int atkListSize = 3;
	//static std::string atkList[atkListSize];
	static std::string atkLearn;
	Entity *battleEnemy;
	Entity* battlePlayer;
	//std::string atkList[4];
	

	void BattleMode();
	void AttackList();
	void ItemList();
	void PrintBattle();
	void BattleMenu(int& curScreenState);
	void EnemyTurn();
	void initBattle(Entity* enemy, Entity* player);

};

