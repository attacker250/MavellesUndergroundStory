#include "Spear.h"
#include "Player.h"

void Spear::move1(Enemy* enemy)
{
    enemy->hp -= 100;
    std::cout << "Poke";
}

void Spear::move2(Enemy* enemy)
{
    enemy->hp -= 50;
    std::cout << "thrust";
}

void Spear::move3(Enemy* enemy)
{
    enemy->hp -= 30;
    std::cout << "pointy!";
}

void Spear::move4(Enemy* enemy)
{
    enemy->hp -= 40;
    std::cout << "Spear Hit";
}

void Spear::setPlayerAttacks()
{
    Player::atkList.clear();
    Player::atkList.push_back("poke");
    Player::atkList.push_back("thrust");
    Player::atkList.push_back("pointy");
    Player::atkList.push_back("spear hit");
}
