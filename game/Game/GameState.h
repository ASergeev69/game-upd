#pragma once
#include "Player.h"
#include "../Map/Map.h"

class GameState
{
private:
	Player player;

	Map map;
	int score = 0;
public:
	const Player& getPlayer() const { return player; }
	const Map& getMap() const { return map; }
	Player& getPlayer() { return player; }
	Map& getMap() { return map; }

	int getScore() const { return score; }

	void setScore(int s) { score = s; }
	void addScore(int value) { score += value; }

	bool movePlayer(int dX, int dY);

};

bool saveGame(const GameState& state, const fs::path& path);
bool loadGame(GameState& state, const fs::path& path);

std::unordered_map<std::string, GameState> loadAllSaves(const fs::path& directory);