#pragma once
#include "Entity.h"
#include <vector>
#include <string>
#include "Inventory.h"
#include "Battle.h"
#include "Consumables.h"





class Player: public Entity
{
public:
	//store name of items as string then access the item json data

	const int maxHp = 300;
	int hp = maxHp;
	int xmov = 0;
	int ymov = 0;
	const int maxInvSize = 5;
	int dmgModifier = 0;
	static Inventory playerInventory;
	//bool inCombat = false;

	bool move() override;
	void learnAtk(std::string atkName);
	void consumeItem(std::string typeItem, int effectiveness, int itemIndex);
	Player() {
		icon = 'P';
		atkList.push_back("TestAttack1");
	}
};

