#include "BattleScreen.h"
#include "../Managers/Enums.h"
#include "raylib.h"
#include "raygui.h"
#include "../Managers/DataManager.h"
#include "../Managers/ScreenManager.h"
#include "../Game/Battle.h"
#include <cstdlib>   // для rand()
#include <ctime>     // для time()

BattleScreen::BattleScreen(ScreenManager* mgr) : manager(mgr) {}

void BattleScreen::Init()
{
    std::srand(static_cast<unsigned int>(std::time(nullptr)));
    AssetManager::loadTextures("assets/battle");
    allBots = DataManager::getAllBots();

    randomBot = allBots[std::rand() % allBots.size()];

    Battle currBattle(&manager->selectedState.getPlayer(), &randomBot);
}

void BattleScreen::Update()
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




}

void BattleScreen::Draw()
{
    ClearBackground(RAYWHITE);

    DrawTexture(AssetManager::getTexture("battle"), 0, 0, WHITE);

    Pokemon& poke = manager->selectedState.getPlayer().getPokemon(i);
    float x = 1040;
    float y = 260 + i * 236; // Расстояние между покемонами: 236

    // Отрисовка текстуры покемона
    DrawTextureEx(AssetManager::getTexture(poke.getName()), { x, y }, 0, 2.0f, WHITE);

}