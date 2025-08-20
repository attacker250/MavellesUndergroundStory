#include "Enemy.h"

void Enemy::interact() {
	curScreenState = BATTLE;
	battleHp = hp;
}