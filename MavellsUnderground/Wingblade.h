#pragma once
#include "Weapon.h"
#include "Player.h"

class Wingblade : public Weapon
{
public:
	void move1(Enemy* enemy) override;
	void move2(Enemy* enemy) override;
	void move3(Enemy* enemy) override;
	void move4(Enemy* enemy) override;
	void setPlayerAttacks() override;

	Wingblade() {
		name = "Wingblade";
		description = "A pair of wings with serrated edges";
	}
};

