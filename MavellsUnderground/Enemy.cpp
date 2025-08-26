#include "Enemy.h"
#include "Battle.h"
#include <fstream>
#include "json.hpp"
#include <ctime>




//SET ENEMY HP FOR BATTLE RAHHH
void Enemy::interact() {
	curScreenState = BATTLE;
	Battle::battleHp = hp;
}

Enemy::Enemy(std::string map) {
	icon = 'E';
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


	std::string enemyIndex = std::to_string(rand() % (EnemyJson[map].size()-1));
	hp = EnemyJson[map][enemyIndex]["HP"];
		//std::cout << hp;
	name = EnemyJson[map][enemyIndex]["Name"];
       //std::cout << name;
	type = EnemyJson[map][enemyIndex]["Type"];
	
	for (int i = 0; i < EnemyJson[map][enemyIndex]["Portrait"].size(); i++) {
		std::string row = "";
		row += EnemyJson[map][enemyIndex]["Portrait"][i];
		
		portrait.push_back(row);
	}
		//std::cout << type;
	for (int f = 0; f < EnemyJson[map][enemyIndex]["Attacks"].size(); f++){
		atkList.push_back(EnemyJson[map][enemyIndex]["Attacks"][f]["NAME"]);
		//attacks[i];
	}
	
}