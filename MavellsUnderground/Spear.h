#pragma once
#include "Weapon.h"

class Spear : public Weapon
{
public:
	int move1(Enemy* enemy) override;
	int move2(Enemy* enemy) override;
	int move3(Enemy* enemy) override;
	int move4(Enemy* enemy) override;
	void setPlayerAttacks() override;

	Spear() {
		name = "Spear";
		description = "A cold-bloodstained spear";
		itemValue = 30;
		type = "Fire";
	}
};

