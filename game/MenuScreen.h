#pragma once
#include "Screen.h"

class ScreenManager; // forward

class MenuScreen : public Screen {
private:
    ScreenManager* manager;
public:
    MenuScreen(ScreenManager* manager);
    void Init() override;
    void Update() override;
    void Draw() override;
};