// MavellsUnderground.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "conio.h"
#include "json.hpp"
#include <fstream>
#include <windows.h>
#include "Player.h"
#include "Entity.h"
#include <vector>
#include <string>


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
	//Entity entityList[1];
		std::ifstream fMapdata("MapData/MapData.json");
		auto MapJson = nlohmann::json::parse(fMapdata);
	enum boarddimensions {
		COLUMNS = 40,
		ROWS = 12
	};
	Game game;
	//MapJson["TestMaps"]["MovementTest"]["Map"][i].get<std::string>()[j];
    //char MapData[ROWS][COLUMNS];
	//char* mapDataPtr[ROWS][COLUMNS] = MapData;
	
	// for (int i = 0; i < ROWS; i++) {
	// 	for (int f = 0; f < COLUMNS; f++) {
	// 		MapData[i][f] = new char;
	// 	}
	// }

	Player player;

	std::vector<Entity> entityList;
	

    
	player.spawn(20, 6);
    //Render gets all the relevant character data and then sets it


	enum ScreenState {
		MAP_RENDER,
		BATTLE,
		INVENTORY,
		CUTSCENE,
		TRADING,
		MENU,
		MAXSCREENSTATE

	};

	while (true) {

		player.move();
		//int xmov = 0;
		//int ymov = 0;
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