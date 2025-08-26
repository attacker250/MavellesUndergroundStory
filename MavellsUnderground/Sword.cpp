#include "Sword.h"
#include "Player.h"


void Sword::move1(Enemy* enemy)
{
	enemy->hp -= 100;
	std::cout << "HIT";
}

void Sword::move2(Enemy* enemy)
{
	enemy->hp -= 50;
	std::cout << "BONK!";
}

void Sword::move3(Enemy* enemy)
{
	enemy->hp -= 30;
	std::cout << "KAPOW!!!";
}

void Sword::move4(Enemy* enemy)
{
	enemy->hp -= 40;
	std::cout << "SMACK!";
}

void Sword::setPlayerAttacks()
{
	Player::atkList.clear();
	Player::atkList.push_back("hit");
	Player::atkList.push_back("bonk");
	Player::atkList.push_back("kapow");
	Player::atkList.push_back("smack");
}
