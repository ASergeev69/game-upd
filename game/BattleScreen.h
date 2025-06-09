#pragma once
#include "Screen.h"

class ScreenManager;

class BattleScreen : public Screen {
private:
    ScreenManager* manager;
public:
    BattleScreen(ScreenManager* manager);
    void Init() override;
    void Update() override;
    void Draw() override;
};