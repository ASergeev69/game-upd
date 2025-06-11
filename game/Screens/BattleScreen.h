#pragma once
#include "Screen.h"
#include <vector>
#include "../Game/Bot.h"
#include "../Game/Battle.h"

class ScreenManager;

class BattleScreen : public Screen {
private:
    ScreenManager* manager;

    vector<Bot> allBots;
    Bot randomBot;
    Battle* currBattle = nullptr;

    bool isPlayerTurn = true;
    bool waitingEnemyAction = false;
    float enemyThinkTimer = 0.0f;
    int enemyStep = 0;
    int count = 0;
public:
    BattleScreen(ScreenManager* manager);
    void Init() override;
    void Update() override;
    void Draw() override;


    int GetRandomAliveEnemyIndex();

    int GetRandomMoveIndex();

};