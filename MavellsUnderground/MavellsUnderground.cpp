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
#include "Button.h"
#include "Door.h"
#include "Room.h"


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


void ClearScreen() {
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

int returnRoomIndex(std::string place, std::string room, std::vector<Room*> &roomList) {
	std::cout << roomList.size();
	for (int i = 0; i < roomList.size(); i++) {
		std::cout << roomList[i]->room << ' ' << roomList[i]->place << '\n';
		std::cout << room << ' ' << place << '\n';
		if (roomList[i]->room == room && roomList[i]->place == place) {
			return i;
		}
	}
	//return 0;
}

bool checkIn(std::string place, std::string room, std::vector<Room*> &roomList) {
	for (int i = 0; i < roomList.size(); i++) {
		if (roomList[i]->room == room && roomList[i]->place == place) {
			return true;
		}
	}
	return false;
}

void InitGame(Game& game, Player& player, std::vector<Entity*>& EntityList, std::string door, std::vector<Room*>& roomList) {
	enum boarddimensions {
		COLUMNS = 40,
		ROWS = 13
	};

	std::ifstream fMapdata("MapData/MapData.json");
	auto MapJson = nlohmann::json::parse(fMapdata);
	game.LoadMap(player.currentPlace, player.RoomDestination, roomList[(returnRoomIndex(player.currentPlace, player.RoomDestination, roomList))]->roomData, roomList[(returnRoomIndex(player.currentPlace, player.RoomDestination, roomList))]->newRoom);
	if (EntityList.size() > 0) {
		for (int i = 1; i < EntityList.size(); i++) {
			EntityList[i] = nullptr;
		}
		//system("pause");
	}
	EntityList.clear();
	if (!roomList[(returnRoomIndex(player.currentPlace, player.RoomDestination, roomList))]->newRoom) {
		for (int i = 0; i < roomList[(returnRoomIndex(player.currentPlace, player.RoomDestination, roomList))]->entityRoomSave.size(); i++) {
			EntityList.push_back(roomList[(returnRoomIndex(player.currentPlace, player.RoomDestination, roomList))]->entityRoomSave[i]);
		}
		std::cout << roomList[(returnRoomIndex(player.currentPlace, player.RoomDestination, roomList))]->entityRoomSave.size();
		std::cout << "paing";
	}
	//for (int i = 0; i < ROWS; i++) {
	//	for (int f = 0; f < COLUMNS; f++) {
	//		//roomList.mapData[returnRoomIndex(player.currentPlace, player.currentRoom, roomList)] = game
	//	}
	//}


	
	//game.checkMap();
	auto Data = MapJson[player.currentPlace][player.RoomDestination];
	//system("pause");
	//player.spawn(MapJson["TestMaps"][player.lastVisitedRoom][player.lastDoor]["FirstPos"][0], MapJson["TestMaps"][player.lastVisitedRoom][player.lastDoor]["FirstPos"][1]);


	
	game.checkMap();
	if (door != "Nill") {
		if(Data[door]["FirstPos"][1] > player.y){
			player.y = Data[door]["FirstPos"][1];
		}
		if (Data[door]["FirstPos"][1] < player.y) {
			player.y = Data[door]["FirstPos"][1];
		}
		if (Data[door]["SecondPos"][0] > player.x) {
			player.x = Data[door]["SecondPos"][0];
		}
		if (Data[door]["SecondPos"][0] < player.x) {
			player.x = Data[door]["SecondPos"][0];
		}

		if (Data[door]["FirstPos"][0] == Data[door]["SecondPos"][0]) {
			if (Data[door]["FirstPos"][0] < 0) {
				player.spawn(Data[door]["FirstPos"][0] + 1, player.y);
			}
			else {
				player.spawn(Data[door]["FirstPos"][0] - 1, player.y);
			}
		}
		else if (Data[door]["FirstPos"][1] == Data[door]["SecondPos"][1]) {
			if (Data[door]["FirstPos"][1] < 0) {
				player.spawn(player.x, Data[door]["FirstPos"][1] + 1);
			}
			else {
				player.spawn(player.x, Data[door]["FirstPos"][1] - 1);
			}
		}
	}
	else {
		player.spawn(20, 6);
	}
	//game.checkMap();


	system("cls");

	if (roomList[(returnRoomIndex(player.currentPlace, player.RoomDestination, roomList))]->newRoom) {
		roomList[(returnRoomIndex(player.currentPlace, player.RoomDestination, roomList))]->newRoom = false;
		EntityList.push_back(&player);
		//Detects the objects that are predefined on the map
		for (int i = 0; i < ROWS; i++) {
			for (int f = 0; f < COLUMNS; f++) {
				int rmCatalogue = static_cast<int>(player.currentRoom[player.currentRoom.length() - 1]) - 49;
				int mapCatalogue = static_cast<int>(player.currentPlace[player.currentPlace.length() - 1]) - 49;

				switch (game.mapData[i][f]) {
				case 'B':
					Barrel * barrel;
					barrel = new Barrel;
					//works aparently	
					//EntityList.push_back(new Barrel);
					EntityList.push_back(barrel);
					EntityList[EntityList.size() - 1]->spawn(f, i);
					break;
				case 'E':
					TestEnemyClass * testenemy;
					testenemy = new TestEnemyClass;
					EntityList.push_back(testenemy);
					EntityList[EntityList.size() - 1]->spawn(f, i);
					break;
				case '+':
					Button * activeBtn;
					activeBtn = new Button;
					EntityList.push_back(activeBtn);
					EntityList[EntityList.size() - 1]->spawn(f, i);
					break;
				case '-':
					Button * button;
					button = new Button;
					EntityList.push_back(button);
					EntityList[EntityList.size() - 1]->spawn(f, i);
					break;
				case '=':
					Door * pointer;
					pointer = new Door;
					EntityList.push_back(pointer);
					EntityList[EntityList.size() - 1]->spawn(f, i);
					break;
				case 'o':
					Door * door;
					door = new Door;
					door->alive = false;
					EntityList.push_back(door);
					EntityList[EntityList.size() - 1]->spawn(f, i);
					break;
				}


			}
		}
	}
	//
	// 
	// game.checkMap();
}

void checkClearCondition(std::vector<Entity*>& EntityList){
	std::string Room = Entity::currentRoom;
	std::string Place = Entity::currentPlace;
	std::ifstream fButtondata("ButtonData/ButtonData.json");
	auto ButtonJson = nlohmann::json::parse(fButtondata);
	int active = 0;
	//check how many buttons are active
	for (int i = 0; i < EntityList.size(); i++){
		if(EntityList[i]->icon == '+'){
			active++;
		}
	}
	//std::cout << active << '\n';
	if(ButtonJson[Entity::currentPlace][Entity::currentRoom].contains("ButtonsActive")){
		if(ButtonJson[Entity::currentPlace][Entity::currentRoom]["ButtonsActive"] == active) {
			//stuff it in a function
			//check through the list and see if its a door.
			//if it is, make it dead and have interact decide what to do
			for (int i = 0; i < EntityList.size(); i++) {
				if (EntityList[i]->type == "Door") {
					EntityList[i]->alive = false;
					EntityList[i]->interact();	
				}
			}
		}
		else{
			for (int i = 0; i < EntityList.size(); i++) {
				if (EntityList[i]->type == "Door") {
					EntityList[i]->alive = true;
					EntityList[i]->interact();
				}
			}
		}
	}


}




int main() {

	//std::vector<std::vector <std::vector<Entity>>> mapObj;
	////std::vector<
	//mapObj.resize(3);
	//mapObj[0].resize(7);

	std::vector<Room*> roomList;
	Room* room1 = new Room("Cave", "Room1");
	Room* room2 = new Room("Cave", "Room2");
	roomList.push_back(room1);
	roomList.push_back(room2);

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

	enum boarddimensions {
		COLUMNS = 40,
		ROWS = 13
	};
	ShowCursor(FALSE);

	Game game;
	Player player;
	game.resetRooms();
	ShowConsoleCursor(false);

	for (int i = 0; i < game.atkListSize; i++) {
		game.atkList[i] = " ";
	}

	player.lastDoor = "Door1";
	player.RoomDestination = "Room1";
	player.currentRoom = "Room1";
	player.currentPlace = "Cave";

	std::vector<Entity*> EntityList;

	InitGame(game, player, EntityList, "Nill", roomList);
	//EntityList.push_back(new Barrel);

	while (true) {
		player.rmIndex = static_cast<int>(player.currentRoom[player.currentRoom.length() - 1]) - 49;
		player.placeIndex = static_cast<int>(player.currentPlace[player.currentPlace.length() - 1]) - 49;
		if (game.curScreenState == MAP_RENDER) {

			//print out map

			//Means the players next move is not into a ' '
			if (!player.move()) {
				//check the Entity array
				//check the conditions when the buttons interacted AND when the player leaves a battle or something
				int PlayerIntendedX = player.x + player.xmov;
				int PlayerIntendedY = player.y + player.ymov;
				for (int i = 1; i < EntityList.size(); i++) {
					if ((EntityList[i]->x == PlayerIntendedX) && (EntityList[i]->y == PlayerIntendedY)) {
						EntityList[i]->interact();
						checkClearCondition(EntityList);
						break;
					}
				}
				if ((PlayerIntendedX) >= COLUMNS || (PlayerIntendedY) >= ROWS || (PlayerIntendedX) <= 0 || (PlayerIntendedY) <= 0) {
					auto setter = MapJson[player.currentPlace][player.currentRoom];
					//Second pos must be the larger value

					for (int i = 0; i < setter["DoorCount"] + 1; i++) {
						if (setter["Door" + std::to_string(i)]["FirstPos"][0] <= PlayerIntendedX && setter["Door" + std::to_string(i)]["SecondPos"][0] >= PlayerIntendedX) {
							if (setter["Door" + std::to_string(i)]["FirstPos"][1] <= PlayerIntendedY && setter["Door" + std::to_string(i)]["SecondPos"][1] >= PlayerIntendedY) {

								roomList[(returnRoomIndex(player.currentPlace, player.RoomDestination, roomList))]->importEntityList(EntityList);
								roomList[(returnRoomIndex(player.currentPlace, player.RoomDestination, roomList))]->roomSaveLayout(game.mapData);

								
								player.RoomDestination = setter["Door" + std::to_string(i)]["Destination"];
								player.currentRoom = setter["Door" + std::to_string(i)]["Destination"];

								
								InitGame(game, player, EntityList, "Door" + std::to_string(i),roomList);
								system("cls");
								break;
							}
						}
					}
					//in json, specify the door position range. Then store what door the plaayer when through
				}
			}
			//std::cout << 
			std::string Map;
			for (int i = 0; i < ROWS; i++) {
				for (int j = 0; j < COLUMNS; j++) {
					Map += game.mapData[i][j];
					//std::cout << MapData[i][j];
				}
				Map += "\n";
			}

			std::cout << Map;
			if (game.enteredRm[0][0] == false) {
				std::cout << "a \n";
				
			}
			Map = "";
			for (int i = 0; i < ROWS; i++) {
				for (int j = 0; j < COLUMNS; j++) {

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
			game.PrintBattle();
			game.BattleMenu(game.curScreenState);
			std::cout << '\n' << game.curScreenState;
		}
		if (game.curScreenState == INVENTORY) {
			for (int i = 0; i < player.playerInventory.storage.size(); i++) {
				std::cout << player.playerInventory.storage[i];
			}
		}
		if (game.curScreenState == LEARNATK) {
			game.learnScreen();
		}
		if (game.curScreenState == TRADING) {
			game.TradeMenu();
		}
			//std::cout << MapJson["TestMaps"].;


			//;
		ClearScreen();
	}
	
		//if ((xpos + xmov < COLUMNS) && (ypos + ymov < ROWS) && (xpos + xmov >= 0) && (ypos + ymov >= 0)) {

	_CrtDumpMemoryLeaks();
	return 0;
}
