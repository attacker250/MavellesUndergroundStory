#pragma once

#include <string>
#include "Game.h"

class Entity: public Game
{
public:
	int x = 0;
	int y = 0;
	int hp = 0;
	bool alive = true;
	std::string type = "none";
	char icon = ' ';
	void updatePos(int movetox, int movetoy);
	virtual bool move();
	void spawn(int spawnx, int spawny);
	virtual void interact();

	static std::string currentRoom;
	static std::string currentPlace;
	std::string RoomDestination;
	std::string lastDoor;
	int rmIndex = static_cast<int>(currentRoom[currentRoom.length() - 1]) - 49;
	int placeIndex = static_cast<int>(currentPlace[currentPlace.length() - 1]) - 49;
};

