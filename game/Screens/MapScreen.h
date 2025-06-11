#pragma once
#include "Screen.h"
#include <iostream>

class ScreenManager; // forward

class MapScreen : public Screen {
private:
    ScreenManager* manager;

    float x, y;

    std::string pos = "f";

    bool enemy = false;

public:
    MapScreen(ScreenManager* manager);
    void Init() override;
    void Update() override;
    void Draw() override;
};
