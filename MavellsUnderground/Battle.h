#pragma once
#include "Enemy.h"
#include "Windows.h"
#include "conio.h"
#include "Player.h"
#include "Effects.h"
#include <string>
#include <vector>
#include "Battle.h"
#include "Cutscenes.h"

#include "json.hpp"
#include <fstream>

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
	
	//Misc
	static int battleHp;
	const static int atkListSize = 3;
	Player* battlePlayer;
	
	
	//Check if player is still in battle
	bool stillbattle = false;

	//Get Enemy
	Enemy* battleEnemy;

	//Way to handle if the player is still fighting
	void BattleMode();
	
	//
	void AttackList();

	void ItemList();
	void PrintBattle();
	void BattleMenu(int& curScreenState);
	void EnemyTurn();
	void initBattle(Enemy* enemy, Player* player);

	//Enemy attack Data
	std::ifstream fAtkData{ "MoveData.json" };
    nlohmann::json AtkJson = nlohmann::json::parse(fAtkData);

	Cutscenes cutscene;
};

