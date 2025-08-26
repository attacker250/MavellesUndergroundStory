#include "Sword.h"
#include "Player.h"


void Sword::move1(Enemy* enemy)
{
	enemy->hp - 100;
	Player::hp += 10;
	std::cout << "HIT";
}

void Sword::move2(Enemy* enemy)
{
}

void Sword::move3(Enemy* enemy)
{
}

void Sword::move4(Enemy* enemy)
{
}

void Sword::setPlayerAttacks()
{
	Player::atkList.clear();
	Player::atkList.push_back("TestAttack1");
}
