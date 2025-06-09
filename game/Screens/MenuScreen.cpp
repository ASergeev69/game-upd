#include "MenuScreen.h"
#include <iostream>
#include "raygui.h"
#include "../Managers/AssetManager.h"
#include "../Managers/ScreenManager.h"

MenuScreen::MenuScreen(ScreenManager* mgr) : manager(mgr) {}

void MenuScreen::Init()
{
    std::cout << "iniit";
    AssetManager::loadStyles();
    AssetManager::loadSounds("assets/menu");
    AssetManager::loadTextures("assets/menu");
    PlayMusicStream(AssetManager::getSound("menu"));
    SetMusicVolume(AssetManager::getSound("menu"), 0.5f);
}

void MenuScreen::Update()
{
    UpdateMusicStream(AssetManager::getSound("menu"));

    if (GuiButton(continueButton, ""))
        std::cout << "test";
    if (GuiButton(savesButton, ""))
        std::cout << "test";
    if (GuiButton(newButton, ""))
        std::cout << "test";
    if (GuiButton(settingsButton, ""))
        std::cout << "test";

}

void MenuScreen::Draw()
{
    ClearBackground(RAYWHITE);
    DrawTexture(AssetManager::getTexture("main"), 0, 0, WHITE);
}