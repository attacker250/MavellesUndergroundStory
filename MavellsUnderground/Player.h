#pragma once
#include "Entity.h"
#include <vector>
#include <string>
#include "Inventory.h"

#include "Consumables.h"





class Player: public Entity
{
public:
	//store name of items as string then access the item json data

	const static int maxHp = 50;
	static int hp;
	int xmov = 0;
	int ymov = 0;
	const int maxInvSize = 5;
	static int dmgModifier;
	static Inventory playerInventory;
	static std::vector<std::string> atkList;
	//bool inCombat = false;

	bool move() override;
	void learnAtk(std::string atkName);
	void consumeItem(std::string typeItem, int effectiveness, int itemIndex);
	Player() {
		icon = 'P';
		atkList.push_back("TestAttack1");
		playerInventory.coins = 100;

	}
};

