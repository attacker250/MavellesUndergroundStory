#include "Trading.h"

//trading
void Trading::PrintTrade() {
	

	TraderData->portrait;
	for (int i = 0; i < TraderData->portrait.size(); i++) {
		std::cout << TraderData->portrait[i] << std::endl;
	}
}

void Trading::TradeSystem() {
	system("cls");
	PrintTrade();
	std::cout << "\n";
	int width = 36;
	for (int a = 0; a < 5; a++)
	{
		std::cout << '|';
		std::cout << '[' << a + 1 << ']';
		Consumables* item1 = new Consumables("Healing", a);
		PlayerData->playerInventory.consumableStorage.push_back(item1);
		std::cout << item1->name; //:D

		for ( int i = 0; i < width - PlayerData->playerInventory.consumableStorage[a]->name.length(); i++)
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

void Trading::fetchPlayerData(Player* player, Trader* trader)
{
	TraderData = trader;
	PlayerData = player;
}

void Trading::TradeMenu(int& curScreenState) {
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
