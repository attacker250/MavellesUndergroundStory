#pragma once
#include "Weapon.h"
#include "Player.h"

class Wingblade : public Weapon
{
public:
	int move1(Enemy* enemy) override;
	int move2(Enemy* enemy) override;
	int move3(Enemy* enemy) override;
	int move4(Enemy* enemy) override;
	void setPlayerAttacks() override;

	Wingblade() {
		itemValue = 60;
		name = "Wingblade";
		description = "A pair of wings with serrated edges";
		type = "Grass";
	}
};

