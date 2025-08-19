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
        MAXSCREENSTATE

    };
    char getPos(int xpos, int ypos);
    void LoadMap(std::string Room, std::string Map);
    //void LoadMap();
    void MapEdit(int xpos, int ypos, char changeto);

    struct EntityArray {
        int x;
        int y;
        char icon;
        std::string hi;
    };

    static char mapData[12][40];
    static int curScreenState;

};