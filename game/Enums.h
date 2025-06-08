#pragma once
#include <string>

using std::string;

enum class pokemonType {
	NORMAL, FIRE, WATER, ELECTRIC, BUG, POISON, AIR
};

enum class mapType {
	AIR, WALL, PLAYER, ENEMY, HEAL
};

enum class Difficulty {
	EASY, MEDIUM, HARD
};

enum class GameScreen {
	MENU, CHARACTER_SELECT, POKEMON_SELECT, GAMEPLAY, BATTLE
};

string to_string(pokemonType type);
string to_string(Difficulty d);

pokemonType typeFromString(const string& str);
Difficulty difficultyFromString(const string& str);