#include "MenuScreen.h"
#include <iostream>
#include "raygui.h"
#include "../Managers/Enums.h"
#include "../Managers/AssetManager.h"
#include "../Managers/ScreenManager.h"
#include "../Game/GameState.h"

MenuScreen::MenuScreen(ScreenManager* mgr) : manager(mgr) {}

void MenuScreen::Init()
{
    std::cout << "iniit";
    AssetManager::loadStyles();
    AssetManager::loadSounds("assets/menu");
    AssetManager::loadTextures("assets/menu");
    PlayMusicStream(AssetManager::getSound("menu"));
    SetMusicVolume(AssetManager::getSound("menu"), 0.5f);
    for (const auto& [name, _] : saveList) {
        saveNames.push_back(name);
    }
}

void MenuScreen::Update()
{
    UpdateMusicStream(AssetManager::getSound("menu"));
    if (showSettings) {
        DrawSettingsPopup();
        //if (GuiButton(saveButton, "Save game"))
        //{
        //    fs::path path = fs::path("saves") / getTimestampedSaveName();
        //    saveGame(selectedState, path);
        //    showSettings = false;
        //}
        return;
    }


    if (GuiButton(continueButton, ""))
        std::cout << "test";

    if (GuiButton(savesButton, ""))
        showSavesList = !showSavesList;

    if (showSavesList && !saveNames.empty()) {
        std::string concatenated;
        for (const auto& s : saveNames)
            concatenated += s + '\n';

        GuiListView(savesMenu, concatenated.c_str(), &listViewFocus, &listViewActive);

        if (listViewActive != -1 && listViewActive >= 0 && listViewActive < saveNames.size()) {
            selectedSaveIndex = listViewActive;
            selectedState = saveList[saveNames[selectedSaveIndex]];
            listViewActive = -1;

            //manager->SetCurrent(GameScreen::MAP);
        }
    }

    if (GuiButton(newButton, ""))
        manager->SetCurrent(GameScreen::CHARACTER);

    if (GuiButton(settingsButton, ""))
    {
        showSettings = true;
    }
    DrawSettingsPopup();
}

void MenuScreen::Draw()
{
    ClearBackground(RAYWHITE);
    DrawTexture(AssetManager::getTexture("main"), 0, 0, WHITE);

    if (showSavesList && !saveNames.empty()) {
        DrawRectangleLines(800, 199, 400, 300, DARKGRAY);
    }
}