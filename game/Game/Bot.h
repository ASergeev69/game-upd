#pragma once
#include <string>
#include <utility>
#include "../Pokemon/Pokemon.h"

class Bot
{
private:
	string name;
	Pokemon team[3];
public:
	const std::string& getName() const { return name; }
	const Pokemon* getTeam() const { return team; }

	const Pokemon& getPokemon(int index) const { return team[index]; }
	Pokemon& getPokemon(int index) { return team[index]; }

	void setName(const std::string& newName) { name = newName; }
	void setTeam(const Pokemon* newTeam)
	{
		for (int i = 0; i < 3; ++i)
			team[i] = newTeam[i];
	}
};