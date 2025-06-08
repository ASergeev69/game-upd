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
	const std::string& getName() const { return name; }
	std::pair<int, int> getPos() const { return { x, y }; }
	const Pokemon* getTeam() const { return team; }

	void setPosition(int newX, int newY) { x = newX; y = newY; }
	void setName(const std::string& newName) { name = newName; }
	void setTeam(const Pokemon* newTeam)
	{
		for (int i = 0; i < 3; ++i)
			team[i] = newTeam[i];
	}
};