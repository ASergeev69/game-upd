#pragma once
#include "../Pokemon/Pokemon.h"
#include "../Managers/Enums.h"

class Player
{
private:
    std::string name;
    Pokemon team[3];
    Difficulty difficulty;
    int x = 6, y = 5;

public:
    const std::string& getName() const { return name; }
    Difficulty getDifficulty() const { return difficulty; }
    int getX() const { return x; }
    int getY() const { return y; }

    const Pokemon* getTeam() const { return team; }
    Pokemon* getTeam() { return team; }

    const Pokemon& getPokemon(int index) const { return team[index]; }
    Pokemon& getPokemon(int index) { return team[index]; }

    void setName(const std::string& newName) { name = newName; }
    void setDifficulty(Difficulty diff) { difficulty = diff; }
    void setX(int newX) { x = newX; }
    void setY(int newY) { y = newY; }
    void setPosition(int newX, int newY) { x = newX; y = newY; }

    void setTeam(const Pokemon* newTeam) {
        for (int i = 0; i < 3; ++i)
            team[i] = newTeam[i];
    }

    void healAll()
    { 
        team[0].setHP(team[0].getMaxHP()); 
        team[1].setHP(team[1].getMaxHP());
        team[2].setHP(team[2].getMaxHP());
    }

    void setPokemon(int index, const Pokemon& p) {
        if (index >= 0 && index < 3)
            team[index] = p;
    }
};