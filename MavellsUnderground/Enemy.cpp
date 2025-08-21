#include "Enemy.h"


//SET ENEMY HP FOR BATTLE RAHHH
void Enemy::interact() {
	curScreenState = BATTLE;
	battleHp = hp;
}