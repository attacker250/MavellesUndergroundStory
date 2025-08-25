#pragma once
#include <iostream>
#include "Windows.h"
#include "conio.h"
#include "Effects.h"
#include "Game.h"

class Trading : public Game
{

public:
    void PrintTrade();
    void TradeMenu();
    void TradeSystem();
};

