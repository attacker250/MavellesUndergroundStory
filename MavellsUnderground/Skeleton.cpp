#include "Skeleton.h"
#include "Player.h"
#include <iostream>
#include "Cutscenes.h"
#include "Effects.h"



Skeleton::Skeleton(){
	icon = 'S';
	desc = "Death";
}


void Skeleton::interact() {
	Cutscenes::key = "Skeleton";
	if (!firstInteraction) {
		Cutscenes::InteractionKey = "First";
		Cutscenes zoom;
		zoom.ZoomOut();
		curScreenState = CUTSCENE;
		while (!zoom.PlayScene())Effects::ClearScreen();
		system("cls");
		firstInteraction = true;
		curScreenState = MAP_RENDER;
	}


}
