#include "Game.h"
#include "json.hpp"
#include <fstream>
#include "conio.h"
#include <iostream>
#include "Windows.h"
#include <string>
#include "Room.h"
#include "Battle.h"

char Game::mapData[ROWS][COLUMNS];

int Game::curScreenState = MAP_RENDER;


//char Game::mapObjects[SECTORS][ROOMS][ROWS][COLUMNS];
bool Game::enteredRm[SECTORS][ROOMS];

//typewriter effect for dialogue






void Game::checkMap()
{
	for (int i = 0; i < ROWS; i++) {
		for (int f = 0; f < COLUMNS; f++) {

			std::cout << mapData[i][f];


		}
		std::cout << '\n';
	}

	system("cls");
//	Sleep(1000);
}




char Game::getPos(int x, int y){
	return mapData[y][x];

}


void Game::MapEdit(int xpos, int ypos, char changeto){


}

void Game::LoadMap(std::string Map, std::string room, char roomData[ROWS][COLUMNS], bool ifNew) {
    std::ifstream fMapdata("MapData/MapData.json");
    auto MapJson = nlohmann::json::parse(fMapdata);
	int rmCatalogue = static_cast<int>(room[room.length() - 1]) - 49;
	int mapCatalogue = static_cast<int>(Map[Map.length() - 1]) - 49;

	enteredRm[mapCatalogue][rmCatalogue] = true;

//	system("cls");

	for (int i = 0; i < ROWS; i++) {
		for (int j = 0; j < COLUMNS; j++) {
			//sets map to the de
			mapData[i][j] = roomData[i][j];
		}
	}
	system("cls");
}




void Game::learnScreen(){
	/*int fullAmt = 0;
	for (int i = 0; i < Battle::atkListSize; i++) {
		if (player->atkList[i] == " ") {
			Battle::atkList[i] = Battle::atkLearn;
			std::cout << "You have learned " << Battle::atkLearn << '\n';
			break;
		}
		else {
			fullAmt++;
		}
	}
	int moveForget = -1;
	while (moveForget >= 0 && moveForget < Battle::atkListSize) {
		if (fullAmt == Battle::atkListSize) {
			std::cout << '\n' << "Which move do you want to forget? " << '\n';
			for (int i = 0; i < Battle::atkListSize; i++) {
				std::cout << "[" << i + 1 << "]" << Battle::atkList[i] << std::endl;
			}
			std::cin >> moveForget;
		}
	}
	Battle::atkList[moveForget - 1] = Battle::atkLearn;
	Sleep(3000);
	curScreenState = MAP_RENDER;*/

}

void Game::resetRooms()
{
	for (int i = 0; i < SECTORS; i++) {
		for (int f = 0; f < ROOMS; f++) {
			enteredRm[i][f] = false;
		}
	}
}
		