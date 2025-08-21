#include "Room.h"
#include "Game.h"


Room::Room(std::string Map, std::string Room) {
	std::ifstream fMapdata("MapData/MapData.json");
	auto MapJson = nlohmann::json::parse(fMapdata);
	int rmCatalogue = static_cast<int>(Room[Room.length() - 1]) - 49;
	int mapCatalogue = static_cast<int>(Map[Map.length() - 1]) - 49;

	for (int i = 0; i < ROWS; i++) {
		for (int j = 0; j < COLUMNS; j++) {
			//std::cout << Room[Room.length() - 1];
			//mapObjects[mapCatalogue][rmCatalogue][i][j] = MapJson[Map][Room]["Map"][i].get<std::string>()[j];
			roomData[i][j] = MapJson[Map][Room]["Map"][i].get<std::string>()[j];
		}
	}

}

void Room::importEntityList(std::vector<Entity*> &entityList)
{
	entityRoomSave.clear();
	for (int i = 0; i < entityList.size(); i++) {
		entityRoomSave.push_back(entityList[i]);
	}
}

std::vector<Entity*> Room::returnEntities()
{
	return entityRoomSave;
}
