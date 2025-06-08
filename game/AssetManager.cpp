#include "AssetManager.h"
#include "raygui.h"
#define RAYGUI_IMPLEMENTATION

unordered_map<string, Texture2D> AssetManager::textures;
unordered_map<string, Music> AssetManager::sounds;

Texture2D AssetManager::getTexture(const string& tName)
{
    return textures.at(tName);
}
Music AssetManager::getSound(const string& mName)
{
    return sounds.at(mName);
}

void AssetManager::loadTextures(const fs::path& directory)
{
    for (const auto& entry : fs::directory_iterator(directory)) {
        if (entry.path().extension() == ".png") {
            std::string name = entry.path().stem().string();
            textures[name] = LoadTexture(entry.path().string().c_str());
        }
    }
}
void AssetManager::loadSounds(const fs::path& directory)
{
    for (const auto& entry : fs::directory_iterator(directory)) {
        if (entry.path().extension() == ".mp3" || entry.path().extension() == ".ogg" || entry.path().extension() == ".wav") {
            std::string filename = entry.path().stem().string();     // без расширения
            std::string fullPath = entry.path().string();            // полный путь
            sounds[filename] = LoadMusicStream(fullPath.c_str());
        }
    }
}

void AssetManager::loadStyles()
{
    Color redTransparent = { 255, 0, 0, 100 };
    int redTransparentHex = (redTransparent.r << 24) | (redTransparent.g << 16) | (redTransparent.b << 8) | redTransparent.a;

    GuiSetStyle(DEFAULT, TEXT_SIZE, 30);
    GuiSetStyle(BUTTON, BASE_COLOR_NORMAL, 0x00000000);
    GuiSetStyle(BUTTON, BORDER_COLOR_NORMAL, 0x00000000);
    GuiSetStyle(BUTTON, TEXT_COLOR_NORMAL, 0x000000FF);
    GuiSetStyle(BUTTON, BASE_COLOR_FOCUSED, 0x11111120);
    GuiSetStyle(BUTTON, BORDER_COLOR_FOCUSED, 0x00000000);
    GuiSetStyle(BUTTON, TEXT_COLOR_FOCUSED, 0x000000FF);
    GuiSetStyle(BUTTON, BASE_COLOR_PRESSED, 0x00000040);
    GuiSetStyle(BUTTON, BORDER_COLOR_PRESSED, 0x00000000);
    GuiSetStyle(BUTTON, TEXT_COLOR_PRESSED, 0x000000FF);
    GuiSetStyle(BUTTON, BASE_COLOR_DISABLED, redTransparentHex);
    GuiSetStyle(BUTTON, BORDER_COLOR_DISABLED, 0x00000000);
    GuiSetStyle(BUTTON, TEXT_COLOR_DISABLED, 0xFFFFFFFF);



    GuiSetStyle(TEXTBOX, BASE_COLOR_NORMAL, 0x00000000);
    GuiSetStyle(TEXTBOX, BORDER_COLOR_NORMAL, 0x00000000);
    GuiSetStyle(TEXTBOX, TEXT_COLOR_NORMAL, 0x000000FF);
    GuiSetStyle(TEXTBOX, BASE_COLOR_FOCUSED, 0x11111120);
    GuiSetStyle(TEXTBOX, BORDER_COLOR_FOCUSED, 0x00000000);
    GuiSetStyle(TEXTBOX, TEXT_COLOR_FOCUSED, 0x000000FF);
    GuiSetStyle(TEXTBOX, BASE_COLOR_PRESSED, 0x00000040);
    GuiSetStyle(TEXTBOX, BORDER_COLOR_PRESSED, 0x00000000);
    GuiSetStyle(TEXTBOX, TEXT_COLOR_PRESSED, 0x000000FF);

    GuiSetStyle(TOGGLE, BASE_COLOR_NORMAL, 0x00000000);
    GuiSetStyle(TOGGLE, BORDER_COLOR_NORMAL, 0x00000000);
    GuiSetStyle(TOGGLE, TEXT_COLOR_NORMAL, 0x000000FF);
    GuiSetStyle(TOGGLE, BASE_COLOR_FOCUSED, 0x11111120);
    GuiSetStyle(TOGGLE, BORDER_COLOR_FOCUSED, 0x00000000);
    GuiSetStyle(TOGGLE, TEXT_COLOR_FOCUSED, 0x000000FF);
    GuiSetStyle(TOGGLE, BASE_COLOR_PRESSED, 0xFFB34720);
    GuiSetStyle(TOGGLE, BORDER_COLOR_PRESSED, 0x00000000);
    GuiSetStyle(TOGGLE, TEXT_COLOR_PRESSED, 0xFFB347FF);

    GuiSetStyle(LISTVIEW, BASE_COLOR_NORMAL, 0x00000000);
    GuiSetStyle(LISTVIEW, BORDER_COLOR_NORMAL, 0x00000000);
    GuiSetStyle(LISTVIEW, TEXT_COLOR_NORMAL, 0xF0F0F0);
    GuiSetStyle(LISTVIEW, BASE_COLOR_FOCUSED, 0x11111120);
    GuiSetStyle(LISTVIEW, BORDER_COLOR_FOCUSED, 0x00000000);
    GuiSetStyle(LISTVIEW, TEXT_COLOR_FOCUSED, 0xF0F0F0);
    GuiSetStyle(LISTVIEW, BASE_COLOR_PRESSED, 0x00000040);
    GuiSetStyle(LISTVIEW, BORDER_COLOR_PRESSED, 0x00000000);
    GuiSetStyle(LISTVIEW, TEXT_COLOR_PRESSED, 0xF0F0F0);

    GuiSetStyle(DEFAULT, BACKGROUND_COLOR, 0x0F193C80);
}


void AssetManager::unloadTextures()
{
    for (auto& [_, tex] : textures) {
        UnloadTexture(tex);
    }
    textures.clear();
}
void AssetManager::unloadSounds()
{
    for (auto& [_, m] : sounds) {
        UnloadMusicStream(m);
    }
    sounds.clear();
}