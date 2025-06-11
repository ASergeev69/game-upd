#pragma once
#include "Screen.h"

class ScreenManager; // forward

class CharacterScreen : public Screen {
private:
    ScreenManager* manager;
    int curr = 0;
    bool editMode = false;
    char name[64] = "";
public:
    CharacterScreen(ScreenManager* manager);
    void Init() override;
    void Update() override;
    void Draw() override;
};