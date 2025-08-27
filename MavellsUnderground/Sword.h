#pragma once
#include "Weapon.h"

class Sword : public Weapon
{
public:
	int move1(Enemy* enemy) override;
	int move2(Enemy* enemy) override;
	int move3(Enemy* enemy) override;
	int move4(Enemy* enemy) override;
	void setPlayerAttacks() override;

	Sword() {
		inUse = true;
		name = "Sword";
		description = "A fine iron sword";
		type = "Grass";
	}
};

