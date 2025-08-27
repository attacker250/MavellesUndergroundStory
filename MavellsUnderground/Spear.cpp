#include "Spear.h"
#include "Player.h"

int Spear::move1(Enemy* enemy)
{
    //enemy->hp -= 100;
    std::cout << "Poke";
    return 11100;
}

int Spear::move2(Enemy* enemy)
{
    //enemy->hp -= 50;
    std::cout << "thrust";
    return 50;
}

int Spear::move3(Enemy* enemy)
{
//    enemy->hp -= 30;
    std::cout << "pointy!";
    return 30;
}

int Spear::move4(Enemy* enemy)
{
  //  enemy->hp -= 40;
    std::cout << "Spear Hit";
    return 40;
}

void Spear::setPlayerAttacks()
{
    Player::atkList.clear();
    Player::atkList.push_back("poke");
    Player::atkList.push_back("thrust");
    Player::atkList.push_back("pointy");
    Player::atkList.push_back("spear hit");
}
