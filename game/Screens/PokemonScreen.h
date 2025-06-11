#pragma once
#include "Screen.h"
#include "../Managers/Enums.h"
#include "../Pokemon/Pokemon.h"
#include <unordered_map>

class ScreenManager; // forward

class PokemonScreen : public Screen {
private:
    ScreenManager* manager;

    bool selectedPokemons[10] = { false };

    Difficulty difficultyActive = Difficulty::EASY;

    unordered_map<string, Pokemon> allPokes;
public:
    PokemonScreen(ScreenManager* manager);
    void Init() override;
    void Update() override;
    void Draw() override;
};