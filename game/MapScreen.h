#pragma once
#include "Screen.h"

class ScreenManager; // forward

class MapScreen : public Screen {
private:
    ScreenManager* manager;
public:
    MapScreen(ScreenManager* manager);
    void Init() override;
    void Update() override;
    void Draw() override;
};