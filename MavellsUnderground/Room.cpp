#include "Room.h"
#include "Game.h"
#include <iostream>
#include <random>
#include <ctime>


Room::Room(std::string Map, std::string Room) {
	srand(time(0));
	room = Room;
	place = Map;
	std::ifstream fMapdata("MapData/MapData.json");
	auto MapJson = nlohmann::json::parse(fMapdata);
	int rmCatalogue = static_cast<int>(Room[Room.length() - 1]) - 49;
	int mapCatalogue = static_cast<int>(Map[Map.length() - 1]) - 49;

	for (int i = 0; i < ROWS; i++) {
		for (int j = 0; j < COLUMNS; j++) {
			//roomData[i][j] = MapJson[Map][Room]["Map"][i].get<std::string>()[j];
			roomData[i][j] = MapJson[Map][Room]["Map"][i].get<std::string>()[j];
		}
	}
	for (int f = 0; f < MapJson[Map][Room]["EnemyCount"]; f++) {
		int randX = rand() % COLUMNS;
		int randY = rand() % ROWS;
		if (roomData[randY][randX] == ' ') {
			roomData[randY][randX] = 'E';
		}
		else {
			f--;
		}

	}
}

//stores and saves the entities on the current screen into the room obj
void Room::importEntityList(std::vector<Entity*> &entityList)
{
	entityRoomSave.clear();
	for (int i = 0; i < entityList.size(); i++) {
		entityRoomSave.push_back(entityList[i]);
	}

}
//saves the map layout into the room obj
void Room::roomSaveLayout(char roomLayout[ROWS][COLUMNS]) {
	for (int i = 0; i < ROWS; i++) {
		for (int f = 0; f < COLUMNS; f++) {
			if (roomLayout[i][f] != 'P') {
				roomData[i][f] = roomLayout[i][f];
			}
			else {
				roomData[i][f] = ' ';
			}
		}
	}
}

std::vector<Entity*> Room::returnEntities()
{
	return entityRoomSave;
}
