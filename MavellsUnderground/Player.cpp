#include "Player.h"
#include "conio.h"

void SwitchScreen(char MapData[12][40], int *curScreenState, ) {

}

void Player::move()
{
    if (_kbhit())
    {
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
    }
}
