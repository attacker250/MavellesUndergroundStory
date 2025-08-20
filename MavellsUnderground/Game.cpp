#include "Game.h"
#include "json.hpp"
#include <fstream>
#include "conio.h"
#include <iostream>
#include "Windows.h"
#include <string>

char Game::mapData[ROWS][COLUMNS];

int Game::curScreenState = MAP_RENDER;
int Game::battleHp = 0;

std::string Game::atkList[atkListSize];
std::string Game::atkLearn;

char Game::mapObjects[roomCount][ROWS][COLUMNS];
bool Game::enteredRoom[SECTORS][ROOMS];
//typewriter effect for dialogue
void Game::typewriter(std::string& text, int delay) {
	int textspeed = delay;

	for (char c : text) {
		Beep(500, 100);
		std::cout << c;
		std::cout.flush();
		Sleep(textspeed);

		if (GetAsyncKeyState('k') & 0x8000) {
			textspeed = 2;
		}
		else {
			textspeed = delay;
		}
	}

}

void Game::PrintBattle() { //to be replaced with enemy ASCII
	const int width = 41;
	const int height = 12;
	const int inner = 39;
	for (int i = 0; i < 41; i++) {
		std::cout << '_';
	}
	std::cout << "\n";
	for (int i = 0; i < height; i++) {
		std::cout << '|';
		for (int j = 0; j < inner; j++) {
			std::cout << ' ';
		}
		std::cout << '|' << std::endl;
	}
	for (int i = 0; i < width; i++) {
		std::cout << '-';
	}
}

void Game::Battle() {
 //to be changed to enemy class hp
	std::string WinMessage = "You Won!";
	bool stillbattle = true;
	if (battleHp <= 0) {
		stillbattle = false;
	}
	if (stillbattle == true) {
		std::cout << "\n";
		std::cout << "Enemy's HP:" << battleHp << std::endl;
		std::cout << "[1] Attack 1" << std::endl;
		std::cout << "[2] Items" << std::endl;
		std::cout << "[3] Run 1" << std::endl;
		std::cout << "[4] Test out learn attack" << std::endl;
	}
	else if (stillbattle == false) {
		typewriter(WinMessage, 40);
		return;
	}

}

void Game::ItemList() {
	std::cout << "\n";
	std::cout << "[1] Item 1" << std::endl;
	std::cout << "[2] Item 2" << std::endl;
	std::cout << "[3] Item 3" << std::endl;
	std::cout << "[4] Back" << std::endl;

	char getbtn = static_cast<char>(_getch());
	if (getbtn) {
		Beep(1080, 300);
		switch (getbtn) {
		case '1':
			std::cout << "use item 1" << std::endl;
			Sleep(500);
			system("cls");
			PrintBattle();
			break;
		case '2':
			std::cout << "use item 2" << std::endl;
			Sleep(500);
			system("cls");
			PrintBattle();
			break;
		case '3':
			std::cout << "use item 3" << std::endl;
			Sleep(500);
			system("cls");
			PrintBattle();
			break;
		case '4':
			system("cls");
			PrintBattle();
			return;
		}
	}
}

void Game::AttackList() {
	std::cout << "\n";
	for (int i = 0; i < atkListSize; i++) {
		std::cout << "[" << i + 1 << "]" << atkList[i] << std::endl;
	}

	char getbtn = static_cast<char>(_getch());
	if (getbtn) {
		Beep(1080, 300);
		switch (getbtn) {
		case '1':
			std::cout << "You chose Fire attack!" << std::endl;
			Sleep(500);
			system("cls");
			PrintBattle();
			break;
		case '2':
			std::cout << "You chose Water attack!" << std::endl;
			Sleep(500);
			system("cls");
			PrintBattle();
			break;
		case '3':
			std::cout << "You chose Grass attack!" << std::endl;
			Sleep(500);
			system("cls");
			PrintBattle();
			break;
		case '4':
			system("cls");
			PrintBattle();
			return;
		}
	}

}



char Game::getPos(int x, int y){
	return mapData[y][x];

}


void Game::MapEdit(int xpos, int ypos, char changeto){


}

void Game::LoadMap(std::string Map, std::string Room){
    std::ifstream fMapdata("MapData/MapData.json");
    auto MapJson = nlohmann::json::parse(fMapdata);
	//int rmCatalgoue = static_cast<int>(Room[Room.length() - 1]) - 48;
//	if (enteredRm == false) {
		for (int i = 0; i < ROWS; i++) {
			for (int j = 0; j < COLUMNS; j++) {
				mapData[i][j] = MapJson[Map][Room]["Map"][i].get<std::string>()[j];
			}
		}
		
	//}
}

void Game::BattleMenu(int& curScreenState) {
	bool isRunning = true;
	//	while (isRunning) {
	Battle();
	char getbtn = static_cast<char>(_getch());
	std::string Escape = "You ran away successfully!";
	if (getbtn) {
		Beep(1080, 300);
		switch (getbtn) {
		case '1':
			system("cls");
			PrintBattle();
			AttackList();
			break;
		case '2':
			system("cls");
			PrintBattle();
			ItemList();
			break;
		case '3':
			std::cout << "You selected to run!" << std::endl;
			Sleep(300);
			typewriter(Escape, 40);
			Sleep(300);
			curScreenState = 0;
			system("cls");
			break;
		default:
			std::cout << "Invalid choice!" << std::endl;
			break;

		}
	}
}

void Game::learnScreen(){
	int fullAmt = 0;
	for (int i = 0; i < atkListSize; i++) {
		if (atkList[i] == " ") {
			atkList[i] = atkLearn;
			std::cout << "You have learned " << atkLearn << '\n';
			break;
		}
		else {
			fullAmt++;
		}
	}
	int moveForget = 0;
	if (fullAmt == atkListSize) {
		std::cout << '\n' << "Which move do you want to forget? " << '\n';
		for (int i = 0; i < atkListSize; i++) {
			std::cout << "[" << i + 1 << "]" << atkList[i] << std::endl;
		}
		std::cin >> moveForget;
	}
	atkList[moveForget - 1] = atkLearn;
	Sleep(3000);
	curScreenState = MAP_RENDER;

}