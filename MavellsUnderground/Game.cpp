#include "Game.h"
#include "json.hpp"
#include <fstream>

char Game::mapData[ROWS][COLUMNS];
int Game::curScreenState = MAP_RENDER;


char Game::getPos(int x, int y)
{
	return mapData[y][x];

}


void Game::MapEdit(int xpos, int ypos, char changeto){


}

void Game::LoadMap(std::string Room, std::string Map){
    std::ifstream fMapdata("MapData/MapData.json");
    auto MapJson = nlohmann::json::parse(fMapdata);
        
    for (int i = 0; i < 12; i++) {
        for (int j = 0; j < 40; j++) {
            mapData[i][j] = MapJson[Room][Map]["Map"][i].get<std::string>()[j];
        }
    }
}
