
#include <iostream>
#include "conio.h"

//Json and File library
#include <fstream>
#include "json.hpp"

//Misc
#include <vector>
#include <string>
#include <windows.h>
#include <ctime>


//Entity headers
#include "Player.h"
#include "Barrel.h"
#include "TestEnemyClass.h"
#include "Entity.h"
#include "Button.h"
#include "Door.h"
#include "Room.h"
#include "Consumables.h"
#include "Trader.h"
#include "PlayerInventoryScreen.h"
#include "Weapon.h"
#include "Equipment.h"

//SceneHeaders
#include "Battle.h"
#include "Trading.h"
#include "Cutscenes.h"
#include "Game.h"


#define _CRTDBG_MAP_ALLOC
#include <stdlib.h>
#include <crtdbg.h>

std::thread _enemyThread;
std::atomic<bool> _running{ false };
std::atomic<int> size{ 0 };
//bool inGame = true;
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
enum boarddimensions {
	COLUMNS = 40,
	ROWS = 13
};

enum ScreenState {
	MAP_RENDER,
	BATTLE,
	INVENTORY,
	CUTSCENE,
	TRADING,
	MENU,
	LEARNATK,
	EQUIPMENT,
	MAIN_MENU,

	MAXSCREENSTATE,
};

void loadingScrn() {
	system("cls");
	std::cout << "Loading...";
}

void enemyLoop(std::vector<Enemy*>& enemyList, Player* player) {

	while (_running) {
		if (Game::curScreenState == MAP_RENDER) {
			for (int i = 0; i < size; i++) {
				//if (dynamic_cast<Enemy*>(entityList[i]) != nullptr) {
				//std::cout << entityList.size();
				enemyList[i]->nextMove(player->x, player->y, ROWS, COLUMNS);

				const int userPosX = player->x;
				const int userPosY = player->y;
				const int enemyPosX = enemyList[i]->x;
				const int enemyPosY = enemyList[i]->y;

				int distanceToUser = abs(userPosX - enemyPosX) + abs(userPosY - enemyPosY);

				// collision test - stop before the same position
				if (distanceToUser <= 1) {
					player->xmov = enemyList[i]->x - player->x;
					player->ymov = enemyList[i]->y - player->y;
					enemyList[i]->interact();
					
				}

				//int sleepMs = 100;

			}
		}
		std::this_thread::sleep_for(std::chrono::milliseconds(1000));

	}
}


std::vector<Weapon*> weaponsList;

int returnRoomIndex(std::string place, std::string room, std::vector<Room*>& roomList) {
	//gets the room index of the rm thats called "place" and "map" is in list
	//std::cout << roomList.size();
	for (int i = 0; i < roomList.size(); i++) {
		//std::cout << roomList[i]->room << ' ' << roomList[i]->place << '\n';
		//std::cout << room << ' ' << place << '\n';
		if (roomList[i]->room == room && roomList[i]->place == place) {
			return i;
		}
	}
	//return 0;
}

bool checkIn(std::string place, std::string room, std::vector<Room*>& roomList) {
	//checks if a room thats called "place" and "map" is in list
	for (int i = 0; i < roomList.size(); i++) {
		if (roomList[i]->room == room && roomList[i]->place == place) {
			return true;
		}
	}
	return false;
}


void InitGame(Game& game, Player& player, std::vector<Entity*>& EntityList, std::string door, std::vector<Room*>& roomList, std::vector<Enemy*>& enemyList) {


	std::ifstream fMapdata("MapData/MapData.json");
	auto MapJson = nlohmann::json::parse(fMapdata);
	game.LoadMap(player.currentPlace, player.RoomDestination, roomList[(returnRoomIndex(player.currentPlace, player.RoomDestination, roomList))]->roomData, roomList[(returnRoomIndex(player.currentPlace, player.RoomDestination, roomList))]->newRoom);
	if (EntityList.size() > 0) {
		for (int i = 1; i < EntityList.size(); i++) {
			EntityList[i] = nullptr;
		}
		//system("pause");
	}
	//sets the rooms objects onto the screen
	EntityList.clear();

	//stop previous enemy thread
	loadingScrn();
	_running = false;
	if (_enemyThread.joinable()) {
		_enemyThread.join();
	}
	system("cls");
	enemyList.clear();

	if (!roomList[(returnRoomIndex(player.currentPlace, player.RoomDestination, roomList))]->newRoom) {
		for (int i = 0; i < roomList[(returnRoomIndex(player.currentPlace, player.RoomDestination, roomList))]->entityRoomSave.size(); i++) {
			EntityList.push_back(roomList[(returnRoomIndex(player.currentPlace, player.RoomDestination, roomList))]->entityRoomSave[i]);
			if (dynamic_cast<Enemy*>(EntityList[i]) != nullptr) {
				enemyList.push_back(static_cast<Enemy*>(EntityList[i]));
				//size = enemyList.size();
			}
		}
	}

	size = enemyList.size();

	//start new enemy thread
	_running = true;
	_enemyThread = std::thread(enemyLoop, std::ref(enemyList), &player);
	//_running = false;




	//game.checkMap();
	auto Data = MapJson[player.currentPlace][player.RoomDestination];
	//system("pause");
	//player.spawn(MapJson["TestMaps"][player.lastVisitedRoom][player.lastDoor]["FirstPos"][0], MapJson["TestMaps"][player.lastVisitedRoom][player.lastDoor]["FirstPos"][1]);


	//game.checkMap();
	if (door != "Nill") {
		if (player.y < Data[door]["FirstPos"][1]) {
			player.y = Data[door]["FirstPos"][1];
		}
		else if (player.y > Data[door]["SecondPos"][1]) {
			player.y = Data[door]["SecondPos"][1];
		}
		if (player.x < Data[door]["FirstPos"][0]) {
			player.x = Data[door]["FirstPos"][0];
		}
		else if (player.x > Data[door]["SecondPos"][0]) {
			player.x = Data[door]["SecondPos"][0];
		}

		//check where the door is (is it at the top,bottom,left or right of the room)
		if (Data[door]["FirstPos"][0] == Data[door]["SecondPos"][0]) {
			//proves that the room is either right or left. then check which one it is based on room width
			if (Data[door]["FirstPos"][0] < 0) {
				player.spawn(Data[door]["FirstPos"][0] + 1, player.y);
			}
			else {
				player.spawn(Data[door]["FirstPos"][0] - 1, player.y);
			}
		}
		else if (Data[door]["FirstPos"][1] == Data[door]["SecondPos"][1]) {
			//proves that the room is either right or left. then check which one it is based on room width
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


//	system("cls");

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
					Enemy * enemy;
					enemy = new Enemy(player.currentPlace);
					enemyList.push_back(enemy);
					EntityList.push_back(enemy);

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
				case 'T':
					Trader * trader;
					trader = new Trader(weaponsList);
					EntityList.push_back(trader);
					EntityList[EntityList.size() - 1]->spawn(f, i);

				}



			}
		}


	}
	size = enemyList.size();
}

void checkClearCondition(std::vector<Entity*>& EntityList) {
	std::string Room = Entity::currentRoom;
	std::string Place = Entity::currentPlace;
	std::ifstream fButtondata("ButtonData/ButtonData.json");
	auto ButtonJson = nlohmann::json::parse(fButtondata);

	std::ifstream fMapdata("MapData/MapData.json");
	auto MapJson = nlohmann::json::parse(fMapdata);

	int active = 0;
	//check how many buttons are active
	for (int i = 0; i < EntityList.size(); i++) {
		if (EntityList[i]->icon == '+') {
			active++;
		}
	}
	
	if (MapJson[Entity::currentPlace][Entity::currentRoom]["RoomType"] == "Fight") {
		int counter = 0;
		for (int i = 0; i < EntityList.size(); i++) {
			if (EntityList[i]->icon == 'E') {
				counter++;
			}
		}
		if (counter == 0) {
			//PLEASE I BEG,STUFF THIS IN A FUNCTION
			for (int i = 0; i < EntityList.size(); i++) {
				if (EntityList[i]->type == "Door") {
					EntityList[i]->alive = false;
					EntityList[i]->interact();
				}
			}
		}
		else {
			for (int i = 0; i < EntityList.size(); i++) {
				if (EntityList[i]->type == "Door") {
					EntityList[i]->alive = true;
					EntityList[i]->interact();
				}
			}
		}
	}

	//Handle Buttons
	if (ButtonJson[Entity::currentPlace][Entity::currentRoom].contains("ButtonsActive")) {
		if (ButtonJson[Entity::currentPlace][Entity::currentRoom]["ButtonsActive"] == active) {
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
		else {
			for (int i = 0; i < EntityList.size(); i++) {
				if (EntityList[i]->type == "Door") {
					EntityList[i]->alive = true;
					EntityList[i]->interact();
				}
			}
		}
	}


}

void createRoom(std::vector<Room*>& roomList, std::string place, std::string room) {
	//creates room with the identifiers "place" and "room
	Room* newroom = new Room(place, room);
	roomList.push_back(newroom);
}


int main() {

	srand(time(0));

	std::vector<std::string> placeList;
	std::vector<std::string> itemTypeList;


	std::vector<Room*> roomList;

	placeList.push_back("Cave");


	//Json load
	std::ifstream fMapdata("MapData/MapData.json");
	auto MapJson = nlohmann::json::parse(fMapdata);

	std::ifstream fDialoguedata("Animations/Dialogue.json");
	auto DialogueJson = nlohmann::json::parse(fDialoguedata);

	std::ifstream fItemdata("ItemData.json");
	auto ItemJson = nlohmann::json::parse(fItemdata);

	//???
	for (int i = 0; i < placeList.size(); i++) {
		for (int f = 0; f < MapJson[placeList[i]].size(); f++) {
			std::string txt = "";
			txt = "Room" + std::to_string(f + 1);
			//std::cout << MapJson[placeList[i]];
			createRoom(roomList, placeList[i], txt);
		}
	}



	ShowCursor(FALSE);

	//Ready all important stuff
	Game game;
	Battle battle;
	Player player;
	Trading trading;
	Cutscenes cutscenes;
	PlayerInventoryScreen playerInventory;
	Equipment equipment;

	//???
	game.resetRooms();
	Effects::ShowConsoleCursor(false);

	//Disapointment.
	std::vector<std::string> weaponNames;
	
	for (int i = 0; i < weaponNames.size(); i++) {
		Weapon* newWeapon;
		newWeapon = new Weapon(weaponNames[i]);
		weaponsList.push_back(newWeapon);
	}




	//	game.getWeaponList(weaponsList);
		//player.playerInventory.weaponStorage.push_back(weaponsList[0]);
		//weaponsList[0]->setPlayerAttacks();

	player.lastDoor = "Door1";
	player.RoomDestination = "Room1";
	player.currentRoom = "Room1";
	player.currentPlace = "Cave";

	//player.playerInventory.consumableStorage.push_back()

	//init the thought path
	game.key = "Thoughts";
	game.InteractionKey = "Intro";

	std::vector<Entity*> EntityList;
	std::vector<Enemy*> EnemyList;
	cutscenes.ZoomOut();
	InitGame(game, player, EntityList, "Nill", roomList, EnemyList);

	//Weapon::setPlayer(static_cast<Player*>(EntityList[0]));
	//Maximize window
	//HWND consoleWindow = GetConsoleWindow(); // This gets the value Windows uses to identify your output window
	//ShowWindow(consoleWindow, SW_MAXIMIZE); // this mimics clicking on its' maximize button

	//Set the encoding format of the console
	SetConsoleOutputCP(CP_UTF8);

	//Set the max size or something (Cutscenes break if you don't Zoom out first)
	SetConsoleDisplayMode(GetStdHandle(STD_OUTPUT_HANDLE), CONSOLE_FULLSCREEN_MODE, 0);

	//Intro Splash Screen

	cutscenes.ZoomIn();
	std::cout << "Please ensure that you've launched this game with the Default Terminal Application Set to Windows Console Host.\nFor More Details, go here: https://www.makeuseof.com/set-reset-default-terminal-app-windows/";
	//Doing a zoomin here kills it for some reason
	Sleep(3000);
	system("cls");
	std::cout << "For the Best Possible Experience, Play this game in maximized or FullScreen. Please Refrain from zooming in or out during gameplay.";
	Sleep(3000);
	system("cls");
	std::cout << "Dedicated to Group 10";
	Sleep(3000);
	system("cls");
	//fullscreen
	//system("pause");
	_running = true;

	//make a func for this
	double old_time = time(0);
	//put this in game
	int dialog = 0;

	while (!game.gameQuit) {

		//What is 
		if (game.curScreenState == MAIN_MENU) {
			cutscenes.ZoomIn();
			game.mainMenuScrn();
			old_time = time(0);
		}
		if (game.curScreenState == MAP_RENDER) {
			//if (Game::curScreenState == MAP_RENDER) {
			//	for (int i = 0; i < EnemyList.size(); i++) {
			//		//if (dynamic_cast<Enemy*>(entityList[i]) != nullptr) {
			//		EnemyList[i]->nextMove(player.x, player.y, ROWS, COLUMNS);

			//		const int userPosX = player.x;
			//		const int userPosY = player.y;
			//		const int enemyPosY = EnemyList[i]->x;
			//		const int enemyPosX = EnemyList[i]->y;

			//		int distanceToUser = abs(userPosX - enemyPosX) + abs(userPosY - enemyPosY);

			//		// collision test - stop before the same position
			//		if (distanceToUser <= 2) {
			//			EnemyList[i]->interact();
			//		}

			//		//int sleepMs = 100;

			//	}
			//}
			//I genuinely don't know if constantly setting the font size is a good idea to be honest
			cutscenes.ZoomIn();

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

					//Check if the position of the doors and set the data acoordingly
					for (int i = 1; i < setter["DoorCount"] + 1; i++) {
						if (setter["Door" + std::to_string(i)]["FirstPos"][0] <= PlayerIntendedX && setter["Door" + std::to_string(i)]["SecondPos"][0] >= PlayerIntendedX) {
							if (setter["Door" + std::to_string(i)]["FirstPos"][1] <= PlayerIntendedY && setter["Door" + std::to_string(i)]["SecondPos"][1] >= PlayerIntendedY) {
								//
								roomList[(returnRoomIndex(player.currentPlace, player.RoomDestination, roomList))]->importEntityList(EntityList);
								roomList[(returnRoomIndex(player.currentPlace, player.RoomDestination, roomList))]->roomSaveLayout(game.mapData);

								//Update the Room destination
								player.RoomDestination = setter["Door" + std::to_string(i)]["Destination"];
								player.currentRoom = setter["Door" + std::to_string(i)]["Destination"];
								//check if the destination has "Place"
								if (setter["Door" + std::to_string(i)].contains("Place")) {
									player.RoomDestination = setter["Door" + std::to_string(i)]["Destination"];
								}

								InitGame(game, player, EntityList, "Door" + std::to_string(i), roomList, EnemyList);
								dialog = 0;
								break;
							}
						}
					}
					//in json, specify the door position range. Then store what door the plaayer when through
				}
			}
			std::string Map;
			for (int i = 0; i < ROWS; i++) {
				for (int j = 0; j < COLUMNS; j++) {
					Map += game.mapData[i][j];
				}
				Map += "\n";
			}

			std::cout << Map;

			//Legend System
			//today, i commit crimes because i have no mental pseverance any more
			std::cout << "Legend:\n";
			std::vector<char> check;
			std::vector<std::string> desc;
			check.push_back('P');
			desc.push_back("You");
			for (int i = 1; i < EntityList.size(); i++) {
				for (int d = 0; d < check.size(); d++) {
					if (EntityList[i]->icon == check[d]) {
						break;
					}
					else if (d == check.size() - 1){
						check.push_back(EntityList[i]->icon);
						desc.push_back(EntityList[i]->desc);
					}
				}
			}
			for (int d = 0; d < check.size(); d++) {
				std::cout << check[d] << ":" << desc[d] << "\n";
			}
			
			//Thoughts System
			std::cout << "Thoughts:";
			if (time(0) - old_time == 2 && DialogueJson[game.key][player.currentPlace][player.currentRoom].contains(game.InteractionKey)) {
				//Timer
				old_time = time(0);
				std::cout << DialogueJson[game.key][player.currentPlace][player.currentRoom][game.InteractionKey][0]["Dialogue"][dialog].get<std::string>();
				//make it so if it doesnt have the key, it plays a random thought
				if (dialog < DialogueJson[game.key][player.currentPlace][player.currentRoom][game.InteractionKey][0]["Dialogue"].size() - 1) {
					dialog++;
				}
			}

			if (game.curScreenState != MAP_RENDER) {
				system("cls");
			}
		}

		if (game.curScreenState == BATTLE) {
			for (int i = 1; i < EntityList.size(); i++) {
				if ((EntityList[i]->x == player.xmov + player.x) && (EntityList[i]->y == player.ymov + player.y)) {
					battle.initBattle(static_cast<Enemy*>(EntityList[i]), static_cast<Player*>(EntityList[0]));
					battle.PrintBattle();
					battle.BattleMenu(game.curScreenState);
					//std::cout << '\n' << game.curScreenState;
					//Battle over
					if (battle.stillbattle == false && EntityList[i]->hp <= 0) {
						loadingScrn();
						_running = false;
						if (_enemyThread.joinable()) {
							_enemyThread.join();
						}
						system("cls");
						for (int i = 0; i < 2; i++) {
							int randDrop = rand() % game.itemList.size();
							Consumables* consumable;
							consumable = new Consumables(game.itemList[randDrop].itemType, game.itemList[randDrop].itemID);
							player.playerInventory.consumableStorage.push_back(consumable);
							std::cout << "\nYou obtained " << consumable->name << '!';
							Sleep(1000);
						}
						game.curScreenState = MAP_RENDER;
						for (int f = 0; f < EnemyList.size(); f++) {
							if (EnemyList[f]->hp <= 0) {
								EnemyList.erase(EnemyList.begin() + f);
							}
						}
						delete EntityList[i];
						EntityList.erase(EntityList.begin() + i);

						size--;

						//start new enemy thread
						_running = true;
						_enemyThread = std::thread(enemyLoop, std::ref(EnemyList), &player);

						checkClearCondition(EntityList);

					}
				}

			}
			old_time = time(0);
		}
		//???????????????????????????? WHY DO WE HAVE TWO OF THESE????????

		if (game.curScreenState == LEARNATK) {
			game.learnScreen();
			old_time = time(0);

		}
		if (game.curScreenState == TRADING) {
			for (int i = 1; i < EntityList.size(); i++) {
				if ((EntityList[i]->x == player.xmov + player.x) && (EntityList[i]->y == player.ymov + player.y)) {
					trading.fetchPlayerData(static_cast<Player*>(EntityList[0]), static_cast<Trader*>(EntityList[i]));
					trading.TradeMenu(game.curScreenState);
					std::cout << '\n' << game.curScreenState;
				}
			}
			old_time = time(0);

		}
		//??????????????????
		if (game.curScreenState == INVENTORY) {
			playerInventory.inventorySelection();
			old_time = time(0);

		}
		if (game.curScreenState == EQUIPMENT) {
			equipment.equipmentSelection();
			old_time = time(0);
		}

		//std::cout << MapJson["TestMaps"].;


		//;
		Effects::ClearScreen();
	}
	_running = false;
	loadingScrn();
	if (_enemyThread.joinable()) { //check if can be joined or detached
		_enemyThread.join(); //be joined
	}
	//Assuming this is the clean up
	for (int i = 0; i < roomList.size(); i++) {
		for (int f = 0; f < roomList[i]->entityRoomSave.size(); f++) {
			if (dynamic_cast<Trader*>(roomList[i]->entityRoomSave[f]) != nullptr) {
				for (int r = 0; r < (dynamic_cast<Trader*>(roomList[i]->entityRoomSave[f]))->traderInventory.consumableStorage.size(); r++) {
					delete (dynamic_cast<Trader*>(roomList[i]->entityRoomSave[f]))->traderInventory.consumableStorage[r];
				}
				for (int r = 0; r < (dynamic_cast<Trader*>(roomList[i]->entityRoomSave[f]))->traderInventory.weaponStorage.size(); r++) {
					delete (dynamic_cast<Trader*>(roomList[i]->entityRoomSave[f]))->traderInventory.weaponStorage[r];
				}
				(dynamic_cast<Trader*>(roomList[i]->entityRoomSave[f]))->traderInventory.consumableStorage.clear();
				(dynamic_cast<Trader*>(roomList[i]->entityRoomSave[f]))->traderInventory.weaponStorage.clear();
			}
			delete roomList[i]->entityRoomSave[f];
		}
		roomList[i]->entityRoomSave.clear();
		delete roomList[i];
		
	}
	roomList.clear();
	for (int i = 0; i < player.playerInventory.consumableStorage.size(); i++) {
		delete player.playerInventory.consumableStorage[i];
	}
	//for (int i = 0; i < player.playerInventory.weaponStorage.size(); i++) {
	//	delete player.playerInventory.weaponStorage[i];
	//}

	for (int i = 0; i < weaponsList.size(); i++) {
		delete weaponsList[i];
	}
	EnemyList.clear();
	weaponsList.clear();
	player.playerInventory.consumableStorage.clear();
	player.playerInventory.weaponStorage.clear();




	system("cls");
	//if ((xpos + xmov < COLUMNS) && (ypos + ymov < ROWS) && (xpos + xmov >= 0) && (ypos + ymov >= 0)) {

	//_CrtDumpMemoryLeaks();
	return 0;
}
