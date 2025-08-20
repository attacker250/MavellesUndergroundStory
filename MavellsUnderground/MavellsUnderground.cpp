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
#include "TestEnemyClass.h"
#include "Entity.h"

#define _CRTDBG_MAP_ALLOC
#include <stdlib.h>
#include <crtdbg.h>


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

void InitGame(Game &game,Player &player, std::vector<Entity*> &EntityList,std::string Door) {
	std::ifstream fMapdata("MapData/MapData.json");
	auto MapJson = nlohmann::json::parse(fMapdata);
	game.LoadMap("TestMaps", player.RoomDestination);
	auto Data = MapJson["TestMaps"][player.RoomDestination];

	//player.spawn(MapJson["TestMaps"][player.lastVisitedRoom][player.lastDoor]["FirstPos"][0], MapJson["TestMaps"][player.lastVisitedRoom][player.lastDoor]["FirstPos"][1]);
	if (EntityList.size() > 0) {
		for (int i = 0; i < EntityList.size(); i++) {
			delete EntityList[i];
			EntityList.erase(EntityList.begin() + i);
		}
	}
	if(Door != "Nill"){
		if(Data[Door]["FirstPos"][0] == Data[Door]["SecondPos"][0]){
			if(Data[Door]["FirstPos"][0] < 0){
				player.spawn(Data[Door]["FirstPos"][0]+1,player.y);
			}
			else{
				player.spawn(Data[Door]["FirstPos"][0] - 1, player.y);
			}
		} 
		else if (Data[Door]["FirstPos"][1] == Data[Door]["SecondPos"][1]) {
			if(Data[Door]["FirstPos"][1] < 0){
				player.spawn(player.x, Data[Door]["FirstPos"][1]+1);
			}
			else{
				player.spawn(player.x, Data[Door]["FirstPos"][1] - 1);
			}
		}
	}
	else{
		player.spawn(20, 6);
	}

	EntityList.clear();
	_CrtDumpMemoryLeaks();

	system("cls");

	EntityList.push_back(&player);
	//Detects the objects that are predefined on the map
	for (int i = 0; i < 12; i++) {
		for (int f = 0; f < 40; f++) {
			switch (game.mapData[i][f]) {
			case 'B':
				Barrel *barrel;
				barrel = new Barrel;
				//works aparently	
				EntityList.push_back(new Barrel);
				//EntityList.push_back(barrel);
				EntityList[EntityList.size() - 1]->spawn(f, i);
				break;
			
			case 'E':
				TestEnemyClass *testenemy;
				testenemy = new TestEnemyClass;
				EntityList.push_back(testenemy);
				EntityList[EntityList.size() - 1]->spawn(f, i);
				break;
			}
		}
	}
}


int main(){
	std::ifstream fMapdata("MapData/MapData.json");
	auto MapJson = nlohmann::json::parse(fMapdata);
	enum ScreenState {
		MAP_RENDER,
		BATTLE,
		INVENTORY,
		CUTSCENE,
		TRADING,
		MENU,
		LEARNATK,

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
	
	for (int i = 0; i < game.atkListSize; i++){
		game.atkList[i] = " ";
	}
	
	player.lastDoor = "Door1";
	player.RoomDestination = "RoomTest1";
	player.currentRoom = "RoomTest1";
	player.currentPlace = "TestMaps";

	std::vector<Entity*> EntityList;

	InitGame(game,player,EntityList,"Nill");
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
				int PlayerIntendedX = player.x + player.xmov;
				int PlayerIntendedY = player.y + player.ymov;
				for (int i = 1; i < EntityList.size(); i++) {
					if ((EntityList[i]->x == PlayerIntendedX) && (EntityList[i]->y == PlayerIntendedY)) {
						EntityList[i]->interact();
						break;
					}
				}
				if ((PlayerIntendedX) >= 40 || (PlayerIntendedY) >= 12 || (PlayerIntendedX) <= 0 || (PlayerIntendedY) <= 0) {
					auto setter = MapJson["TestMaps"][player.currentRoom];
					//Second pos must be the larger value

					for (int i = 0; i < setter["DoorCount"]+1; i++) {
						if(setter["Door"+std::to_string(i)]["FirstPos"][0] <= PlayerIntendedX && setter["Door"+std::to_string(i)]["SecondPos"][0] >= PlayerIntendedX ){
							if (setter["Door"+std::to_string(i)]["FirstPos"][1] <= PlayerIntendedY  && setter["Door"+std::to_string(i)]["SecondPos"][1] >= PlayerIntendedY) {
								player.RoomDestination = setter["Door" + std::to_string(i)]["Destination"];
								InitGame(game, player, EntityList, "Door" + std::to_string(i));
								player.currentRoom = setter["Door" + std::to_string(i)]["Destination"];

								break;
							}
						}
					}
					//in json, specify the door position range. Then store what door the plaayer when through
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
			//std::cout << "Battle\n";
			game.PrintBoard();
			game.BattleMenu(game.curScreenState);
			std::cout << '\n' << game.curScreenState;
		}
		if (game.curScreenState == INVENTORY){
			for (int i = 0; i < player.playerInventory.storage.size(); i++){
				std::cout << player.playerInventory.storage[i];
			}
		} 
		if (game.curScreenState == LEARNATK){
			game.learnScreen();
		} 
		//std::cout << MapJson["TestMaps"].;

		
		//;
		ClearScreen();
	}
		//if ((xpos + xmov < COLUMNS) && (ypos + ymov < ROWS) && (xpos + xmov >= 0) && (ypos + ymov >= 0)) {
		

    return 0;
}