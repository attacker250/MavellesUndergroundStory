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


void SwitchScreen(char MapData[12][40], int NewX, int NewY){

}

void ClearScreen(){
	COORD cursorPosition;	cursorPosition.X = 0;	cursorPosition.Y = 0;	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), cursorPosition);
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
	//MapJson["TestMaps"]["MovementTest"]["Map"][i].get<std::string>()[j];
    //char MapData[ROWS][COLUMNS];
	//char* mapDataPtr[ROWS][COLUMNS] = MapData;
	
	// for (int i = 0; i < ROWS; i++) {
	// 	for (int f = 0; f < COLUMNS; f++) {
	// 		MapData[i][f] = new char;
	// 	}
	// }

	Player player;
	Game game;

	std::vector<Entity*> EntityList;
	
	//EntityList.push_back(new Barrel);

	for (int i = 0; i < ROWS; i++) {
 		for (int f = 0; f < COLUMNS; f++) {
			switch (game.mapData[i][f]) {
				case 'B':
					EntityList.push_back(new Barrel);
			}
 		}
	}
    
	player.spawn(20, 6);



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
				//game.getPos()
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
		}

		if (game.curScreenState == BATTLE) {
			std::cout << "Battle\n";
		}


		
		//;
		ClearScreen();
	}
		//if ((xpos + xmov < COLUMNS) && (ypos + ymov < ROWS) && (xpos + xmov >= 0) && (ypos + ymov >= 0)) {
		


    return 0;
}