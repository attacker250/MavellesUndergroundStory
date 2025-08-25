#include "Entity.h"
#include <iostream>

std::string Entity::currentRoom = "Room1";
std::string Entity::currentPlace = "Cave1";



//updates the position and icon of obj on board
void Entity::updatePos(int movetox, int movetoy){
	mapData[y][x] = ' ';
	mapData[movetoy][movetox] = icon;
	y = movetoy;
	x = movetox;
}
//to trigger movement overriden in child classes)
bool Entity::move(){
	return false;
}	

//to trigger interactions (overriden in child classes)
void Entity::interact() {
}


void Entity::spawn(int xspawn, int yspawn){
	mapData[yspawn][xspawn] = icon;
	x = xspawn;
	y = yspawn;

}