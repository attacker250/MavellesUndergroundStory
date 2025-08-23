#pragma once

#include <string>
#include "Game.h"
#include <vector>

class Entity: public Game
{
public:
	enum portraitDimensions {
		WIDTH = 62,
		HEIGHT = 16
	};
	std::vector<std::string> portrait;
	int x = 0;
	int y = 0;
	int hp = 0;
	bool alive = true;
	std::string name = "none";
	std::string type = "none";
	char icon = ' ';
	void updatePos(int movetox, int movetoy);
	virtual bool move();
	void spawn(int spawnx, int spawny);
	virtual void interact();

	//const static int atkListSize = 4;
	std::vector<std::string> atkList;
	static std::string currentRoom;
	static std::string currentPlace;
	std::string RoomDestination;
	std::string lastDoor;
	int rmIndex = static_cast<int>(currentRoom[currentRoom.length() - 1]) - 49;
	int placeIndex = static_cast<int>(currentPlace[currentPlace.length() - 1]) - 49;
};

