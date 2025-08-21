#include "Game.h"
#include "json.hpp"
#include <fstream>
#include "conio.h"
#include <iostream>
#include "Windows.h"
#include <string>
#include "Room.h"

char Game::mapData[ROWS][COLUMNS];

int Game::curScreenState = MAP_RENDER;
int Game::battleHp = 0;

std::string Game::atkList[atkListSize];
std::string Game::atkLearn;

//char Game::mapObjects[SECTORS][ROOMS][ROWS][COLUMNS];
bool Game::enteredRm[SECTORS][ROOMS];

//typewriter effect for dialogue
void Game::typewriter(std::string& text, int delay, int maxChar) {
	int charCount = 0;

	for (char c : text) {
		std::cout << c;
		std::cout.flush();


		if (GetAsyncKeyState('K') & 0x8000) {
			Sleep(2);
		}
		else {
			Sleep(delay);
			Beep(800, 40);
		}

		charCount++;

		if (charCount > maxChar && c == ' ') {
			std::cout << "\n";
			charCount = 0;
		}
		if (c == '.' || c == '!') {
			Sleep(1000);
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
		typewriter(WinMessage, 40, 50);
		return;
	}
}

//input enemy damage here
void Game::EnemyTurn()
{
	Sleep(300);
	int enemydmg = 50;
	std::string enemymssg = "\nThe enemy attacks! It dealt " + std::to_string(enemydmg) + " damage to you..."; //pass in enemydmg
	typewriter(enemymssg, 20, 50);
	Sleep(300);
	system("cls");
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
	std::cout << "[" << 4 << "]" << " Back" << std::endl;
	char getbtn = static_cast<char>(_getch());
	if (getbtn) {
		Beep(1080, 300);
		switch (getbtn) {
		case '1':
			std::cout << "You chose Fire attack!" << std::endl;
			Sleep(500);
			system("cls");
			PrintBattle();
			EnemyTurn();
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

//trading
void Game::PrintTrade(){
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

void Game::TradeSystem(){
	system("cls");
	PrintTrade();
	std::cout << "\n";
	for (int a = 1; a < 6; a++)
	{
		std::cout << '|';
		std::cout << '[' << a << ']';
		std::cout << "Test item";

		for (int j = 0; j < 27; j++)
		{
			std::cout << ' ';
		}

		std::cout << '|' << std::endl;
	}
	
	std::cout << '|' << '[' << 6 << ']';
	std::cout << "Back";
	for (int e = 0; e < 32; e++)
	{
		std::cout << ' ';
	}
	std::cout << '|';
	std::cout << "\n";
	
	for (int i = 0; i < 41; i++)
	{
		std::cout << '-';
	}

	char getbtn = static_cast<char>(_getch());
	switch (getbtn) {
	case '1':
		std::cout << "\nYou have selected item 1.";
		Sleep(2000);
		system("cls");
		PrintTrade();
		break;
	case '2':
		std::cout << "\nYou have selected item 2.";
		Sleep(2000);
		system("cls");
		PrintTrade();
		break;
	case '3':
		std::cout << "\nYou have selected item 3.";
		Sleep(2000);
		system("cls");
		PrintTrade();
		break;
	case '4':
		std::cout << "\nYou have selected item 4.";
		Sleep(2000);
		system("cls");
		PrintTrade();
		break;
	case '5':
		std::cout << "\nYou have selected item 5.";
		Sleep(2000);
		system("cls");
		PrintTrade();
		break;
	case '6':
		std::cout << "\nYou have selected Back.";
		system("cls");
		PrintTrade();
		return;
	}
}

void Game::checkMap()
{
	for (int i = 0; i < ROWS; i++) {
		for (int f = 0; f < COLUMNS; f++) {

			std::cout << mapData[i][f];


		}
		std::cout << '\n';
	}

	system("cls");
//	Sleep(1000);
}

void Game::TradeMenu(){
	PrintTrade();

	std::cout << "\n";
	std::cout << '|';
	std::cout << '[' << 1 << ']';
	std::cout << "Trade";
	for (int j = 0; j < 31; j++) {
		std::cout << ' ';
	}
	std::cout << '|' << std::endl;
	std::cout << '|';
	std::cout << '[' << 2 << ']';
	std::cout << "Talk";
	for (int j = 0; j < 32; j++) {
		std::cout << ' ';
	}
	std::cout << '|' << std::endl;

	std::cout << '|';
	std::cout << '[' << 3 << ']';
	std::cout << "Back";
	for (int e = 0; e < 32; e++)
	{
		std::cout << ' ';

	}
	std::cout << '|';
	std::cout << "\n";


	for (int i = 0; i < 41; i++) {
		std::cout << '-';
	}
	std::cout << "\n";

	std::string dialogue = "Hello traveller! Welcome to my humble shop. I sell all sorts of cool weapons here.";
	std::string dialogue2 = "Please, don't hesitate to look around! Anything caught your eye?";
	char getbtn = static_cast<char>(_getch());
	if (getbtn) {
		switch (getbtn) {
		case '1':
			std::cout << "You have selected Trade.\n";
			TradeSystem();
			break;
		case '2':
			std::cout << "You have selected Talk.\n";
			system("cls");
			PrintTrade();
			std::cout << "\n";
			typewriter(dialogue, 30, 50);
			std::cout << "\n";
			Sleep(100);
			typewriter(dialogue2, 30, 50);
			Sleep(1000);
			_kbhit();
			system("cls");
			PrintTrade();
			break;
		case '3':
			std::cout << "You have selected Back.\n";
			//go back to the map
			curScreenState = MAP_RENDER;
			Sleep(1000);
			system("cls");
			break;
		default:
			std::cout << "Invalid selection. Please choose 1, 2, or 3.\n";
			system("cls");
			PrintTrade();
			break;
			
		}
	}
}


char Game::getPos(int x, int y){
	return mapData[y][x];

}


void Game::MapEdit(int xpos, int ypos, char changeto){


}

void Game::LoadMap(std::string Map, std::string room, char roomData[ROWS][COLUMNS], bool ifNew) {
    std::ifstream fMapdata("MapData/MapData.json");
    auto MapJson = nlohmann::json::parse(fMapdata);
	int rmCatalogue = static_cast<int>(room[room.length() - 1]) - 49;
	int mapCatalogue = static_cast<int>(Map[Map.length() - 1]) - 49;

	enteredRm[mapCatalogue][rmCatalogue] = true;
	std::cout << Map << "\n";
	std::cout << room;
	Sleep(1000);
	system("cls");
	if (ifNew) {
		std::cout << "a \n";
	}
	else {
		std::cout << "b \n";
	}
	for (int i = 0; i < ROWS; i++) {
			for (int j = 0; j < COLUMNS; j++) {
				//std::cout << Room[Room.length() - 1];
				//mapObjects[mapCatalogue][rmCatalogue][i][j] = MapJson[Map][Room]["Map"][i].get<std::string>()[j];
				if (ifNew) {
					
					mapData[i][j] = MapJson[Map][room]["Map"][i].get<std::string>()[j];
				}
				else {
					
					mapData[i][j] = roomData[i][j];
				}
				std::cout << mapData[i][j];
			}
			std::cout << '\n';
			
	}
	system("cls");
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
			typewriter(Escape, 40, 50);
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
	int moveForget = -1;
	while (moveForget >= 0 && moveForget < atkListSize) {
		if (fullAmt == atkListSize) {
			std::cout << '\n' << "Which move do you want to forget? " << '\n';
			for (int i = 0; i < atkListSize; i++) {
				std::cout << "[" << i + 1 << "]" << atkList[i] << std::endl;
			}
			std::cin >> moveForget;
		}
	}
	atkList[moveForget - 1] = atkLearn;
	Sleep(3000);
	curScreenState = MAP_RENDER;

}

void Game::resetRooms()
{
	for (int i = 0; i < SECTORS; i++) {
		for (int f = 0; f < ROOMS; f++) {
			enteredRm[i][f] = false;
		}
	}
}
