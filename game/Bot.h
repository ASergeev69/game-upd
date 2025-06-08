#pragma once
#include <string>
#include <utility>
#include "Pokemon.h"

using std::pair;

class Bot
{
private:
	string name;
	int x = 0, y = 0;
	Pokemon team[3];
public:
	const string& getName() { return name; }
	pair<int, int> getPos() { return {x, y}; }
	Pokemon* getTeam() { return team; }

	void setPosition(int newX, int newY) { x = newX; y = newY; }
	void setName(const std::string& newName) { name = newName; }
	void setTeam(const Pokemon* newTeam)
	{
		for (int i = 0; i < 3; ++i)
			team[i] = newTeam[i];
	}
};