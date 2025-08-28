#include "Player.h"
#include "conio.h"
#include "Battle.h"

#include <iostream>
#include <vector>

std::vector<std::string> Player::atkList;
Inventory Player::playerInventory;
int Player::hp = maxHp;
int Player::dmgModifier = 0;

bool Player::move(){
    if (_kbhit()){
        xmov = 0;
        ymov = 0;
        char getbtn = static_cast<char>(_getch());
        switch (getbtn) {
            case ('a'): 
            case ('A'):
                xmov--;
                break;
            
            case ('w'):
            case ('W'):
                ymov--;
                break;

            case ('s'):
            case ('S'):
            
                ymov++;
                break;


            case ('d'):
            case ('D'):
                xmov++;
                break;

            case ('i'):
                playerInventory.addItem("SWORD");
                learnAtk("FIRE");
                break;
            case ('u'):
                gameQuit = true;
                break;
            case ('E'):
            case ('e'):
                curScreenState = INVENTORY;
                break;
            case ('Q'):
            case ('q'):
                curScreenState = EQUIPMENT;
        }
        if (mapData[y + ymov][x + xmov] == ' ') {
            updatePos(x + xmov, y + ymov);
            return true;
			
        }
        else {
            //std::cout << "wall" << mapData[y + ymov][x + xmov]  ;
            return false;
        }
    }

    else {
        return true;
    }
}

//lets the player learn an atk (like in pkmn!)
void Player::learnAtk(std::string atkName){
    //Battle::atkLearn = atkName;
    //curScreenState = LEARNATK;
    //
}

void Player::consumeItem(int itemIndex){
    playerInventory.consumeItem(itemIndex,hp,dmgModifier);
    playerInventory.consumableStorage[itemIndex]->consume(1);
    for (int i = 0; i < playerInventory.consumableStorage.size(); i++) {
        if (playerInventory.consumableStorage[i]->broken) {
            delete playerInventory.consumableStorage[i];
            playerInventory.consumableStorage.erase(playerInventory.consumableStorage.begin() + i);
        }
    }
}

