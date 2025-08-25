#pragma once
#include <iostream>
#include "Windows.h"
#include "conio.h"
#include "Effects.h"
#include "Game.h"
#include "Player.h"

class Trading : public Game
{

public:
    Player* PlayerData;
    void PrintTrade();
    void TradeMenu();
    void TradeSystem();
    void fetchPlayerData(Player* player);
};

