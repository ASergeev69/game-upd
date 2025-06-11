#pragma once
#include "Screen.h"
#include <vector>
#include "../Game/Bot.h"

class ScreenManager;

class BattleScreen : public Screen {
private:
    ScreenManager* manager;

    vector<Bot> allBots;
    Bot randomBot;
public:
    BattleScreen(ScreenManager* manager);
    void Init() override;
    void Update() override;
    void Draw() override;
};