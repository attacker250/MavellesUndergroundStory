#include "Player.h"
#include "conio.h"
#include "Battle.h"

#include <iostream>
#include <vector>
#include <string>

Inventory Player::playerInventory;


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
                learnAtk("FIRE");

                    
                
                break;
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
    Battle::atkLearn = atkName;
    curScreenState = LEARNATK;
    
}
