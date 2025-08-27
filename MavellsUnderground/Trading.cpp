#include "Trading.h"

//trading
void Trading::PrintTrade() {


	TraderData->portrait;
	for (int i = 0; i < TraderData->portrait.size(); i++) {
		std::cout << TraderData->portrait[i] << std::endl;
	}
	std::cout << "You have : $" << std::to_string(PlayerData->playerInventory.coins) << '\n';
}

void Trading::sellSystem() {
	system("cls");
	PrintTrade();
	printBorder();
	//std::cout << "\n";
	const int width = 36;
	for (int i = 0; i < PlayerData->playerInventory.consumableStorage.size(); i++)
	{
		std::cout << "|[" << i + 1 << ']';

		//Consumables* item1 = new Consumables("Healing", a);
		//PlayerData->playerInventory.consumableStorage.push_back(item1);
		std::string txt = PlayerData->playerInventory.consumableStorage[i]->name + "   Value: " + std::to_string(PlayerData->playerInventory.consumableStorage[i]->itemValue); //:D
		std::cout << txt;
		fitBox(width, txt);

		std::cout << '|' << std::endl;
	}

	std::cout << '|' << '[' << std::to_string(PlayerData->playerInventory.consumableStorage.size() + 1) << ']';
	std::cout << "Back";
	for (int e = 0; e < width - 4; e++)
	{
		std::cout << ' ';
	}
	std::cout << '|';
	std::cout << "\n";

	for (int i = 0; i < 41; i++)
	{
		std::cout << '-';
	}

	int getbtn = static_cast<int>(_getch()) - 49;
	if (PlayerData->playerInventory.consumableStorage.size() == getbtn) {
		system("cls");
		PrintTrade();

	}
	else if (getbtn < PlayerData->playerInventory.consumableStorage.size() && getbtn >= 0) {
		PlayerData->playerInventory.coins += PlayerData->playerInventory.consumableStorage[getbtn]->itemValue;
		TraderData->traderInventory.consumableStorage.push_back(PlayerData->playerInventory.consumableStorage[getbtn]);
		std::cout << "\nYou sold " << PlayerData->playerInventory.consumableStorage[getbtn]->name << "!\n";
		PlayerData->playerInventory.consumableStorage.erase(PlayerData->playerInventory.consumableStorage.begin() + getbtn);
		Sleep(1000);
		system("cls");
	}
	else {
		sellSystem();
	}
}

void Trading::fetchPlayerData(Player* player, Trader* trader)
{
	TraderData = trader;
	PlayerData = player;
}

void Trading::buyingScreen()
{
	system("cls");
	PrintTrade();
	printBorder();
	for (int i = 0; i < TraderData->traderInventory.consumableStorage.size(); i++) {
		//std::cout << TraderData->traderInventory.consumableStorage[i]->name << '\n';
		std::string text = "|[" + std::to_string(i + 1) + ']' + TraderData->traderInventory.consumableStorage[i]->name + "   Value:" + std::to_string(TraderData->traderInventory.consumableStorage[i]->itemValue);
		std::cout << text;
		for (int f = 0; f < tradeUIWidth - text.length(); f++) {
			std::cout << ' ';
		}
		std::cout << "|\n";

	}
	for (int i = 0; i < TraderData->traderInventory.weaponStorage.size(); i++) {
		//std::cout << TraderData->traderInventory.consumableStorage[i]->name << '\n';
		std::string text = "|[" + std::to_string(i + TraderData->traderInventory.consumableStorage.size() + 1) + ']' + TraderData->traderInventory.weaponStorage[i]->name + "   Value:" + std::to_string(TraderData->traderInventory.weaponStorage[i]->itemValue);
		std::cout << text;
		for (int f = 0; f < tradeUIWidth - text.length(); f++) {
			std::cout << ' ';
		}
		std::cout << "|\n";

	}
	std::cout << "|[" << std::to_string(TraderData->traderInventory.consumableStorage.size() + TraderData->traderInventory.weaponStorage.size() + 1) << "]Back\n";
	printBorder();
	int getItem = static_cast<int>(_getch()) - 49;
	if (TraderData->traderInventory.consumableStorage.size() + TraderData->traderInventory.weaponStorage.size() == getItem) {
		system("cls");
		PrintTrade();

	}

	else if (getItem < TraderData->traderInventory.consumableStorage.size() && getItem >= 0) {
		if (PlayerData->playerInventory.coins >= TraderData->traderInventory.consumableStorage[getItem]->itemValue) {
			PlayerData->playerInventory.coins -= TraderData->traderInventory.consumableStorage[getItem]->itemValue;
			PlayerData->playerInventory.consumableStorage.push_back(TraderData->traderInventory.consumableStorage[getItem]);
			std::cout << "You purchased " << TraderData->traderInventory.consumableStorage[getItem]->name << "!\n";
			TraderData->traderInventory.consumableStorage.erase(TraderData->traderInventory.consumableStorage.begin() + getItem);
		}
		else {
			std::cout << "Insufficient coins! (You're broke!)";
		}
		Sleep(1000);
		system("cls");

	}
	else if (getItem < TraderData->traderInventory.consumableStorage.size() + TraderData->traderInventory.weaponStorage.size() && getItem >= 0) {
		getItem -= TraderData->traderInventory.consumableStorage.size();
		if (PlayerData->playerInventory.coins >= TraderData->traderInventory.weaponStorage[getItem]->itemValue) {
			bool inInv = false;
			for (int i = 0; i < PlayerData->playerInventory.weaponStorage.size(); i++) {
				if (TraderData->traderInventory.weaponStorage[getItem] == PlayerData->playerInventory.weaponStorage[i]) {
					inInv = true;
					break;
				}
			}
			if (!inInv) {
				PlayerData->playerInventory.coins -= TraderData->traderInventory.weaponStorage[getItem]->itemValue;
				PlayerData->playerInventory.weaponStorage.push_back(TraderData->traderInventory.weaponStorage[getItem]);
				std::cout << "You purchased " << TraderData->traderInventory.weaponStorage[getItem]->name << "!\n";
				TraderData->traderInventory.weaponStorage.erase(TraderData->traderInventory.weaponStorage.begin() + getItem);
			}
			else {
				std::cout << "This item is already in your inventory! \n";
			}
		}
		else {
			std::cout << "Insufficient coins! (You're broke!)";
		}
		Sleep(1000);
		system("cls");

	}
	else {

		buyingScreen();

	}

	//	Sleep(500);

}

void Trading::printBorder()
{
	for (int i = 0; i < tradeUIWidth + 1; i++) {
		std::cout << '-';
	}
	std::cout << '\n';
}


void Trading::TradeMenu(int& curScreenState) {
	PrintTrade();
	printBorder();
	std::cout << "|[1]Buy";
	for (int j = 0; j < 33; j++) {
		std::cout << ' ';
	}
	std::cout << '|';
	std::cout << "\n|[2]Sell";
	for (int j = 0; j < 32; j++) {
		std::cout << ' ';
	}
	std::cout << '|';
	std::cout << "\n|[3]Talk";
	for (int j = 0; j < 32; j++) {
		std::cout << ' ';
	}
	std::cout << '|';
	std::cout << "\n|[4]Back";
	for (int e = 0; e < 32; e++)
	{
		std::cout << ' ';

	}
	std::cout << "|\n";


	for (int i = 0; i < 41; i++) {
		std::cout << '-';
	}
	std::cout << "\n";

	//work on this when you integrate the dialogue + cutscene system

	std::string dialogue = "Hello traveller! Welcome to my humble shop. I sell all sorts of cool weapons here.";
	std::string dialogue2 = "Please, don't hesitate to look around! Anything caught your eye?";
	char getbtn = static_cast<char>(_getch());

	if (getbtn) {
		switch (getbtn) {
		case '1':
			//	std::cout << "You have selected Sell.\n";
			buyingScreen();
			break;
		case '2':
			std::cout << "You have selected Sell.\n";
			sellSystem();
			break;
		case '3':
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
		case '4':
			std::cout << "You have selected Back.\n";
			//go back to the map
			curScreenState = MAP_RENDER;
			Sleep(1000);
			system("cls");
			break;
		default:
			//std::cout << "Invalid selection. Please choose 1, 2, or 3.\n";
			system("cls");
			PrintTrade();
			break;

		}
	}
}
