#pragma once
#include <iostream>

class Cutscenes{
	public:
		static std::string key;
		static int InteractionNo;
		void PlayScene();

		std::string AsciiPrint(std::string input);
		
		int i = 5;	
		int SceneNo = 0;
		int Dialogue = 0;
};

