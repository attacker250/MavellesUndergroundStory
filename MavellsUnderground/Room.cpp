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
			roomData[i][j] = MapJson[Map][Room]["Map"][i].get<std::string>()[j];
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
