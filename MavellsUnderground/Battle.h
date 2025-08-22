#pragma once
#include "Enemy.h"
#include "Windows.h"
#include "conio.h"
#include "Effects.h"

class Battle : public Effects
{
public:
	static int battleHp;
	const static int atkListSize = 3;
	static std::string atkList[atkListSize];
	static std::string atkLearn;

	void BattleMode();
	void AttackList();
	void ItemList();
	void PrintBattle();
	void BattleMenu(int& curScreenState);
	void EnemyTurn();

};

