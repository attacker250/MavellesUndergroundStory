#include "Effects.h"
void Effects::changeColor(int desiredColor) {
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), desiredColor);
}

void Effects::typewriter(std::string text, int delay, int maxChar) {
    int charCount = 0;

    for (char c : text) {
        std::cout << c;
        std::cout.flush();


        if (GetAsyncKeyState('K') & 0x8000) {
            Sleep(2);
        }
        else {
            Sleep(delay);
            //Beep(800, 40);
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

void Effects::ClearScreen() {
    COORD cursorPosition;	cursorPosition.X = 0;	cursorPosition.Y = 0;	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), cursorPosition);
}

void Effects::ShowConsoleCursor(bool showFlag)
{
    HANDLE out = GetStdHandle(STD_OUTPUT_HANDLE);

    CONSOLE_CURSOR_INFO     cursorInfo;

    GetConsoleCursorInfo(out, &cursorInfo);
    cursorInfo.bVisible = showFlag; // set the cursor visibility
    SetConsoleCursorInfo(out, &cursorInfo);
}

void Effects::fitBox(int boxwidth,std::string text)
{
    for (int i = 0; i < (boxwidth - text.size()); i++) {
        std::cout << ' ';
    }
}

std::string Effects::returnFit(int boxwidth, std::string text) {
    std::string hi;
    for (int i = 0; i < (boxwidth - text.size()); i++) {
        //std::cout << ' ';
        hi += " ";
    }
    return hi;
}