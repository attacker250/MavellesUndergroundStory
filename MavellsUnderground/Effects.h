#pragma once
#include <string>
#include <iostream>
#include "conio.h"
#include "Windows.h"

class Effects
{
public:
	void typewriter(std::string& text, int delay, int maxChar);
	static void ClearScreen();
	static void ShowConsoleCursor(bool showFlag);
};

