#include "Barrel.h"
Barrel::Barrel() {
	icon = 'B';
}


void Barrel::interact() {
	curScreenState = BATTLE;
	//std::cout << "BARREL INTERACT";
}