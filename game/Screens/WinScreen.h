#pragma once
#include "Screen.h"
#include "../Managers/ScreenManager.h"

class ScreenManager; // forward

class WinScreen : public Screen {
private:
    ScreenManager* manager;
public:
    WinScreen(ScreenManager* mgr) : manager(mgr) {}
    void Init() override {
        AssetManager::loadTextures("assets/win");
    };
    void Update() override
    {
        if (GuiButton({ 295, 412, 397, 170 }, ""))
        {
            manager->SetCurrent(GameScreen::MENU);
        }
    };
    void Draw() override
    {
        ClearBackground(RAYWHITE);
        DrawTexture(AssetManager::getTexture("win"), 0, 0, WHITE);
    };
};
