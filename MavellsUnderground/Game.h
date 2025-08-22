#pragma once
#include <string>
#include <vector>
#include "Effects.h"

class Game : public Effects
{
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
	

    bool testNew = false;

	void resetRooms();
    char getPos(int xpos, int ypos);
    void LoadMap(std::string Map, std::string room, char roomData[ROWS][COLUMNS], bool ifNew);
    void MapEdit(int xpos, int ypos, char changeto);
    
    void learnScreen();
    
    void checkMap();

    struct EntityArray {
        int x;
        int y;
        char icon;
        std::string hi;
    };

    static char mapData[ROWS][COLUMNS];
    static bool enteredRm[SECTORS][ROOMS];
    static int curScreenState;



    //Game() {
    //    for (int i = 0; i < atkListSize; i++) {
    //        atkList[i] = " ";
    //    }
    //}

};