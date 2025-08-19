#pragma once
#include "Entity.h"
class TestEnemyClass : public Entity
{
public:
	void interact() override;
	TestEnemyClass(){
		icon = 'E';
	}
};

