#include "ScreenManager.h"

void ScreenManager::Register(GameScreen id, unique_ptr<Screen> screen) {
    screens[id] = std::move(screen);
}

void ScreenManager::SetCurrent(GameScreen id) {
    current = id;
    screens[current]->Init();
}

void ScreenManager::Init() {
    if (screens.contains(current))
        screens[current]->Init();
}

void ScreenManager::Update() {
    if (screens.contains(current))
        screens[current]->Update();
}

void ScreenManager::Draw() {
    if (screens.contains(current))
        screens[current]->Draw();
}