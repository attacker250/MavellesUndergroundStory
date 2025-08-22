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

	system("cls");


	if (EnemyJson.contains("0")) {
		std::cout << EnemyJson.contains("0");
	}
	else {
		std::cout << EnemyJson.items();
		//std::cout << "hii";
	}
	system("pause");


	// for (int i = 0; i < EnemyJson["TestMaps"].size(); i++) {
	// 	hp = EnemyJson["TestMaps"][i]["HP"];
	// 	std::cout << hp;
 //        name = EnemyJson["TestMaps"][i]["Name"];
 //        std::cout << name;
	// 	type = EnemyJson["TestMaps"][i]["Type"];
	// 	std::cout << type;
	// 	for (int f = 0; f < EnemyJson["TestMaps"][i]["Type"]["Attacks"].size(); f++){
	// 		attacks.push_back(EnemyJson["TestMaps"][i]["Type"]["Attacks"][i]["Name"]);
	// 		attacks[i];
	// 	}
	// }
}