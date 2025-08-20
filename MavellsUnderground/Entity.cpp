#include "Entity.h"
#include <iostream>

std::string Entity::currentRoom = "Room1";
std::string Entity::currentPlace = "Cave1";

void Entity::updatePos(int movetox, int movetoy){
	
	int currRmNum = static_cast<int>(currentRoom[currentRoom.length() - 1] - 49);
	int currPlaceNum = static_cast<int>(currentPlace[currentPlace.length() - 1] - 49);
	mapObjects[currPlaceNum][currRmNum][y][x] = ' ';
	mapData[y][x] = ' ';
	if (icon != 'P') {
		if (icon != ' ') {
			mapObjects[currPlaceNum][currRmNum][movetoy][movetox] = icon;
		}
		else {
			mapObjects[currPlaceNum][currRmNum][movetoy][movetox] = 'o';
		}
	}
	
	mapData[movetoy][movetox] = icon;
	y = movetoy;
	x = movetox;
}

bool Entity::move(){
	return false;
}	

void Entity::interact() {
	//std::cout << "Base";
}


void Entity::spawn(int xspawn, int yspawn){
	mapData[yspawn][xspawn] = icon;
	x = xspawn;
	y = yspawn;

}