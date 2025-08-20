#pragma once
#include <string>
#include <vector>

class Game {
public:
    enum mapDimensions {
        ROWS = 12,
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
	const static int atkListSize = 3;
	static std::string atkList[atkListSize];
    static std::string atkLearn;

    static int battleHp;
    char getPos(int xpos, int ypos);
    void LoadMap(std::string Room, std::string Map);
    void MapEdit(int xpos, int ypos, char changeto);
    void typewriter(std::string& text, int delay);
    void AttackList();
    void ItemList();
    void Battle();
    void PrintBoard();
    void BattleMenu(int& curScreenState);
    void learnScreen();

    struct EntityArray {
        int x;
        int y;
        char icon;
        std::string hi;
    };

    static char mapData[12][40];
    static int curScreenState;

};