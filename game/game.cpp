#include "raylib.h"
#include "Managers/Enums.h"
#include "Managers/ScreenManager.h"
#include "Screens/MenuScreen.h"
#include "Screens/CharacterScreen.h"
#include "Screens/PokemonScreen.h"
#include "Screens/MapScreen.h"
#include "Screens/BattleScreen.h"

ScreenManager screenManager;

int main() {
    InitWindow(1536, 1024, "Poke");
    InitAudioDevice();


    screenManager.Register(GameScreen::MENU, std::make_unique<MenuScreen>(&screenManager));/*
    screenManager.Register(GameScreen::CHARACTER, std::make_unique<CharacterScreen>(&screenManager));
    screenManager.Register(GameScreen::POKEMON, std::make_unique<PokemonScreen>(&screenManager));
    screenManager.Register(GameScreen::MAP, std::make_unique<MapScreen>(&screenManager));*/



    screenManager.SetCurrent(GameScreen::MENU);

    while (!WindowShouldClose()) {
        BeginDrawing();
        screenManager.Draw();

        screenManager.Update();
        EndDrawing();
    }

    CloseWindow();
    return 0;
}