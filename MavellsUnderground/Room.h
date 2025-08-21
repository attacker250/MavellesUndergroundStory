#pragma once
#include <fstream>
#include "json.hpp"
//Misc
#include <vector>
#include <string>
#include <windows.h>
#include "Entity.h"
#include <string>

class Room
{
public:
	enum mapDimensions {
		ROWS = 13,
		COLUMNS = 40
	};
	char roomData[ROWS][COLUMNS];

	std::string place = "cave";
	std::string room = "room1";
	bool newRoom = true;

	std::vector<Entity*> entityRoomSave;
	Room(std::string Map, std::string Room);
	void importEntityList(std::vector<Entity*>& entityList);
	std::vector<Entity*> returnEntities();
	void roomSaveLayout(char roomLayout[ROWS][COLUMNS]);
};

