#pragma once
#include "Screen.h"

class ScreenManager; // forward

class PokemonScreen : public Screen {
private:
    ScreenManager* manager;
public:
    PokemonScreen(ScreenManager* manager);
    void Init() override;
    void Update() override;
    void Draw() override;
};