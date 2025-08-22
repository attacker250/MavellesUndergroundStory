#include "Effects.h"

void Effects::typewriter(std::string& text, int delay, int maxChar) {
    int charCount = 0;

    for (char c : text) {
        std::cout << c;
        std::cout.flush();


        if (GetAsyncKeyState('K') & 0x8000) {
            Sleep(2);
        }
        else {
            Sleep(delay);
            Beep(800, 40);
        }

        charCount++;

        if (charCount > maxChar && c == ' ') {
            std::cout << "\n";
            charCount = 0;
        }
        if (c == '.' || c == '!') {
            Sleep(1000);
        }

    }
}
