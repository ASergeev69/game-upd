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
	MENU, CHARACTER, POKEMON, MAP, BATTLE
};

enum class Weather {
	CLEAR, RAIN, SUN
};

string to_string(pokemonType type);
string to_string(Difficulty d);

pokemonType typeFromString(const string& str);
Difficulty difficultyFromString(const string& str);