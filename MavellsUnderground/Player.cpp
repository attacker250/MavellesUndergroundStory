#include "Player.h"
#include "conio.h"

void SwitchScreen() {

}

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
        }
        if (mapData[y + ymov][x + xmov] == ' ') {
            updatePos(x + xmov, y + ymov);
            return true;
        }
        else {
            return false;
        }
    }
    else {
        return true;
    }
}
