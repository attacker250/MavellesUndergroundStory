#pragma once
#include <iostream>
#include "Windows.h"
#include "conio.h"
#include "Effects.h"
#include "Game.h"
#include "Player.h"
#include <fstream>
#include "json.hpp"
#include "Trader.h"

class Trading : public Game
{

public:
    Player* PlayerData;
    Trader* TraderData;
    void PrintTrade();
    void TradeMenu(int& curScreenState);
    void TradeSystem();
    void fetchPlayerData(Player* player, Trader* trader);
};

