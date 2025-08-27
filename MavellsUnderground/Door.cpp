#include "Door.h"

void Door::interact(){
	if(alive){
		icon = '=';
		updatePos(x, y);
		desc = "The way out.Blocked     ";
	}
	else{
		desc = "Not very blocked anymore";
		icon = ' ';
		updatePos(x, y);
	}
}