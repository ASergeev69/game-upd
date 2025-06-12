#include "raylib.h"
#include "Managers/Enums.h"
#include "Managers/ScreenManager.h"
#include "Screens/MenuScreen.h"
#include "Screens/CharacterScreen.h"
#include "Screens/PokemonScreen.h"
#include "Screens/MapScreen.h"
#include "Managers/DataManager.h"
#include "Screens/BattleScreen.h"
#include "Screens/WinScreen.h"
#include <iostream>

ScreenManager screenManager;

int main() {
    InitWindow(1536, 1024, "Poke");
    SetExitKey(0);
    InitAudioDevice();


    screenManager.Register(GameScreen::MENU, std::make_unique<MenuScreen>(&screenManager));
    screenManager.Register(GameScreen::CHARACTER, std::make_unique<CharacterScreen>(&screenManager));
    screenManager.Register(GameScreen::POKEMON, std::make_unique<PokemonScreen>(&screenManager));
    screenManager.Register(GameScreen::MAP, std::make_unique<MapScreen>(&screenManager));
    screenManager.Register(GameScreen::BATTLE, std::make_unique<BattleScreen>(&screenManager));
    screenManager.Register(GameScreen::WIN, std::make_unique<WinScreen>(&screenManager));


    screenManager.SetCurrent(GameScreen::MENU);

    while (!WindowShouldClose())
    {
        BeginDrawing();
        screenManager.Draw();

        screenManager.Update();
        EndDrawing();
    }

    CloseWindow();
    return 0;
}