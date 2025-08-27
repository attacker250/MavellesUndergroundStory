#include "Battle.h"
#include <iostream>
#include "Windows.h"
#include "conio.h"
#include <cstdlib>
#include <ctime>
#include "Enemy.h"
#include "Inventory.h"
#include "Game.h"
#include "Player.h"

#include <fstream>
#include "json.hpp"

enum types {
    FIRE,
    WATER,
    GRASS,

    MAX_TYPES
};
enum ScreenState {
    MAP_RENDER,
    BATTLE,
    INVENTORY,
    CUTSCENE,
    TRADING,
    MENU,
    LEARNATK,
    EQUIPMENT,
    MAIN_MENU,

    MAXSCREENSTATE,
};

int Battle::battleHp = 0;

void Battle::PrintBattle() { //to be replaced with enemy ASCII
    for (int i = 0; i < battleEnemy->portrait.size(); i++) {

		std::cout << battleEnemy->portrait[i];
        std::cout << '\n';
        
    }
    std::cout << battleEnemy->type << '\n';
}


 

//input enemy damage here
void Battle::EnemyTurn()
{

    Sleep(300);
    srand(time(0));
    int chosenAtk = rand() % battleEnemy->atkList.size();
    int enemydmg = 50;
    std::string enemymssg = "\nThe enemy used " + battleEnemy->atkList[chosenAtk] + "!"; //pass in enemydmg
    typewriter(enemymssg, 20, 50);
    battlePlayer->hp -= enemydmg;
    if (battlePlayer->hp <= 0) {
        Game::curScreenState = MAIN_MENU;
    }
    Sleep(300);
    system("cls");
}
void Battle::initBattle(Enemy *enemy, Player* player)
{
    stillbattle = true;
    battleEnemy = enemy;
    battlePlayer = player;
    //for (int i = 0; i < entityList.size(); i++) {
    //    entityListBattle.push_back(entityList[i]);
    //}
    //for (int i = 0; i < player->atkList; i++) {
    //    atkList[i] = player->atkList[atkListSize];
    //}
}

void Battle::BattleMode() {
	//to be changed to enemy class hp
	std::string WinMessage = "You Won!";
	
    //Check if enemy defeated
	if (battleHp <= 0) {
		stillbattle = false;
        typewriter(WinMessage, 40, 50);
	}

    //On first enter
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
    //Print menu
    else {
        std::cout << '\n' << battleEnemy->name << "'s HP:" << battleEnemy->hp << std::endl;
        std::cout << "Your HP:" << battlePlayer->hp << '\n';
        std::cout << "[1] Attack" << std::endl;
        std::cout << "[2] Items" << std::endl;
        std::cout << "[3] Run" << std::endl;
        std::cout << "[4] Test out learn attack" << std::endl;
    }


}
void Battle::ItemList() {
    std::cout << "\n";

    for (int i = 0; i < battlePlayer->playerInventory.consumableStorage.size(); i++) {
        std::cout << '[' + std::to_string(i + 1) + "] " + battlePlayer->playerInventory.consumableStorage[i]->name << '\n';

    }

    std::cout << '[' + std::to_string(battlePlayer->playerInventory.consumableStorage.size() + 1) + "] Back \n";
    //std::cout << "[4] Back" << std::endl;

    int getbtn = static_cast<int>(_getch()) - 49;

    if (battlePlayer->playerInventory.consumableStorage.size() == getbtn) {
        system("cls");
        PrintBattle();
    }
    else if (battlePlayer->atkList.size() > getbtn && getbtn >= 0) {
        std::string txt = "You chose " + battlePlayer->playerInventory.consumableStorage[getbtn]->name + '!';
        typewriter(txt, 20, 40);
        std::cout << '\n';
        typewriter(battlePlayer->playerInventory.consumableStorage[getbtn]->description, 20, 60);
        if (battlePlayer->playerInventory.consumableStorage[getbtn]->itemType == "Healing") {
            std::cout << battlePlayer->playerInventory.consumableStorage[getbtn]->itemEffectiveness;
            battlePlayer->hp += battlePlayer->playerInventory.consumableStorage[getbtn]->itemEffectiveness;
            std::cout << battlePlayer->hp;
        }
        else if (battlePlayer->playerInventory.consumableStorage[getbtn]->itemType == "Buff") {
            battlePlayer->dmgModifier += battlePlayer->playerInventory.consumableStorage[getbtn]->itemEffectiveness;
        }
        battlePlayer->playerInventory.consumableStorage[getbtn]->consume(1);
        for (int i = 0; i < battlePlayer->playerInventory.consumableStorage.size(); i++) {
            if (battlePlayer->playerInventory.consumableStorage[i]->broken) {
                battlePlayer->playerInventory.consumableStorage.erase(battlePlayer->playerInventory.consumableStorage.begin() + i);
            }
        }
        battlePlayer->consumeItem(battlePlayer->playerInventory.consumableStorage[getbtn]->itemType, battlePlayer->playerInventory.consumableStorage[getbtn]->itemEffectiveness, getbtn);
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
    //Beep(1080, 300);

    if (battlePlayer->atkList.size() == getbtn) {
        system("cls");
        PrintBattle();
    }
    else if (battlePlayer->atkList.size() > getbtn && getbtn >= 0){
        


        std::string txt = "You chose " + battlePlayer->atkList[getbtn] + '!';
        typewriter(txt, 20, 40);
        std::cout << '\n';
        for (int i = 0; i < battlePlayer->playerInventory.weaponStorage.size(); i++) {
            if (battlePlayer->playerInventory.weaponStorage[i]->inUse) {
                int dmg = 0;
                int playertype = 0;
                int enemytype = 0;
                switch (getbtn + 1) {
                case 1:
                    dmg = battlePlayer->playerInventory.weaponStorage[i]->move1(battleEnemy);
                    break;

                case 2:
                    dmg = battlePlayer->playerInventory.weaponStorage[i]->move2(battleEnemy);
                    break;

                case 3:
                    dmg = battlePlayer->playerInventory.weaponStorage[i]->move3(battleEnemy);
                    break;

                case 4:
                    dmg = battlePlayer->playerInventory.weaponStorage[i]->move4(battleEnemy);
                    break;
                }
                if (battlePlayer->playerInventory.weaponStorage[i]->type == "Fire") {
                    playertype = FIRE;
                }
                else if (battlePlayer->playerInventory.weaponStorage[i]->type == "Water") {
                    playertype = WATER;
                }
                else if (battlePlayer->playerInventory.weaponStorage[i]->type == "Grass") {
                    playertype = GRASS;
                }

                if (battleEnemy->type == "Fire") {
                    playertype = FIRE;
                }
                else if (battleEnemy->type == "Water") {
                    playertype = WATER;
                }
                else if (battleEnemy->type == "Grass") {
                    playertype = GRASS;
                }
                if ((playertype == enemytype + 1) || (playertype == FIRE && enemytype == GRASS)) {
                    dmg *= 2;
                    std::cout << "\nIt was super effective!\n";
                }
                else if ((playertype == enemytype - 1) || (playertype == GRASS && enemytype == FIRE)) {
                    dmg /= 2;
                    std::cout << "\nIt was not very effective!\n";
                }
                Sleep(1000);


                battleEnemy->hp -= dmg;
            }
            
        }
        //Sleep(500);
        //txt = AtkJson[battlePlayer->atkList[getbtn]]["Action"];
        //typewriter(txt, 20, 40);
        Sleep(500);
        std::cout << '\n';
       /* int dmg = AtkJson[battlePlayer->atkList[getbtn]]["Damage"].get<int>();*/
      /*  txt = "It dealt " + std::to_string(dmg) + " damage! \n";*/
        
        //battleEnemy->hp -= dmg;
        //txt += " damage!";
       // typewriter(txt, 20, 40);
        Sleep(500);
        system("cls");
        if (battleEnemy->hp > 0) {
            PrintBattle();
            EnemyTurn();
        }
        else{
            
            stillbattle = false;

        }

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
        //Beep(1080, 300);
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
                EnemyTurn();
               
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