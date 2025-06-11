#pragma once
#include "raylib.h"
#include "raygui.h"
#include "../Game/GameState.h"

class Screen {
protected:
    GameState selectedState;
    bool showSettings = false;
    float settingsVolume = 50.0f;
    bool settingsSaveRequested = false;
    bool settingsExitRequested = false;

    bool isInMenu = true;


    Rectangle windowBounds = { 800, 199, 400, 300 };;

    Rectangle volumeSlider = { windowBounds.x + 40, windowBounds.y + 60, 320, 20 };
    Rectangle saveButton = { windowBounds.x + 100, windowBounds.y + 110, 200, 40 };
    Rectangle exitButton = { windowBounds.x + 100, windowBounds.y + 170, 200, 40 };
    Rectangle closeButton = { windowBounds.x + 370, windowBounds.y + 10, 20, 20 };

    std::string getTimestampedSaveName() {
        time_t now = time(nullptr);
        tm* lt = localtime(&now);

        std::ostringstream oss;
        oss << "save_"
            << std::put_time(lt, "%Y-%m-%d_%H-%M-%S")
            << ".json";

        return oss.str();
    }
public:
    virtual void Init() = 0;
    virtual void Update() = 0;
    virtual void Draw() = 0;
    virtual ~Screen() = default;

    bool DrawSettingsPopup() {
        if (!showSettings) return false;

        DrawRectangle(0, 0, GetScreenWidth(), GetScreenHeight(), Fade(BLACK, 0.5f));

        GuiWindowBox(windowBounds, "Settings");


        GuiSlider(volumeSlider, "0", "100", &settingsVolume, 0, 100);
        SetMasterVolume(settingsVolume / 100.0f);

        if (GuiButton(exitButton, "Leave game")) {
            CloseWindow();
        }

        if (CheckCollisionPointRec(GetMousePosition(), closeButton) && IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
            showSettings = false;
        }

        if (IsKeyPressed(KEY_ESCAPE)) {
            showSettings = false;
        }

        return true;
    }

};