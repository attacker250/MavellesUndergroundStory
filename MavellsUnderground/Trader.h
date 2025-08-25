#pragma once
#include "Entity.h"
#include <fstream>
#include "json.hpp"
#include "Trader.h"
#include "Entity.h"


class Trader : public Entity
{

public:
	Trader();
	void interact();
};

