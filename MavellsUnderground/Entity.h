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

	
	//Position
	int x = 0;
	int y = 0;
	
	//Killed or not
	int hp = 0;
	bool alive = true;
	std::string name = "none";
	std::string type = "none";
	
	//For Legend
	std::string desc;

	//Screen Visual
	char icon = ' ';
	std::vector<std::string> portrait;

	//movment Funcs
	void updatePos(int movetox, int movetoy);
	virtual bool move();
	void spawn(int spawnx, int spawny);
	virtual void nextMove(int x, int y, int boardHeight, int boardWidth) {};
	
	//Interactions
	virtual void interact();

	//Enemy Attack List (??????)
	std::vector<std::string> atkList;
	
	//Room moving Data
	static std::string currentRoom;
	static std::string currentPlace;
	std::string RoomDestination;
	std::string lastDoor;
	int rmIndex = static_cast<int>(currentRoom[currentRoom.length() - 1]) - 49;
	int placeIndex = static_cast<int>(currentPlace[currentPlace.length() - 1]) - 49;

	//When enemy dies (Failsafe)
	~Entity() {
		icon = ' ';
		updatePos(x, y);	
	}
};

