#include "Wingblade.h"

void Wingblade::move1(Enemy* enemy)
{
	enemy->hp -= 30;
	std::cout << "Wingslash";
}

void Wingblade::move2(Enemy* enemy)
{
	enemy->hp -= 20;
	std::cout << "Air cutter";
}

void Wingblade::move3(Enemy* enemy)
{
	enemy->hp -= 50;
	std::cout << "Slash";
}

void Wingblade::move4(Enemy* enemy)
{
	enemy->hp - 10;
	std::cout << "Air stuff idk";
}

void Wingblade::setPlayerAttacks()
{
    Player::atkList.clear();
    Player::atkList.push_back("Wingslash");
    Player::atkList.push_back("air cutter");
    Player::atkList.push_back("slash");
    Player::atkList.push_back("air stuff idk");
}
