#include "CharacterScreen.h"
#include "raylib.h"
#include "raygui.h"
#include "../Managers/AssetManager.h"

CharacterScreen::CharacterScreen(ScreenManager* mgr) : manager(mgr) {};

void CharacterScreen::Init()
{

}

void CharacterScreen::Update()
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
}

void CharacterScreen::Draw()
{
    ClearBackground(RAYWHITE);
    DrawTexture(AssetManager::getTexture("character"), 0, 0, WHITE);
}