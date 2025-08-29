#pragma once
#include <string>
#include <iostream>
#include "conio.h"
#include "Windows.h"

class Effects
{
public:
	static void changeColor(int desiredColor);
	void typewriter(std::string text, int delay, int maxChar);
	static void ClearScreen();
	static void ShowConsoleCursor(bool showFlag);
	static void fitBox(int boxwidth,std::string text);
	std::string returnFit(int boxwidth, std::string text);
};

