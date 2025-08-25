#pragma once
#include "Enemy.h"
#include "Windows.h"
#include "conio.h"
#include "Entity.h"
#include "Player.h"
#include "Effects.h"
#include <string>
#include <vector>
#include "Battle.h"

class Battle : public Effects
{
public:
	enum ScreenState {
		MAP_RENDER,
		BATTLE,
		INVENTORY,
		CUTSCENE,
		TRADING,
		MENU,
		LEARNATK,

		MAXSCREENSTATE,
	};
	static int battleHp;
	const static int atkListSize = 3;
	bool stillbattle = false;
	//static std::string atkList[atkListSize];
	static std::string atkLearn;
	Entity *battleEnemy;
	Entity* battlePlayer;
	std::vector<Entity*> entityListBattle;
	//std::string atkList[4];
	

	void BattleMode();
	void AttackList();
	void ItemList();
	void PrintBattle();
	void BattleMenu(int& curScreenState);
	void EnemyTurn();
	void initBattle(Entity* enemy, Entity* player);

};

