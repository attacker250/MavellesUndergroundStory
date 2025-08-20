#include "Door.h"

void Door::interact(){
	if(alive){
		icon = '=';
		updatePos(x, y);
	}
	else{
		icon = ' ';
		updatePos(x, y);
	}

}