#include "Entity.h"
#include <iostream>


void Entity::updatePos(int movetox, int movetoy){
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