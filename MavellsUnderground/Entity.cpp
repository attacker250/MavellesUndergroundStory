#include "Entity.h"

void Entity::updatePos(int movetox, int movetoy, char mapData[12][40]){
	mapData[y][x] = ' ';
	mapData[movetoy][movetox] = icon;
	y = movetoy;
	x = movetox;
}

void Entity::move(){}

void Entity::spawn(int xspawn, int yspawn, char mapData[12][40]){
	updatePos(xspawn, yspawn,mapData);

}