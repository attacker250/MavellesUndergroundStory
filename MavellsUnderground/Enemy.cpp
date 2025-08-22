#include "Enemy.h"
#include "Battle.h"
#include <fstream>
#include "json.hpp"



//SET ENEMY HP FOR BATTLE RAHHH
void Enemy::interact() {
	curScreenState = BATTLE;
	Battle::battleHp = hp;
}

Enemy::Enemy() {
	srand(time(0));
	std::ifstream fEnemydata("EntityData/EntityData.json");
	auto EnemyJson = nlohmann::json::parse(fEnemydata);
	for (int i = 0; i < EnemyJson["TestMaps"].size(); i++) {

	}
}