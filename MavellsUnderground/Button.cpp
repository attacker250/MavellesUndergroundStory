#include "Button.h"
int Button::maxId = 0;

Button::Button(){
	icon = '-';
	maxId++;
	id = maxId;
}
Button::~Button(){
	maxId--;
}

//add button array sequence in player.
//Get button active status in entity list
void Button::interact(){
	active = !active;
	if(active){
        icon = '+';
	}
	else{	
		icon = '-';
	}
	updatePos(x, y);
}


 