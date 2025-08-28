#pragma once
#include <iostream>
#include <Windows.h>
#include "json.hpp"
#include <fstream>


class Cutscenes {
public:
	static std::string key;
	static std::string InteractionKey;

	Cutscenes();

	void ZoomOut();
	void ZoomIn();
	bool PlayScene();

	std::string AsciiPrint(std::string input);

	int i = 0;
	int SceneNo = 0;
	int Dialogue = 0;
	int dialogueSetSize = 0;
	int dialogueChoice = 0;
	int FrameSize = 0;

	CONSOLE_FONT_INFOEX cfi;

	std::ifstream fFontdata{ "Animations/Fonts.json" };
	nlohmann::json FontJson = nlohmann::json::parse(fFontdata);

	//std::ifstream fCutscenedata{ "Animations/Cutscenes.json" };
	static nlohmann::json CutsceneJson;

	std::ifstream fDialoguedata{"Animations/Dialogue.json"};
	nlohmann::json DialogueJson = nlohmann::json::parse(fDialoguedata);

};

