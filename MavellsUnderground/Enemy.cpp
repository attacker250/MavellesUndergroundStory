#include "Enemy.h"
#include "Battle.h"
#include <fstream>
#include "json.hpp"
#include <ctime>
#include "Player.h"

//SET ENEMY HP FOR BATTLE RAHHH
void Enemy::interact() {
	curScreenState = BATTLE;
	Battle::battleHp = hp;
}

Enemy::Enemy(std::string map) {
	icon = 'E';
	desc = "\"Kill or Be Killed.\"";
	srand(time(0));
	std::ifstream fEnemydata("EntityData/EntityData.json");
	auto EnemyJson = nlohmann::json::parse(fEnemydata);

	std::string enemyIndex;
	//tutorial enemy
	if (map == "Cave" && Player::currentRoom == "Room2") {
		enemyIndex = "1";
	}
	else {
		enemyIndex = std::to_string(rand() % (EnemyJson[map].size()-1));
	}
	 
	hp = EnemyJson[map][enemyIndex]["HP"];
		//std::cout << hp;
	name = EnemyJson[map][enemyIndex]["Name"];
       //std::cout << name;
	type = EnemyJson[map][enemyIndex]["Type"];

	dropAmt = EnemyJson[map][enemyIndex]["DropCount"];
	
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

void Enemy::nextMove(int playerX, int playerY, int boardHeight, int boardWidth)
{
	int distanceToUser = abs(y - playerY) + abs(x - playerX);
	//bool running
	if (distanceToUser <= 7) {
		//Chasing(when less than 7)
		const int directionCount = 4;
		const int direction[directionCount][2] = {
			
			{1,0},
			{0,-1},
			{0,1},
			{-1,0}
		};
		int nextX = x;
		int nextY = y;
		int minDistance = 999;


		for (int i = 0; i < directionCount; i++) {
			int newRow = y + direction[i][0];
			int newCol = x + direction[i][1];
			

			//prevent from out of the board
			if (newRow >= 0 && newRow < boardHeight && newCol >= 0 && newCol < boardWidth) {
				int dist = abs(playerY - newRow) + abs(playerX - newCol);
				if (dist < minDistance) {
					minDistance = dist;
					nextY = newRow;
					nextX = newCol;
					
				}
			}
		}
		if (mapData[nextY][nextX] == ' ') {
			updatePos(nextX, nextY);
		}

		//update position
	}
	else {
		//random move
		int dir = rand() % 4;
		int dRow = 0, dCol = 0;

		switch (dir) {
		case 0:dRow = -1; break;// up
		case 1:dRow = 1; break;// down
		case 2:dCol = -1; break;// left
		case 3:dCol = 1; break;// right
		}

		int newRow = y + dRow;
		int newCol = x + dCol;

		//prevent from out of the board
		if (newRow >= 0 && newRow < boardHeight && newCol >= 0 && newCol < boardWidth && mapData[newRow][newCol] == ' ') {
			//y = newRow;
			//x = newCol;
			updatePos(newCol, newRow);
		}
	}
}

Enemy::~Enemy() {
	std::cout << "+----Thy Reward----+";
	for (int i = 0; i < dropAmt; i++) {
		int randDrop = rand() % itemList.size();
		cutscenes.ZoomIn();
		Player::playerInventory.addItem(randDrop);
		std::cout << "\n| You obtained " << Player::playerInventory.consumableStorage[Player::playerInventory.consumableStorage.size() - 1]->name << '!';
		std::cout << "\n|--------";
		Sleep(1000);
	}
	Sleep(1000);
}