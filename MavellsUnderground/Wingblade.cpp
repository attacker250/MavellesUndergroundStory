#include "Wingblade.h"

int Wingblade::move1(Enemy* enemy)
{
	//enemy->hp -= 30;
	std::cout << "Wingslash";
	return 30;
}

int Wingblade::move2(Enemy* enemy)
{
	//enemy->hp -= 20;
	std::cout << "Air cutter";
	return 20;
}

int Wingblade::move3(Enemy* enemy)
{
	//enemy->hp -= 50;
	std::cout << "Slash";
	return 50;
}

int Wingblade::move4(Enemy* enemy)
{
	//enemy->hp - 10;
	std::cout << "Air stuff idk";
	return 10;
}

void Wingblade::setPlayerAttacks()
{
    Player::atkList.clear();
    Player::atkList.push_back("Wingslash");
    Player::atkList.push_back("air cutter");
    Player::atkList.push_back("slash");
    Player::atkList.push_back("air stuff idk");
}
