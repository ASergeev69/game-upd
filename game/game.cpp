#include "ScreenManager.h"
#include "raylib.h"
#include "Enums.h"
#include "MenuScreen.h"
#include "CharacterScreen.h"
#include "PokemonScreen.h"
#include "MapScreen.h"
#include "BattleScreen.h"

ScreenManager screenManager;

int main() {
    InitWindow(800, 600, "Poke");

    screenManager.Register(GameScreen::MENU, std::make_unique<MenuScreen>(&screenManager));
    screenManager.Register(GameScreen::CHARACTER, std::make_unique<CharacterScreen>(&screenManager));
    screenManager.Register(GameScreen::POKEMON, std::make_unique<PokemonScreen>(&screenManager));
    screenManager.Register(GameScreen::MAP, std::make_unique<MapScreen>(&screenManager));
    // зарегистрируй все сцены

    screenManager.SetCurrent(GameScreen::MENU);

    while (!WindowShouldClose()) {
        BeginDrawing();
        screenManager.Update();

        screenManager.Draw();
        EndDrawing();
    }

    CloseWindow();
    return 0;
}