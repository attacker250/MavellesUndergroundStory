#include "Cutscenes.h"
#include "Player.h"
#include <iostream>
#include "json.hpp"
#include <fstream>
#include "conio.h"

std::string Cutscenes::key;
int Cutscenes::InteractionNo;

void Cutscenes::PlayScene() {
	std::ifstream fCutscenedata("Animations/Cutscenes.json");
	auto CutsceneJson = nlohmann::json::parse(fCutscenedata);
	std::string currentRoom = Player::currentRoom;
	std::string currentPlace = Player::currentPlace;

	std::string image;

	if (i < CutsceneJson[key][currentPlace][currentRoom][SceneNo][InteractionNo].size()-1) {
		i++;	
	}
	else {
		i = 0;
	}
	std::cout << CutsceneJson[key][currentPlace][currentRoom][InteractionNo][SceneNo][i].get<std::string>();
	Sleep(10);

	//if (_kbhit) {
	//	char input = _getch();
	//	if (input == '\n') {
	//		SceneNo++;
	//	}
	//}



}

std::string Cutscenes::AsciiPrint(std::string input) {
    std::ifstream fFontdata("Animations/Fonts.json");
    auto FontJson = nlohmann::json::parse(fFontdata);

    std::string words;
    std::vector<std::string>split;

    std::string store;
    //factor line breaks
    for (int i = 0; i < input.size(); i++) {
        //checks if theres a line break
        if (input[i] == '\n') {
            //if so, first push back what the string stored and reset it to be empty
            split.push_back(store);
            store = "";
        }
        else {
            //otherwise, add the current letter thats being checked into the store
            store += input[i];
        }
    }
    //push back the last set of letters
    split.push_back(store);

    //run a loop for all the texts
    for (int a = 0; a < split.size(); a++) {
        for (int d = 0; d < FontJson["Default"]["b"].size(); d++) {
            //runs a loop for height of all letters
            for (int i = 0; i < split[a].size(); i++) {
                //add the row by row letters side by side   
                std::string converter;
                converter += split[a][i];
                if (FontJson["Default"].contains(converter)) {
                    words += FontJson["Default"][converter][d];
                }

            }
            words += "\n";
        }
        words += "\n";
    }
    return words;
}
