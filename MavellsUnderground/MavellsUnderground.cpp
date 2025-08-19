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
				EntityList[EntityList.size() - 1]->spawn(f, i);
				break;
			
			case 'E':
				EntityList.push_back(new TestEnemyClass);
				EntityList[EntityList.size() - 1]->spawn(f, i);
				break;
			}
		}
	}
}

void PrintBoard() { //to be replaced with enemy ASCII
	const int width = 41;
	const int height = 12;
	const int inner = 39;
	for (int i = 0; i < 41; i++) {
		std::cout << '_';
	}
	std::cout << "\n";
	for (int i = 0; i < height; i++) {
		std::cout << '|';
		for (int j = 0; j < inner; j++) {
			std::cout << ' ';
		}
		std::cout << '|' << std::endl;
	}
	for (int i = 0; i < width; i++) {
		std::cout << '-';
	}
}

void Battle(int e1hp) {
	int enemy1hp = e1hp;
	bool stillbattle = true;
	if (enemy1hp <= 0) {
		enemy1hp = 0;
		stillbattle = false;
	}
	if (stillbattle == true) {
		std::cout << "\n";
		std::cout << "Enemy's HP:" << enemy1hp << std::endl;
		std::cout << "[1] Attack 1" << std::endl;
		std::cout << "[2] Items" << std::endl;
		std::cout << "[3] Run 1" << std::endl;
	}
	else if (stillbattle == false) {
		std::cout << "YOU WON!" << std::endl;
		return;
	}

}

void ItemList() {
	std::cout << "\n";
	std::cout << "[1] Item 1" << std::endl;
	std::cout << "[2] Item 2" << std::endl;
	std::cout << "[3] Item 3" << std::endl;
	std::cout << "[4] Back" << std::endl;

	char getbtn = static_cast<char>(_getch());
	if (getbtn) {
		Beep(1080, 300);
		switch (getbtn) {
		case '1':
			std::cout << "use item 1" << std::endl;
			Sleep(500);
			system("cls");
			PrintBoard();
			break;
		case '2':
			std::cout << "use item 2" << std::endl;
			Sleep(500);
			system("cls");
			PrintBoard();
			break;
		case '3':
			std::cout << "use item 3" << std::endl;
			Sleep(500);
			system("cls");
			PrintBoard();
			break;
		case '4':
			system("cls");
			PrintBoard();
			return;
		}
	}
}

void AttackList(int& e1hp) {
	int enemy1hp = e1hp;
	std::cout << "\n";
	std::cout << "[1] Fire attack" << std::endl;
	std::cout << "[2] Water attack" << std::endl;
	std::cout << "[3] Grass attack" << std::endl;
	std::cout << "[4] Back" << std::endl;

	char getbtn = static_cast<char>(_getch());
	if (getbtn) {
		Beep(1080, 300);
		switch (getbtn) {
		case '1':
			std::cout << "You chose Fire attack!" << std::endl;
			e1hp -= 20;
			Sleep(500);
			system("cls");
			PrintBoard();
			break;
		case '2':
			std::cout << "You chose Water attack!" << std::endl;
			e1hp -= 5;
			Sleep(500);
			system("cls");
			PrintBoard();
			break;
		case '3':
			std::cout << "You chose Grass attack!" << std::endl;
			e1hp -= 10;
			Sleep(500);
			system("cls");
			PrintBoard();
			break;
		case '4':
			system("cls");
			PrintBoard();
			return;
		}
	}

}

void mainmenu(int& e1hp, int &curScreenState) {
	int enemy1hp = e1hp;
	bool isRunning = true;
//	while (isRunning) {
	Battle(enemy1hp);
	char getbtn = static_cast<char>(_getch());
	if (getbtn) {
		Beep(1080, 300);
		switch (getbtn) {
		case '1':
			system("cls");
			PrintBoard();
			AttackList(enemy1hp);
			break;
		case '2':
			system("cls");
			PrintBoard();
			ItemList();
			break;
		case '3':
			std::cout << "You chose Run 1!" << std::endl;
			curScreenState = 0;
			system("cls");
			break;
		default:
			std::cout << "Invalid choice!" << std::endl;
			break;
			
		}
	}
}
//typewriter effect for dialogue
void typewriter(std::string& text, int delay) {
	int textspeed = delay;

	for (char c : text) {
		std::cout << c;
		std::cout.flush();
		Sleep(textspeed);

		if (GetAsyncKeyState('k') & 0x8000) {
			textspeed = 2;
		}
		else {
			textspeed = delay;
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
	std::string currentRoom;

	Game game;
	Player player;
	ShowConsoleCursor(false);
	
	
	player.lastDoor = "Door1";
	player.RoomDestination = "RoomTest1";
	currentRoom = "RoomTest1";

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
				int PlayerIntendedX = player.x + player.xmov;
				int PlayerIntendedY = player.y + player.ymov;
				for (int i = 1; i < EntityList.size(); i++) {
					if ((EntityList[i]->x == PlayerIntendedX) && (EntityList[i]->y == PlayerIntendedY)) {
						EntityList[i]->interact();
						break;
					}
				}
				if ((PlayerIntendedX) >= 40 || (PlayerIntendedY) >= 12) {
					//std::cout << player.RoomDestination;
					//for (int i = 0; i < MapJson["TestMaps"][currentRoom]["DoorCount"]; i++) {
					//	if(MapJson["TestMaps"][currentRoom]["Door"+std::to_string(i)][0] == PlayerIntendedX){
					//		std::cout << "Test 1";
					//		system("pause");
					//		if (MapJson["TestMaps"][currentRoom]["Door" + std::to_string(i)][1] == PlayerIntendedY) {
					//			player.RoomDestination = MapJson["TestMaps"][currentRoom]["Door" + std::to_string(i)]["Destination"];
					//			currentRoom = MapJson["TestMaps"][currentRoom]["Door" + std::to_string(i)]["Destination"];

					//			break;
					//		}
					//	}
					//}
					//InitGame(game, player, EntityList, "TestMaps", "RoomTest2");
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
			int enemy1hp = 100;

			PrintBoard();
			mainmenu(enemy1hp,game.curScreenState);
			std::cout << '\n' << game.curScreenState;
		}
		if (game.curScreenState == INVENTORY){
			for (int i = 0; i < player.playerInventory.storage.size(); i++){
				std::cout << player.playerInventory.storage[i];
			}

		}
		//std::cout << MapJson["TestMaps"].;

		
		//;
		ClearScreen();
	}
		//if ((xpos + xmov < COLUMNS) && (ypos + ymov < ROWS) && (xpos + xmov >= 0) && (ypos + ymov >= 0)) {
		


    return 0;
}