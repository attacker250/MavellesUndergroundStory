#include "Entity.h"
#include <iostream>

std::string Entity::currentRoom;
std::string Entity::currentPlace;

void Entity::updatePos(int movetox, int movetoy){
	mapData[y][x] = ' ';
//	if (static_cast<int>(Room[Room.length() - 1]) - 48)
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