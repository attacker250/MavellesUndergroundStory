#include "Entity.h"
#include <iostream>

std::string Entity::currentRoom;
std::string Entity::currentPlace;

void Entity::updatePos(int movetox, int movetoy){
	
	//int currRmNum = static_cast<int>(currentRoom[currentRoom.length() - 1] - 48);
	//int currPlaceNum = static_cast<int>(currentPlace[currentPlace.length() - 1] - 48);
	//if (icon != 'd') {
	//	mapObjects[currPlaceNum][currRmNum][y][x] = ' ';
	//	mapObjects[currPlaceNum][currRmNum][movetoy][movetox] = icon;
	//}
	mapData[y][x] = ' ';
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