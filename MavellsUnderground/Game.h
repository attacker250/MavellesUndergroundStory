#pragma once
#include <string>
#include <vector>

class Game {
public:
    enum mapDimensions {
        ROWS = 13,
        COLUMNS = 40
    };
    enum ScreenState {
        MAP_RENDER,
        BATTLE,
        INVENTORY,
        CUTSCENE,
        TRADING,
        MENU,
		LEARNATK,

        MAXSCREENSTATE,
    };
    enum gameRooms {
        SECTORS = 3,
        ROOMS = 7
    };
    const static char roomCount = 2;
	const static int atkListSize = 3;
	static std::string atkList[atkListSize];
    static std::string atkLearn;

    bool testNew = false;

    static int battleHp;
    char getPos(int xpos, int ypos);
    void LoadMap(std::string Room, std::string Map);
    void MapEdit(int xpos, int ypos, char changeto);
    void typewriter(std::string& text, int delay, int maxChar);
    void AttackList();
    void ItemList();
    void Battle();
    void PrintBattle();
    void BattleMenu(int& curScreenState);
    void EnemyTurn();
    void learnScreen();
    void resetRooms();
    void PrintTrade();
    void TradeMenu();
    void TradeSystem();
    void checkMap();

    struct EntityArray {
        int x;
        int y;
        char icon;
        std::string hi;
    };

    static char mapData[ROWS][COLUMNS];
    static char mapObjects[SECTORS][ROOMS][ROWS][COLUMNS];
    static bool enteredRm[SECTORS][ROOMS];
    static int curScreenState;



    //Game() {
    //    for (int i = 0; i < atkListSize; i++) {
    //        atkList[i] = " ";
    //    }
    //}

};