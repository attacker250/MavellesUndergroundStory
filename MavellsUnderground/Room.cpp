#include "Room.h"
#include "Game.h"
#include <iostream>

Room::Room(std::string Map, std::string Room) {
	room = Room;
	place = Map;
	std::ifstream fMapdata("MapData/MapData.json");
	auto MapJson = nlohmann::json::parse(fMapdata);
	int rmCatalogue = static_cast<int>(Room[Room.length() - 1]) - 49;
	int mapCatalogue = static_cast<int>(Map[Map.length() - 1]) - 49;

	for (int i = 0; i < ROWS; i++) {
		for (int j = 0; j < COLUMNS; j++) {
			//std::cout << Room[Room.length() - 1];
			//mapObjects[mapCatalogue][rmCatalogue][i][j] = MapJson[Map][Room]["Map"][i].get<std::string>()[j];

			roomData[i][j] = MapJson[Map][Room]["Map"][i].get<std::string>()[j];
			std::cout << roomData[i][j];
		}
		std::cout << '\n';
	}
	system("cls");

}

void Room::importEntityList(std::vector<Entity*> &entityList)
{
	entityRoomSave.clear();
	for (int i = 1; i < entityList.size(); i++) {
		
		entityRoomSave.push_back(entityList[i]);
	}
	std::cout << entityRoomSave.size();
}

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
