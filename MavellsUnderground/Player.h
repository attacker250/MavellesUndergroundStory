#pragma once
#include "Entity.h"
#include <vector>
#include <string>
#include "Inventory.h"



class Player: public Entity
{
public:
	//store name of items as string then access the item json data

	const int maxHp = 300;
	int hp = maxHp;
	int xmov = 0;
	int ymov = 0;
	const int maxInvSize = 5;
	static Inventory playerInventory;
	static std::string currentRoom;
	static std::string currentPlace;
	std::string RoomDestination;
	std::string lastDoor;

	bool move() override;
	void learnAtk(std::string atkName);
	
	Player() {
		icon = 'P';
		for (int i = 0; i < atkListSize; i++){
			atkList[i] = ' ';
		}
	}
};

