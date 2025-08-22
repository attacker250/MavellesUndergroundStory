#pragma once
#include "Entity.h"
#include <string>
#include <vector>

class Enemy : public Entity
{
public:
	std::vector<std::string> attacks;
	void interact() override;
	Enemy();
};

