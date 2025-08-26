#pragma once
#include "Weapon.h"

class Sword : public Weapon
{
public:
	void move1(Enemy* enemy) override;
	void move2(Enemy* enemy) override;
	void move3(Enemy* enemy) override;
	void move4(Enemy* enemy) override;
	void setPlayerAttacks() override;

	Sword() {
		inUse = true;
	}
};

