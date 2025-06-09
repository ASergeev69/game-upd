#pragma once
#include "raylib.h"
#include "Screen.h"

class ScreenManager; // forward

class MenuScreen : public Screen {
private:
    ScreenManager* manager;

    Rectangle continueButton = { 143, 199, 391, 106 };
    Rectangle savesButton = { 143, 331, 394, 103 };
    Rectangle newButton = {177, 462, 328, 101};
    Rectangle settingsButton = {223, 590, 247, 80};
public:
    MenuScreen(ScreenManager* manager);
    void Init() override;
    void Update() override;
    void Draw() override;
};