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

	// system("cls");


	// if (EnemyJson.contains("0")) {
	// 	std::cout << EnemyJson.contains("0");
	// }
	// else {
	// 	std::cout << EnemyJson.items();
	// 	//std::cout << "hii";
	// }
	// system("pause");
	//int enemyIndex = 1;


	std::string enemyIndex = std::to_string(1);
	hp = EnemyJson["TestMaps"][enemyIndex]["HP"];
		//std::cout << hp;
	name = EnemyJson["TestMaps"][enemyIndex]["Name"];
       //std::cout << name;
	type = EnemyJson["TestMaps"][enemyIndex]["Type"];
	
	for (int i = 0; i < EnemyJson["TestMaps"][enemyIndex]["Portrait"].size(); i++) {
		std::string row = "";
		row += EnemyJson["TestMaps"][enemyIndex]["Portrait"][i];
		
		portrait.push_back(row);
	}
		//std::cout << type;
	for (int f = 0; f < EnemyJson["TestMaps"][enemyIndex]["Attacks"].size(); f++){
		atkList.push_back(EnemyJson["TestMaps"][enemyIndex]["Attacks"][f]["NAME"]);
		//attacks[i];
	}
	
}