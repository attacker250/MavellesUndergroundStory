#pragma once
#include "Weapon.h"

class Spear : public Weapon
{
public:
	void move1(Enemy* enemy) override;
	void move2(Enemy* enemy) override;
	void move3(Enemy* enemy) override;
	void move4(Enemy* enemy) override;
	void setPlayerAttacks() override;

	Spear() {
		name = "Spear";
		description = "A cold-bloodstained spear";
	}
};

