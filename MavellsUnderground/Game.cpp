#include "Game.h"
#include "json.hpp"
#include <fstream>
#include "conio.h"
#include <iostream>
#include "Windows.h"
#include "Room.h"
#include "Battle.h"
#include "Cutscenes.h"




//std::vector<Weapon*> Game::weaponList;
std::string Game::key;
std::string Game::InteractionKey;
std::vector<Game::itemPath> Game::itemList;
bool Game::gameQuit = false;


Consumables Game::returnItem(std::string type, int itemID) {
	Consumables obj(type, itemID);
	return obj;
}



char Game::mapData[ROWS][COLUMNS];

//int Game::curScreenState = MAIN_MENU;
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



void Game::mainMenuScrn(){
	system("cls");
	HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(h, FOREGROUND_BLUE | FOREGROUND_GREEN);
	std::string main[11] =
	{ "     _    _    _ _   _ _____  ____ _     _              ",
	 "    / `  |  ` / | ` | | ____|/ ___| |   / `                 ",
	 "   / _ ` | |`/| |  `| |  __| `___`| |  / _ `                  ",
	 "  / ___ `| |  | | |`  | |___ ___) | | / ___ `              ",
	 " /_/   `_`_|_ |_|_| `_|_____|____/|_|/_/___`_` ____   _____  ",
	 "   / `  |  _ ` `   / / ____|| ` | |_   _| | | |  _ ` | ____| ",
	 "  / _ ` | | | ` ` / /|  _|  |  `| | | | | | | | |_) ||  _|  ",
	 " / ___ `| |_| |` V / | |___ | |`  |_| |_| |_| |  _ / | |___",
	 "/_/   `_`____/  `_/  |_____||_| `_|_____|`___/|_| `_`|_____|   ",
	 "                                                               ",
	 "                                                               " };

	std::string menu[2] = {
	 "[1] Start New Game",
	 "[2] Quit"
	};





	for (int i = 0; i < 5; i++) {
		std::cout << main[i] << std::endl;
	}
	SetConsoleTextAttribute(h, FOREGROUND_GREEN | FOREGROUND_RED);
	for (int i = 5; i < 9; i++) {
		std::cout << main[i] << std::endl;
	}
	SetConsoleTextAttribute(h, FOREGROUND_RED | FOREGROUND_BLUE | FOREGROUND_GREEN);
	for (int i = 9; i < 11; i++) {
		std::cout << main[i] << std::endl;
	}
	for (int i = 0; i < 2; i++) {
		std::cout << menu[i] << std::endl;
	}

	//press any key to start the game
	char getbtn = _getch();
	//clear starting screen and render map
	int getbtnNumber = (getbtn - '0');
	if (getbtnNumber == 1) {



		Cutscenes::key = "Intro";
		Cutscenes::InteractionKey = "Intro";
		system("cls");
		Cutscenes playIntro;
		curScreenState = CUTSCENE;
		playIntro.ZoomOut();
		while (!playIntro.PlayScene())Effects::ClearScreen();
		system("cls");
		playIntro.ZoomIn();




		curScreenState = MAP_RENDER;

	}
	else if (getbtnNumber == 2) {
		gameQuit = true;
	}
}

//void Game::getWeaponList(std::vector<Weapon*> weaponsList)
//{
//	for (int i = 0; i < weaponsList.size(); i++) {
//		weaponList.push_back(weaponsList[i]);
//	}
//}

Game::Game()
{
	std::ifstream fItem("ItemData.json");
	auto ItemJson = nlohmann::json::parse(fItem);


	std::vector<std::string> itemTypeList;

	itemTypeList.push_back("Healing");

	for (int i = 0; i < itemTypeList.size(); i++) {
		for (int f = 0; f < ItemJson[itemTypeList[i]].size(); f++) {
			itemPath itempath;
			itempath.itemID = f;
			itempath.itemType = itemTypeList[i];
			itemList.push_back(itempath);
		}
	}
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
		