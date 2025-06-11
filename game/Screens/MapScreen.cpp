#include "MapScreen.h"
#include "../Managers/Enums.h"
#include "raylib.h"
#include "raygui.h"
#include <iostream>
#include <string>
#include "../Map/Map.h"
#include "../Managers/AssetManager.h"
#include "../Map/Cell.h"
#include "../Managers/DataManager.h"
#include "../Managers/ScreenManager.h"

MapScreen::MapScreen(ScreenManager* mgr) : manager(mgr) {}

void MapScreen::Init()
{
    DataManager::loadBots("data/bots.json");
    AssetManager::loadTextures("assets/map");

    std::cout << manager->selectedState.getPlayer().getName() << " " << manager->selectedState.getPlayer().getSkinId() << " " << manager->selectedState.getPlayer().getPokemon(0).getName() <<
        " " << manager->selectedState.getPlayer().getPokemon(1).getName() << " " << manager->selectedState.getPlayer().getPokemon(2).getName() << std::endl;

}

void MapScreen::Update()
{
    if (showSettings) {
        DrawSettingsPopup();
        if (GuiButton(saveButton, "Save game"))
        {
            fs::path path = fs::path("saves") / getTimestampedSaveName();
            saveGame(manager->selectedState, path);
            showSettings = false;
        }
        return;
    }

    if (IsKeyPressed(KEY_W))
    {
        pos = "b";
        enemy = manager->selectedState.movePlayer(0, -1);
    }
    if (IsKeyPressed(KEY_S))
    {
        pos = "f";
        enemy = manager->selectedState.movePlayer(0, 1);
    }
    if (IsKeyPressed(KEY_D))
    {
        pos = "r";
        enemy = manager->selectedState.movePlayer(1, 0);
    }
    if (IsKeyPressed(KEY_A))
    {
        pos = "l";
        enemy = manager->selectedState.movePlayer(-1, 0);
    }
    if (IsKeyPressed(KEY_ESCAPE)) {
        enemy = showSettings = !showSettings; // переключение
    }

    if (enemy)
    {
        enemy = false;
        std::cout << "enemy!";
        
        manager->SetCurrent(GameScreen::BATTLE);
    }

}

void MapScreen::Draw()
{
    ClearBackground(RAYWHITE);
    DrawTexture(AssetManager::getTexture("map"), 0, 0, WHITE);

    for (int i = 0; i < 10; ++i)
    {
        for (int j = 0; j < 9; ++j)
        {
            if (manager->selectedState.getMap().getGrid()[j][i].getTextureName() == "wall" || manager->selectedState.getMap().getGrid()[j][i].getTextureName() == "heal" || manager->selectedState.getMap().getGrid()[j][i].getTextureName() == "enemy")
            {
                x = (63 + i * 76 + i * 0.15);
                y = (99.0 + j * 77 + j * 0.1);
                DrawTextureEx(AssetManager::getTexture(manager->selectedState.getMap().getGrid()[j][i].getTextureName()), { x, y }, 0, 0.094f, WHITE);
            }

            if (manager->selectedState.getMap().getGrid()[j][i].getTextureName() == "player")
            {
                x = (63 + i * 76 + i * 0.15);
                y = (99.0 + j * 77 + j * 0.1);
                DrawTextureEx(AssetManager::getTexture("person_" + pos + "_" + std::to_string(manager->selectedState.getPlayer().getSkinId())), { x, y }, 0, 0.094f, WHITE);
            }
        }
    }

    for (int i = 0; i < 3; ++i) {
        Pokemon& poke = manager->selectedState.getPlayer().getPokemon(i);
        float x = 1040;
        float y = 260 + i * 236; // Расстояние между покемонами: 236

        // Отрисовка текстуры покемона
        DrawTextureEx(AssetManager::getTexture(poke.getName()), { x, y }, 0, 2.0f, WHITE);

        // Параметры полосы здоровья
        float barX = x + 25;
        float barY = y + 20;
        float barWidth = 120;
        float barHeight = 20;
        float hpRatio = (float) (poke.getHP() / poke.getMaxHP());

        // Фон полосы
        DrawRectangle(barX, barY, barWidth, barHeight, DARKGRAY);
        // Текущая полоса HP
        DrawRectangle(barX, barY, barWidth * hpRatio, barHeight, GREEN);
        // Обводка
        DrawRectangleLines(barX, barY, barWidth, barHeight, BLACK);

        // Уровень покемона
        DrawText(("Lvl " + std::to_string(poke.getLevel())).c_str(), barX, barY - 25, 20, WHITE);
    }


}