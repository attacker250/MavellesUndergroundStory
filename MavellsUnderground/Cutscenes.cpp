#include "Cutscenes.h"
#include "Player.h"
#include <iostream>
#include "json.hpp"
#include <fstream>
#include "conio.h"
#include <Windows.h>

std::string Cutscenes::key;
std::string Cutscenes::InteractionKey;

Cutscenes::Cutscenes() {
    GetCurrentConsoleFontEx(GetStdHandle(STD_OUTPUT_HANDLE), FALSE, &cfi);
    cfi.cbSize = sizeof(cfi);
    cfi.nFont = 0;

    cfi.FontFamily = FF_DONTCARE;
    cfi.FontWeight = FW_NORMAL;
    wcscpy_s(cfi.FaceName, L"Consolas"); // Choose your font


   
}


void Cutscenes::ZoomOut() {

    cfi.dwFontSize.X = 0.5;                   // Width of each character in the font
    cfi.dwFontSize.Y = 3;
    SetCurrentConsoleFontEx(GetStdHandle(STD_OUTPUT_HANDLE), FALSE, &cfi);

}

void Cutscenes::ZoomIn() {

    cfi.dwFontSize.X = 0;                   // Width of each character in the font
    cfi.dwFontSize.Y = 23;
    SetCurrentConsoleFontEx(GetStdHandle(STD_OUTPUT_HANDLE), FALSE, &cfi);
}

bool Cutscenes::PlayScene() {


    std::string currentRoom = Player::currentRoom;
    std::string currentPlace = Player::currentPlace;



    //Keep the Animation Playing
    if (i < FrameSize) {
        i++;
    }

    std::cout << AsciiPrint("------------------------------");

    if (DialogueJson[key][currentPlace][currentRoom][InteractionKey][SceneNo]["Type"] == "Text") {
        dialogueSetSize = DialogueJson[key][currentPlace][currentRoom][InteractionKey][SceneNo]["Dialogue"].size() - 1;
        FrameSize = CutsceneJson[key][currentPlace][currentRoom][InteractionKey][SceneNo]["Frames"].size() - 1;
        std::cout << CutsceneJson[key][currentPlace][currentRoom][InteractionKey][SceneNo]["Frames"][i].get<std::string>();
        std::cout << AsciiPrint("------------------------------");
        std::cout << AsciiPrint(DialogueJson[key][currentPlace][currentRoom][InteractionKey][SceneNo]["Dialogue"][Dialogue].get<std::string>());
    }
    if (DialogueJson[key][currentPlace][currentRoom][InteractionKey][SceneNo]["Type"] == "Choice") {
        FrameSize = CutsceneJson[key][currentPlace][currentRoom][InteractionKey][SceneNo]["Frames"].size() - 1;
        std::cout << CutsceneJson[key][currentPlace][currentRoom][InteractionKey][SceneNo]["Frames"][i].get<std::string>();
        std::cout << AsciiPrint("------------------------------");
        std::cout << AsciiPrint(DialogueJson[key][currentPlace][currentRoom][InteractionKey][SceneNo]["TopText"].get<std::string>());
        for (int i = 0; i < DialogueJson[key][currentPlace][currentRoom][InteractionKey][SceneNo]["Choice"].size(); i++) {
            std::cout << AsciiPrint("[" + std::to_string(i + 1) + "]" + DialogueJson[key][currentPlace][currentRoom][InteractionKey][SceneNo]["Choice"][i].get<std::string>());
        }
        dialogueSetSize = 1;
    }
    if (DialogueJson[key][currentPlace][currentRoom][InteractionKey][SceneNo]["Type"] == "Branch") {
        FrameSize = CutsceneJson[key][currentPlace][currentRoom][InteractionKey][SceneNo]["Branches"][dialogueChoice].size() - 1;
        dialogueSetSize = DialogueJson[key][currentPlace][currentRoom][InteractionKey][SceneNo]["Branches"][dialogueChoice].size() - 1;
        std::cout << CutsceneJson[key][currentPlace][currentRoom][InteractionKey][SceneNo]["Branches"][dialogueChoice][i].get<std::string>();
        std::cout << AsciiPrint("------------------------------");
        std::cout << AsciiPrint(DialogueJson[key][currentPlace][currentRoom][InteractionKey][SceneNo]["Branches"][dialogueChoice][Dialogue].get<std::string>());
    }
    if (DialogueJson[key][currentPlace][currentRoom][InteractionKey][SceneNo]["Type"] == "Empty") {
        //Make it so that they can only leave when the anim is done
        dialogueSetSize = 0;
        FrameSize = CutsceneJson[key][currentPlace][currentRoom][InteractionKey][SceneNo]["Frames"].size() - 1;
        std::cout << CutsceneJson[key][currentPlace][currentRoom][InteractionKey][SceneNo]["Frames"][i].get<std::string>();


    }
    if (DialogueJson[key][currentPlace][currentRoom][InteractionKey][SceneNo]["Type"] != "Choice" && i == FrameSize) {
        std::cout << AsciiPrint("------------------------------\n->Enter" );
    }
    else {
        std::cout << AsciiPrint("------------------------------");
    }
    
    //Handle Input
    if (_kbhit()) {
        char getbtn = static_cast<char>(_getch());
        if (DialogueJson[key][currentPlace][currentRoom][InteractionKey][SceneNo]["Type"] == "Choice") {
            int hi = (getbtn - '0');
            if (hi < DialogueJson[key][currentPlace][currentRoom][InteractionKey][SceneNo]["Choice"].size() + 1 && hi > 0) {
                dialogueChoice = hi - 1;
                SceneNo++;
                i = 0;
                Dialogue = 0;
                system("cls");
            }
        }
        if (getbtn == '\r' && DialogueJson[key][currentPlace][currentRoom][InteractionKey][SceneNo]["Type"] != "Choice" && i == FrameSize) {
            if (SceneNo == DialogueJson[key][currentPlace][currentRoom][InteractionKey].size() - 1 && Dialogue == dialogueSetSize) {
                //End of the cutscene (Return to home screen)[for now]
                i = 0;
                SceneNo = 0;
                Dialogue = 0;
                dialogueSetSize = 0;
                dialogueChoice = 0;
                FrameSize = 0;
                
                return true;
                cfi.dwFontSize.X = 0;                   // Width of each character in the font
                cfi.dwFontSize.Y = 23;
                SetCurrentConsoleFontEx(GetStdHandle(STD_OUTPUT_HANDLE), FALSE, &cfi);
                system("cls");
            }
            //change scene
            else if (Dialogue == dialogueSetSize) {
                SceneNo++;
                Dialogue = 0;
                i = 0;
                system("cls");
            }
            else {
                //Progress Dialouge
                Dialogue++;
                system("cls");
            }
        }
    }
	Sleep(50);
    return false;
}

std::string Cutscenes::AsciiPrint(std::string input) {

    std::string words;
    std::vector<std::string>split;

    std::string store;
    //factor line breaks
    for (int i = 0; i < input.size(); i++) {
        //checks if theres a line break
        if (input[i] == '\n') {
            //if so, first push back what the string stored and reset it to be empty
            split.push_back(store);
            store = "";
        }
        else {
            //otherwise, add the current letter thats being checked into the store
            store += input[i];
        }
    }
    //push back the last set of letters
    split.push_back(store);

    //run a loop for all the texts
    for (int a = 0; a < split.size(); a++) {
        for (int d = 0; d < FontJson["Default"]["b"].size(); d++) {
            //runs a loop for height of all letters
            for (int i = 0; i < split[a].size(); i++) {
                //add the row by row letters side by side   
                std::string converter;
                converter += split[a][i];
                if (FontJson["Default"].contains(converter)) {
                    words += FontJson["Default"][converter][d];
                }
            }
            words += "\n";
        }
        words += "\n";
    }
    return words;
}
