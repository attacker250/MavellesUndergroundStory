#include "Padlock.h"
#include "Player.h"
#include <iostream>
#include "Cutscenes.h"
#include "Effects.h"

Padlock::Padlock() {
	icon = '!';
	desc = "A barrel";
	type = "Padlock";
}


void Padlock::interact() {
	system("cls");
	std::ifstream fPuzzledata("ButtonData/PuzzleData.json");
	nlohmann::json PuzzleJson = nlohmann::json::parse(fPuzzledata);
	if (secret) {
		std::string pass;
		for (int i = 0; i < PuzzleJson[currentPlace][currentRoom]["Secret"]["Puzzle"].size(); i++) {
			std::cout << PuzzleJson[currentPlace][currentRoom]["Secret"]["Puzzle"][i].get<std::string>() << "\n";
		}


		std::cout << "Hint: " << PuzzleJson[currentPlace][currentRoom]["Secret"]["Hint"] << "\n";
		std::cout << "Solve the puzzle and input your answer:";
		std::cin >> pass;

		if (pass == PuzzleJson[currentPlace][currentRoom]["Secret"]["Password"]) {
			alive = false;
			icon = ' ';
		}
	}
	else {
		int pass;
		for (int i = 0; i < PuzzleJson[currentPlace][currentRoom]["Normal"]["Puzzle"].size(); i++) {
			std::cout << PuzzleJson[currentPlace][currentRoom]["Normal"]["Puzzle"][i].get<std::string>() << "\n";
		}


		std::cout << "Hint: " <<PuzzleJson[currentPlace][currentRoom]["Normal"]["Hint"] << "\n";
		std::cout << "Solve the puzzle and input your answer:";
		std::cin >> pass;

		if (pass == PuzzleJson[currentPlace][currentRoom]["Normal"]["Password"]) {
			alive = false;
			icon = ' ';
		}

	}
	system("cls");

}