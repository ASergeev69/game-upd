#include "PokemonScreen.h"
#include "../Managers/Enums.h"
#include "raylib.h"
#include "raygui.h"
#include <iostream>
#include "../Managers/AssetManager.h"
#include "../Managers/DataManager.h"
#include "../Managers/ScreenManager.h"

PokemonScreen::PokemonScreen(ScreenManager* mgr) : manager(mgr) {}

void PokemonScreen::Init()
{
    AssetManager::loadTextures("assets/pokemon");
    DataManager::loadPokemons("data/pokemons.json");

    allPokes = DataManager::getAllPokemons();
}

void PokemonScreen::Update()
{
    // Кнопка "Назад"
    if (GuiButton({ 272, 794, 272, 108 }, "")) {
        manager->SetCurrent(GameScreen::MENU);
    }

    // Сложность
    bool toggle0 = difficultyActive == Difficulty::EASY;
    bool toggle1 = difficultyActive == Difficulty::MEDIUM;
    bool toggle2 = difficultyActive == Difficulty::HARD;

    GuiToggle({ 202, 127, 300, 110 }, "", &toggle0);
    GuiToggle({ 571, 127, 384, 110 }, "", &toggle1);
    GuiToggle({ 1020, 127, 317, 110 }, "", &toggle2);

    if (IsMouseButtonReleased(MOUSE_LEFT_BUTTON)) {
        Vector2 mouse = GetMousePosition();
        if (CheckCollisionPointRec(mouse, { 202, 127, 300, 110 })) difficultyActive = Difficulty::EASY;
        else if (CheckCollisionPointRec(mouse, { 571, 127, 384, 110 })) difficultyActive = Difficulty::MEDIUM;
        else if (CheckCollisionPointRec(mouse, { 1020, 127, 317, 110 })) difficultyActive = Difficulty::HARD;
    }

    // Покемоны
    int selectedCount = 0;
    for (int i = 0; i < 10; i++) {
        int row = i / 5;
        int col = i % 5;

        Rectangle rect = {
            241 + col * (167 + 63),
            301 + row * (144 + 63),
            167, 144
        };

        std::string textureName = "poke_" + std::to_string(i + 1);
        DrawTextureEx(AssetManager::getTexture(textureName), { rect.x, rect.y - 10 }, 0, 2.0f, WHITE);

        bool prev = selectedPokemons[i];
        GuiToggle(rect, "", &selectedPokemons[i]);

        // Ограничение на максимум 3
        if (!prev && selectedPokemons[i]) {
            int count = 0;
            for (bool selected : selectedPokemons) if (selected) count++;
            if (count > 3) selectedPokemons[i] = false;
        }

        if (selectedPokemons[i]) selectedCount++;
    }

    // Кнопка "Продолжить"
    if (selectedCount == 3) {
        if (GuiButton({ 1027, 795, 276, 109 }, "")) {
            manager->selectedState.getPlayer().setDifficulty(difficultyActive);

            int index = 0;
            for (int i = 0; i < 10 && index < 3; i++) {
                if (!selectedPokemons[i]) continue;

                std::string pokeName = "poke_" + std::to_string(i + 1);

                // Берём напрямую по имени
                if (allPokes.count(pokeName)) {
                    manager->selectedState.getPlayer().setPokemon(index++, allPokes[pokeName]);
                }
            
            }

            switch (manager->selectedState.getPlayer().getDifficulty())
            {
            case Difficulty::EASY:
                manager->selectedState.getMap().generate(5, 5); break;
            case Difficulty::MEDIUM:
                manager->selectedState.getMap().generate(6, 4); break;
            case Difficulty::HARD:
                manager->selectedState.getMap().generate(7, 3); break;
            }

            manager->SetCurrent(GameScreen::MAP);
        }

       
    }
    else {
        GuiDisable();
        GuiButton({ 1027, 795, 276, 109 }, "");
        GuiEnable();
    }
}

void PokemonScreen::Draw()
{
    ClearBackground(RAYWHITE);

    DrawTexture(AssetManager::getTexture("pokemon"), 0, 0, WHITE);

}