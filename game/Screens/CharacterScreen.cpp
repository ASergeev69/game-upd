#include "CharacterScreen.h"
#include "../Managers/Enums.h"
#include "raylib.h"
#include "raygui.h"
#include "../Managers/AssetManager.h"
#include "../Managers/ScreenManager.h"

CharacterScreen::CharacterScreen(ScreenManager* mgr) : manager(mgr) {}

void CharacterScreen::Init()
{
    AssetManager::loadTextures("assets/character");
}

void CharacterScreen::Update()
{
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

    if (GuiButton({ 310, 844, 275, 110 }, ""))
    {
        manager->SetCurrent(GameScreen::MENU);
    }
    if (GuiTextBox({ 535, 92, 431, 88 }, name, 64, editMode)) editMode = !editMode;
    if (GuiButton({ 858, 844, 372, 110 }, "") && name[0] != '\0')
    {
        manager->selectedState.getPlayer().setSkinId(curr);
        manager->selectedState.getPlayer().setName(name);

        manager->SetCurrent(GameScreen::POKEMON);
    }


    if (GuiButton({ 1260, 444, 100, 180 }, "")) curr = (curr + 1) % 4;
    if (GuiButton({ 168, 444, 100, 180 }, "")) curr = (curr + 3) % 4;


}

void CharacterScreen::Draw()
{
    ClearBackground(RAYWHITE);

    DrawTexture(AssetManager::getTexture("character"), 0, 0, WHITE);

    DrawTextureEx(AssetManager::getTexture("person_" + std::to_string(curr)), { 500, 250 }, 0, 0.5f, WHITE);

}