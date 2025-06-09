#pragma once
#include "Enums.h"
#include "Screen.h"
#include <unordered_map>
#include <memory>

using std::unordered_map, std::unique_ptr;

class ScreenManager
{
private:
	unordered_map<GameScreen, unique_ptr<Screen>> screens;
	GameScreen current;
public:
    void Register(GameScreen id, unique_ptr<Screen> screen);
    void SetCurrent(GameScreen id);

    void Init();
    void Update();
    void Draw();
};