#include "Sword.h"
#include "Player.h"


int Sword::move1(Enemy* enemy)
{
	//enemy->hp -= 100;
	std::cout << "HIT";
	return 100;
}

int Sword::move2(Enemy* enemy)
{
	//enemy->hp -= 50;
	std::cout << "BONK!";
	return 50;
}

int Sword::move3(Enemy* enemy)
{
	//enemy->hp -= 30;
	std::cout << "KAPOW!!!";
	return 30;
}

int Sword::move4(Enemy* enemy)
{
	//enemy->hp -= 40;
	std::cout << "SMACK!";
	return 40;
}

void Sword::setPlayerAttacks()
{
	Player::atkList.clear();
	Player::atkList.push_back("hit");
	Player::atkList.push_back("bonk");
	Player::atkList.push_back("kapow");
	Player::atkList.push_back("smack");
}
