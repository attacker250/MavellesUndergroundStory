#include "Entity.h"

void Entity::updatePos(int movetox, int movetoy){
	mapData[y][x] = ' ';
	mapData[movetoy][movetox] = icon;
	y = movetoy;
	x = movetox;
}

bool Entity::move(){
	return false;
}

void Entity::interact() {}


void Entity::spawn(int xspawn, int yspawn){
	updatePos(xspawn, yspawn);

}