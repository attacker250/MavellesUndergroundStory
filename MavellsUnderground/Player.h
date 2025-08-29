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

	const static int maxHp = 300;
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
	static void consumeItem(int itemIndex);

	Player() {
		icon = 'P';
		playerInventory.addWeapon("Rock");
		Player::playerInventory.weaponStorage[0]->inUse = true;
		Player::playerInventory.weaponStorage[0]->setPlayerAttacks();
		playerInventory.coins = 100;

	}
};

