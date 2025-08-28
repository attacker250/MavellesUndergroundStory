#pragma once
#include <string>
#include <vector>
#include "Consumables.h"
#include "Effects.h"
#include <thread>


class Game : public Effects
{
public:
    struct itemPath {
        std::string itemType = "";
        int itemID = 0;
    };
    static bool gameQuit;

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
        EQUIPMENT,
        MAIN_MENU,

        MAXSCREENSTATE,
    };
    enum gameRooms {
        SECTORS = 3,
        ROOMS = 7
    };
    const static char roomCount = 2;
	
    std::vector<itemPath> itemList;
    bool testNew = false;

    void resetRooms();
    char getPos(int xpos, int ypos);
    void LoadMap(std::string Map, std::string room, char roomData[ROWS][COLUMNS], bool ifNew);
    void MapEdit(int xpos, int ypos, char changeto);
    void mainMenuScrn();
   // void getWeaponList(std::vector<Weapon*> weaponsList);
    Game();
    
    void learnScreen();
    
    Consumables returnItem(std::string type, int itemID);

    void checkMap();

    struct EntityArray {
        int x;
        int y;
        char icon;
        std::string hi;
    };

    //Thoughts
    static std::string key;
    static std::string InteractionKey;

    static char mapData[ROWS][COLUMNS];
    static bool enteredRm[SECTORS][ROOMS];
    static int curScreenState;



    //Game() {
    //    for (int i = 0; i < atkListSize; i++) {
    //        atkList[i] = " ";
    //    }
    //}

};