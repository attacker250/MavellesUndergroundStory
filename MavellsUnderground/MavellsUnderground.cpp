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
	Entity entityList[1];
	int xpos = 0;
	int ypos = 0;
	std::ifstream fMapdata("MapData/MapData.json");
	auto MapJson = nlohmann::json::parse(fMapdata);
	enum boarddimensions {
		COLUMNS = 40,
		ROWS = 12
	};
    char MapData[ROWS][COLUMNS];
	//char* mapDataPtr[ROWS][COLUMNS] = MapData;
	
	// for (int i = 0; i < ROWS; i++) {
	// 	for (int f = 0; f < COLUMNS; f++) {
	// 		MapData[i][f] = new char;
	// 	}
	// }

	Player player;

	std::vector<Entity> entityList;
	

    for (int i = 0;i < 12;i++) {
        for (int j = 0;j < 40;j++) {
            MapData[i][j] = MapJson["TestMaps"]["MovementTest"]["Map"][i].get<std::string>()[j];
        }
    }
	player.spawn(6, 20, MapData);
    //Render gets all the relevant character data and then sets it
	//for(int i = 0;i < EntityData.size();I++{
		//for(int i = 0;i < EntityData.size();I++{
		//	if(map[] entity data or something
		// } 
	//}
	//

	enum ScreenState{
		MAP_RENDER,
		BATTLE,
		INVENTORY,
		CUTSCENE,
		TRADING,
		MENU,
		MAXSCREENSTATE

	};

	int curScreenState = MAP_RENDER;


	MapData[7][20] = 'B';



	while (true) {
		//Sleep(50);
		//system("cls");
		//Clear when any entity moves

		int xmov = 0;
		int ymov = 0;
		if (_kbhit()) {
			player.move();
			char getbtn = static_cast<char>(_getch());

			// if (getbtn == 'a') {
			// 	xmov--;
			// }
			// else if (getbtn == 'w') {
			// 	ymov--;
			// }
			// else if (getbtn == 's') {
			// 	ymov++;
			// }
			// else if (getbtn == 'd') {
			// 	xmov++;
			// }
			
			if (getbtn == '1'){
				system("cls");
				curScreenState = BATTLE;
				}
			if (getbtn == '2') {
				system("cls");
				curScreenState = MAP_RENDER;
			}

		}


		for (int i = 0; i < COLUMNS; i++) {
			for (int f = 0; f < ROWS; f++) {
				if (MapData[f][i] == 'P') {
					xpos = i;
					ypos = f;
				}
			}
		}
		MapData[ypos][xpos] = ' ';
		MapData[ypos + ymov][xpos + xmov] = 'P';


		if (curScreenState == MAP_RENDER){
			//print out map
			std::string Map;
			for (int i = 0; i < 12; i++) {
				for (int j = 0; j < 40; j++) {
					Map += MapData[i][j];
					//std::cout << MapData[i][j];
				}
				Map += "\n";
			}
			std::cout << Map;	
		}

		if (curScreenState == BATTLE) {
			std::cout << "Battle\n";
		}



		//;
		ClearScreen();
	}
		//if ((xpos + xmov < COLUMNS) && (ypos + ymov < ROWS) && (xpos + xmov >= 0) && (ypos + ymov >= 0)) {
		


    return 0;
}