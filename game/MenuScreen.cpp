#include "MenuScreen.h"
#include "raygui.h"
#include "ScreenManager.h"9699

MenuScreen::MenuScreen(ScreenManager* mgr) : manager(mgr) {}

void MenuScreen::Init() {}

void MenuScreen::Update()
{
    if (GuiButton({ 300, 200, 200, 50 }, "")) {
        manager->SetCurrent(GameScreen::CHARACTER);
    }
}

void MenuScreen::Draw()
{
    ClearBackground(RAYWHITE);
    DrawText("Poke Adventure", 250, 100, 40, DARKBLUE);
}