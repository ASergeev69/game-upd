#pragma once
#include "raylib.h"
#include "Screen.h"
#include "../Game/GameState.h"
#include <vector>
#include <unordered_map>
#include <string>

class ScreenManager; // forward

class MenuScreen : public Screen {
private:
    ScreenManager* manager;

    Rectangle continueButton = { 143, 199, 391, 106 };
    Rectangle savesButton = { 143, 331, 394, 103 };
    Rectangle newButton = {177, 462, 328, 101};
    Rectangle settingsButton = {223, 590, 247, 80};
    Rectangle savesMenu = { 800, 199, 400, 300 };

    int selectedSaveIndex = -1;
    int listViewFocus = 0;
    int listViewActive = -1; // 🔧 добавь это
    bool showSavesList = false;
    unordered_map<string, GameState> saveList = loadAllSaves("saves");
    std::vector<std::string> saveNames;
public:
    MenuScreen(ScreenManager* manager);
    void Init() override;
    void Update() override;
    void Draw() override;
};