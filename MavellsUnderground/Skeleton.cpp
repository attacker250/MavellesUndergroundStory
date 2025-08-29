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
		cutscenes.ZoomOut();
		curScreenState = CUTSCENE;
		while (!cutscenes.PlayScene())Effects::ClearScreen();
		system("cls");
		firstInteraction = true;
		curScreenState = MAP_RENDER;
	}
	else {
		Cutscenes::InteractionKey = "Other";
		cutscenes.ZoomOut();
		curScreenState = CUTSCENE;
		while (!cutscenes.PlayScene())Effects::ClearScreen();
		system("cls");
		firstInteraction = true;
		curScreenState = MAP_RENDER;
	}


}
