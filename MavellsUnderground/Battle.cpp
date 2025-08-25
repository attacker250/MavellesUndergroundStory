#include "Battle.h"
#include <iostream>
#include "Windows.h"
#include "conio.h"
#include <cstdlib>
#include <ctime>
#include "Enemy.h"
#include "Inventory.h"

#include <fstream>
#include "json.hpp"



int Battle::battleHp = 0;

void Battle::PrintBattle() { //to be replaced with enemy ASCII
   /* const int width = 41;
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
    }*/
    //char size = battleEnemy->portrait.size()
    for (int i = 0; i < battleEnemy->portrait.size(); i++) {

		std::cout << battleEnemy->portrait[i];
        std::cout << '\n';
        
    }
}
 

//input enemy damage here
void Battle::EnemyTurn()
{
    std::ifstream fEnemydata("EntityData/EntityData.json");
    auto EnemyJson = nlohmann::json::parse(fEnemydata);
    Sleep(300);
    srand(time(0));
    int chosenAtk = rand() % battleEnemy->atkList.size();
    int enemydmg = 50;
    std::string enemymssg = "\nThe enemy used " + battleEnemy->atkList[chosenAtk] + "!"; //pass in enemydmg
    typewriter(enemymssg, 20, 50);
    battlePlayer->hp -= enemydmg;
    Sleep(300);
    system("cls");
}
void Battle::initBattle(Entity *enemy, Entity* player)
{
    battleEnemy = enemy;
    battlePlayer = player;
    //for (int i = 0; i < player->atkList; i++) {
    //    atkList[i] = player->atkList[atkListSize];
    //}
}

void Battle::BattleMode() {
	//to be changed to enemy class hp
	std::string WinMessage = "You Won!";
	
	if (battleHp <= 0) {
		stillbattle = false;
        typewriter(WinMessage, 40, 50);
	}
    if (stillbattle == false) {
        std::cout << "\n";
        std::string Encounter = "You encountered a wild " + battleEnemy->name + '!';
        typewriter(Encounter, 1, 40);
        stillbattle = true;
        Sleep(400);
        system("cls");
        PrintBattle();
        BattleMode();
    }
    else {
        std::cout << '\n' << battleEnemy->name << "'s HP:" << battleEnemy->hp << std::endl;
        std::cout << "Your HP:" << (static_cast<Player*>(battlePlayer))->hp << '\n';
        std::cout << "[1] Attack" << std::endl;
        std::cout << "[2] Items" << std::endl;
        std::cout << "[3] Run" << std::endl;
        std::cout << "[4] Test out learn attack" << std::endl;
    }


}
void Battle::ItemList() {
    std::cout << "\n";

    for (int i = 0; i < static_cast<Player*>(battlePlayer)->playerInventory.consumableStorage.size(); i++) {
        std::cout << '[' + std::to_string(i + 1) + "] " + static_cast<Player*>(battlePlayer)->playerInventory.consumableStorage[i]->name << '\n';

    }

    std::cout << '[' + std::to_string(static_cast<Player*>(battlePlayer)->playerInventory.consumableStorage.size() + 1) + "] Back \n";
    //std::cout << "[4] Back" << std::endl;

    int getbtn = static_cast<int>(_getch()) - 49;

    if (static_cast<Player*>(battlePlayer)->playerInventory.consumableStorage.size() == getbtn) {
        system("cls");
        PrintBattle();
    }
    else if (battlePlayer->atkList.size() > getbtn && getbtn >= 0) {
        std::string txt = "You chose " + (static_cast<Player*>(battlePlayer))->playerInventory.consumableStorage[getbtn]->name + '!';
        typewriter(txt, 20, 40);
        std::cout << '\n';
        typewriter((static_cast<Player*>(battlePlayer))->playerInventory.consumableStorage[getbtn]->description, 20, 60);
        //if ((static_cast<Player*>(battlePlayer))->playerInventory.consumableStorage[getbtn]->itemType == "Healing") {
        //    std::cout << (static_cast<Player*>(battlePlayer))->playerInventory.consumableStorage[getbtn]->itemEffectiveness;
        //    (static_cast<Player*>(battlePlayer))->hp += (static_cast<Player*>(battlePlayer))->playerInventory.consumableStorage[getbtn]->itemEffectiveness;
        //    std::cout << (static_cast<Player*>(battlePlayer))->hp;
        //}
        //else if ((static_cast<Player*>(battlePlayer))->playerInventory.consumableStorage[getbtn]->itemType == "Buff") {
        //    (static_cast<Player*>(battlePlayer))->dmgModifier += (static_cast<Player*>(battlePlayer))->playerInventory.consumableStorage[getbtn]->itemEffectiveness;
        //}
        //(static_cast<Player*>(battlePlayer))->playerInventory.consumableStorage[getbtn]->consume(1);
        //for (int i = 0; i < (static_cast<Player*>(battlePlayer))->playerInventory.consumableStorage.size(); i++) {
        //    if ((static_cast<Player*>(battlePlayer))->playerInventory.consumableStorage[i]->broken) {
        //        (static_cast<Player*>(battlePlayer))->playerInventory.consumableStorage.erase((static_cast<Player*>(battlePlayer))->playerInventory.consumableStorage.begin() + i);
        //    }
        //}
        (static_cast<Player*>(battlePlayer))->consumeItem((static_cast<Player*>(battlePlayer))->playerInventory.consumableStorage[getbtn]->itemType, (static_cast<Player*>(battlePlayer))->playerInventory.consumableStorage[getbtn]->itemEffectiveness, getbtn);
        Sleep(1000);
        system("cls");
        PrintBattle();
    }
}

void Battle::AttackList() {
    std::cout << "\n";
    if (battlePlayer->atkList.size() > 0) {
        for (int i = 0; i < battlePlayer->atkList.size(); i++) {
            std::cout << "[" << i + 1 << "]" << battlePlayer->atkList[i] << std::endl;
        }
    }
    std::cout << "[" << battlePlayer->atkList.size() + 1 << "]" << " Back" << std::endl;
    int getbtn = static_cast<int>(_getch()) - 49;
    Beep(1080, 300);

    if (battlePlayer->atkList.size() == getbtn) {
        system("cls");
        PrintBattle();
    }
    else if (battlePlayer->atkList.size() > getbtn && getbtn >= 0){
        std::ifstream fAtkData("MoveData.json");
        auto AtkJson = nlohmann::json::parse(fAtkData);

        std::string txt = "You chose " + battlePlayer->atkList[getbtn] + '!';
        typewriter(txt, 20, 40);
        std::cout << '\n';
        Sleep(500);
        txt = AtkJson[battlePlayer->atkList[getbtn]]["Action"];
        typewriter(txt, 20, 40);
        Sleep(500);
        std::cout << '\n';
        int dmg = AtkJson[battlePlayer->atkList[getbtn]]["Damage"].get<int>();
        txt = "It dealt " + std::to_string(dmg) + " damage! \n";
        battleEnemy->hp -= dmg;
        //txt += " damage!";
        typewriter(txt, 20, 40);
        Sleep(500);
        system("cls");
        PrintBattle();
        EnemyTurn();

    }
    else {
        std::cout << "Invalid option";
        Sleep(500);
        system("cls");
        PrintBattle();
        AttackList();
    }
            
        
    
}

void Battle::BattleMenu(int& curScreenState) {
    BattleMode();
    bool isRunning = true;
    //	while (isRunning) {
   // Battle();
    char getbtn = static_cast<char>(_getch());
    std::string Escape = "You ran away successfully!";
	std::string attempt = "You attempted to run.";
    int randNumber = rand() % 2 + 1;
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
            Sleep(300);
			srand(static_cast<unsigned>(time(0)));
            typewriter(attempt, 2, 40);



			if (randNumber == 1) {
				curScreenState = 0;
				typewriter(Escape, 2, 50);
				Sleep(300);
                stillbattle = false;
				system("cls");
                curScreenState = MAP_RENDER;
			}
			else if (randNumber == 2) {
                std::cout << "failed to escape! " << std::endl;
                Sleep(500);
                system("cls");

                PrintBattle();
               //  BattleMode();
                BattleMenu(curScreenState);
               
			}
            break;
        default:
            //std::cout << "Invalid choice!" << std::endl;
            ClearScreen();
           
            PrintBattle();
        //  BattleMode();
            BattleMenu(curScreenState);
            break;

        }
    }
}