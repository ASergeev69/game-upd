#pragma once
#include "raylib.h"
#include <unordered_map>
#include <string>	
#include <filesystem>

using std::string, std::unordered_map;

namespace fs = std::filesystem;

class AssetManager
{
private:
	static unordered_map<string, Texture2D> textures;
	static unordered_map<string, Music> sounds;
public:
	static Texture2D getTexture(const string& tName);
	static Music getSound(const string& mName);	

	static void loadTextures(const fs::path& directory);
	static void loadSounds(const fs::path& directory);
	static void loadStyles();


	static void unloadTextures();
	static void unloadSounds();
};