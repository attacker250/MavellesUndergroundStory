// MavellsUnderground.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

//Input
#include <iostream>
#include "conio.h"

//Json and File library
#include <fstream>
#include "json.hpp"
//Misc
#include <vector>
#include <string>
#include <windows.h>


//Entity headers
#include "Player.h"
#include "Barrel.h"

#include "Entity.h"
//bool checkmove(char Mapdata[12][40], int Newy, int NewX, int ROWS, int COLS){
//	for (int i = 0; i < 12; i++){
//		for (int j = 0; j < 40; j++){
//			switch (Mapdata[i][j]){
//			case '*':
//			 
//			}
//		}
//	}
//	return false;
//}


void ClearScreen(){
	COORD cursorPosition;	cursorPosition.X = 0;	cursorPosition.Y = 0;	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), cursorPosition);
}

void ShowConsoleCursor(bool showFlag)
{
	HANDLE out = GetStdHandle(STD_OUTPUT_HANDLE);

	CONSOLE_CURSOR_INFO     cursorInfo;

	GetConsoleCursorInfo(out, &cursorInfo);
	cursorInfo.bVisible = showFlag; // set the cursor visibility
	SetConsoleCursorInfo(out, &cursorInfo);
}

void InitGame(Game &game,Player &player, std::vector<Entity*> &EntityList,std::string Room , std::string map) {
	std::ifstream fMapdata("MapData/MapData.json");
	auto MapJson = nlohmann::json::parse(fMapdata);
	game.LoadMap("TestMaps", player.RoomDestination);

	//player.spawn(MapJson["TestMaps"][player.lastVisitedRoom][player.lastDoor]["FirstPos"][0], MapJson["TestMaps"][player.lastVisitedRoom][player.lastDoor]["FirstPos"][1]);
	player.spawn(20,6);

	EntityList.push_back(&player);
	//Detects the objects that are predefined on the map
	for (int i = 0; i < 12; i++) {
		for (int f = 0; f < 40; f++) {
			switch (game.mapData[i][f]) {
			case 'B':
				EntityList.push_back(new Barrel);
				EntityList[EntityList.size() - 1]->x = f;
				EntityList[EntityList.size() - 1]->y = i;
			}
		}
	}



}

int main(){
	enum ScreenState {
		MAP_RENDER,
		BATTLE,
		INVENTORY,
		CUTSCENE,
		TRADING,
		MENU,
		MAXSCREENSTATE

	};
	//std::ifstream fMapdata("MapData/MapData.json");
	//auto MapJson = nlohmann::json::parse(fMapdata);
	enum boarddimensions {
		COLUMNS = 40,
		ROWS = 12
	};
	ShowCursor(FALSE);
	//MapJson["TestMaps"]["MovementTest"]["Map"][i].get<std::string>()[j];
    //char MapData[ROWS][COLUMNS];
	//char* mapDataPtr[ROWS][COLUMNS] = MapData;
	
	// for (int i = 0; i < ROWS; i++) {
	// 	for (int f = 0; f < COLUMNS; f++) {
	// 		MapData[i][f] = new char;
	// 	}
	// }

	Game game;
	Player player;
	ShowConsoleCursor(false);
	
	
	player.lastDoor = "Door1";
	player.RoomDestination = "RoomTest1";
	std::vector<Entity*> EntityList;

	InitGame(game,player,EntityList,"TestMaps","RoomTest1");
	//EntityList.push_back(new Barrel);

	while (true) {


		//if (_kbhit()) {
		//	player.move();
		//	char getbtn = static_cast<char>(_getch());
			
			//if (getbtn == '1'){
			//	system("cls");
			//	curScreenState = BATTLE;
			//	}
			//if (getbtn == '2') {
			//	system("cls");
			//	curScreenState = MAP_RENDER;
			//}

	


		if (game.curScreenState == MAP_RENDER){
			//print out map
			
			if (!player.move()) {
				//check the array
				for (int i = 1; i < EntityList.size(); i++) {
					if ((EntityList[i]->x == player.x + player.xmov) && (EntityList[i]->y == player.y + player.ymov)) {
						EntityList[i]->interact();
						break;
					}

				if ((player.x + player.xmov) >= 40 || (player.y + player.ymov) >= 12) {


					InitGame(game, player, EntityList, "TestMaps", "RoomTest2");
					//in json, specify the door position range. Then store what door the plaayer when through
				}
				}
			}

			std::string Map;
			for (int i = 0; i < 12; i++) {
				for (int j = 0; j < 40; j++) {
					Map += game.mapData[i][j];
					//std::cout << MapData[i][j];
				}
				Map += "\n";
			}
			std::cout << Map;	
			if (game.curScreenState != MAP_RENDER) {
				system("cls");
			}
		}

		if (game.curScreenState == BATTLE) {
			std::cout << "Battle\n";
		}
		if (game.curScreenState == INVENTORY){
			for (int i = 0; i < player.playerInventory.storage.size(); i++){
				std::cout << player.playerInventory.storage[i];
			}
		}


		
		//;
		ClearScreen();
	}
		//if ((xpos + xmov < COLUMNS) && (ypos + ymov < ROWS) && (xpos + xmov >= 0) && (ypos + ymov >= 0)) {
		


    return 0;
}