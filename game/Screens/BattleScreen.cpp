#include "BattleScreen.h"
#include "../Managers/Enums.h"
#include "raylib.h"
#include "raygui.h"
#include "../Managers/DataManager.h"
#include "../Managers/ScreenManager.h"
#include "../Game/Battle.h"
#include <cstdlib> 
#include <ctime> 

BattleScreen::BattleScreen(ScreenManager* mgr) : manager(mgr) {}

void BattleScreen::Init()
{
    std::srand(static_cast<unsigned int>(std::time(nullptr)));
    AssetManager::loadTextures("assets/battle");
    allBots = DataManager::getAllBots();

    randomBot = allBots[std::rand() % allBots.size()];

    currBattle = new Battle(&manager->selectedState.getPlayer(), &randomBot);
}

int BattleScreen::GetRandomAliveEnemyIndex() {
    std::vector<int> aliveIndices;

    for (int i = 0; i < 3; ++i) {
        if (randomBot.getPokemon(i).getHP() > 0) {
            aliveIndices.push_back(i);
        }
    }

    if (aliveIndices.empty()) return -1; // Все покемоны мертвы

    int r = GetRandomValue(0, aliveIndices.size() - 1);
    return aliveIndices[r];
}

int BattleScreen::GetRandomMoveIndex() {
    return GetRandomValue(0, 1); // допустим 2 атаки
}

void BattleScreen::Update()
{
    if (!currBattle->isPlayerDead() && !currBattle->isEnemyDead() && isPlayerTurn) {
        // Выбор активного покемона
        if (IsKeyPressed(KEY_Z)) currBattle->setPlayerIndex(0);
        if (IsKeyPressed(KEY_X)) currBattle->setPlayerIndex(1);
        if (IsKeyPressed(KEY_C)) currBattle->setPlayerIndex(2);

        // Атаки
        if ((IsKeyPressed(KEY_ONE) || GuiButton({ 933, 823, 270, 114 }, "")) && !currBattle->isCurrentDead()) {
            currBattle->PlayerAttack(0); // обычная атака
            isPlayerTurn = false;
            waitingEnemyAction = true;
            enemyThinkTimer = 0.0f;
            enemyStep = 0;
            count++;
            manager->selectedState.getPlayer().getPokemon(currBattle->getPlayerIndex()).addExp(10);
        }
        if ((IsKeyPressed(KEY_TWO) || GuiButton({ 1240, 823, 244, 114 }, "")) && count > 3 && !currBattle->isCurrentDead()) {
            count = 0;
            currBattle->PlayerAttack(1); // спецатака
            isPlayerTurn = false;
            waitingEnemyAction = true;
            enemyThinkTimer = 0.0f;
            enemyStep = 0;
        }
    }
    else if (!currBattle->isPlayerDead() && !currBattle->isEnemyDead() && waitingEnemyAction) {
        enemyThinkTimer += GetFrameTime();

        // Фаза выбора цели
        if (enemyStep == 0 && enemyThinkTimer > 1.6f) {
            currBattle->setEnemyIndex(GetRandomAliveEnemyIndex());
            enemyStep++;
        }
        // Фаза атаки
        else if (enemyStep == 1 && enemyThinkTimer > 1.2f) {
            int moveIndex = GetRandomMoveIndex(); // 0 или 1
            currBattle->EnemyAttack(moveIndex);
            waitingEnemyAction = false;
            isPlayerTurn = true;
        }
    }
    else if (currBattle->isEnemyDead())
        manager->SetCurrent(GameScreen::MAP);
    else if (currBattle->isPlayerDead())
        manager->SetCurrent(GameScreen::MENU);

}


void BattleScreen::Draw()
{
    ClearBackground(RAYWHITE);

    DrawTexture(AssetManager::getTexture("battle"), 0, 0, WHITE);

    float y = 770, y2 =45;

    for (int i = 0; i < 3; i++) {
        Pokemon& poke = manager->selectedState.getPlayer().getPokemon(i);
        float x = (i == 0 ? 71 : (i == 1 ? 371 : 642));
        float y_tex = y;

        DrawTextureEx(AssetManager::getTexture(poke.getName()), { x, y_tex }, 0, 2.0f, WHITE);

        DrawText(("Lvl: " + std::to_string(poke.getLevel())).c_str(), x + 20, y_tex + 150, 20, DARKGRAY);

        float hpRatio = (float)poke.getHP() / poke.getMaxHP();
        DrawRectangle(x, y_tex + 180, 120, 10, GRAY);
        DrawRectangle(x, y_tex + 180, (int)(120 * hpRatio), 10, GREEN);

        if (currBattle->getPlayerIndex() == i) {
            DrawRectangleLines(x - 6, y_tex + 145, 132, 55, GOLD);
        }
    }

    for (int i = 0; i < 3; i++) {
        Pokemon& poke = randomBot.getPokemon(i);
        float x = (i == 0 ? 743 : (i == 1 ? 1028 : 1314));
        float y_tex = y2;

        DrawTextureEx(AssetManager::getTexture(poke.getName()), { x, y_tex }, 0, 2.0f, WHITE);

        DrawText(("Lvl: " + std::to_string(poke.getLevel())).c_str(), x + 20, y_tex + 150, 20, DARKGRAY);

        float hpRatio = (float)poke.getHP() / poke.getMaxHP();
        DrawRectangle(x, y_tex + 180, 120, 10, GRAY);
        DrawRectangle(x, y_tex + 180, (int)(120 * hpRatio), 10, RED);

        if (currBattle->getEnemyIndex() == i) {
            DrawRectangleLines(x - 6, y_tex + 145, 132, 55, GOLD);
        }
    }
}