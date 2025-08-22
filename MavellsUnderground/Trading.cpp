#include "Trading.h"

//trading
void Trading::PrintTrade() {
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

void Trading::TradeSystem() {
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

void Trading::TradeMenu() {
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
			Effects::typewriter(dialogue, 30, 50);
			std::cout << "\n";
			Sleep(100);
			Effects::typewriter(dialogue2, 30, 50);
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
