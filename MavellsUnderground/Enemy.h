#pragma once
#include "Entity.h"

class Enemy : public Entity
{
public:
	void interact() override;
	Enemy();
};

