#include "Button.h"

Button::Button(){
	icon = '-';
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


