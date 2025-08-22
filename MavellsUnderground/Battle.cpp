#include "Battle.h"
#include <iostream>
#include "Windows.h"
#include "conio.h"

int Battle::battleHp = 0;
std::string Battle::atkList[atkListSize];
std::string Battle::atkLearn;

void Battle::PrintBattle() { //to be replaced with enemy ASCII
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

void Battle::BattleMode() {
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
    }
}

//input enemy damage here
void Battle::EnemyTurn()
{
    Sleep(300);
    int enemydmg = 50;
    std::string enemymssg = "\nThe enemy attacks! It dealt " + std::to_string(enemydmg) + " damage to you..."; //pass in enemydmg
    typewriter(enemymssg, 20, 50);
    Sleep(300);
    system("cls");
}
void Battle::ItemList() {
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

void Battle::AttackList() {
    std::cout << "\n";
    for (int i = 0; i < Battle::atkListSize; i++) {
        std::cout << "[" << i + 1 << "]" << Battle::atkList[i] << std::endl;
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

void Battle::BattleMenu(int& curScreenState) {
    BattleMode();
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