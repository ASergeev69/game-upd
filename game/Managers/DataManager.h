#pragma once
#include <unordered_map>
#include <vector>
#include <string>
#include <filesystem>
#include "../Pokemon/Pokemon.h"
#include "../Game/Bot.h"
#include "../Map/Map.h"

using std::vector, std::unordered_map, std::string;
namespace fs = std::filesystem;


class DataManager
{
private:
	static unordered_map<string, Pokemon> allPokemons;
	static vector<Bot> allBots;

public:
	static void loadPokemons(fs::path directory);
	static void loadBots(fs::path directory);

	static const unordered_map<string, Pokemon>& getAllPokemons();
	static const vector<Bot>& getAllBots();
};