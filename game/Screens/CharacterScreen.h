#pragma once
#include "Screen.h"

class ScreenManager; // forward

class CharacterScreen : public Screen {
private:
    ScreenManager* manager;
public:
    CharacterScreen(ScreenManager* manager);
    void Init() override;
    void Update() override;
    void Draw() override;
};