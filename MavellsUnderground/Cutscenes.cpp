#include "Cutscenes.h"
#include "Player.h"
#include <iostream>
#include "json.hpp"
#include <fstream>
#include "conio.h"

std::string Cutscenes::key;
int Cutscenes::InteractionNo;

void Cutscenes::startScene() {
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
