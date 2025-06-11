#pragma once
#include "../Pokemon/Pokemon.h"
#include "../Managers/Enums.h"

class Player
{
private:
    std::string name;
    Pokemon team[3];
    Difficulty difficulty;
    int skinId = 0;
    int x = 5, y = 4;

public:
    std::string getName() const { return name; }
    Pokemon* getTeam() { return team; }
    Difficulty getDifficulty() const { return difficulty; }
    int getSkinId() const { return skinId; }
    int getX() const { return x; }
    int getY() const { return y; }

    // Сеттеры
    void setName(const std::string& n) { name = n; }
    void setTeam(const Pokemon(&t)[3]) { for (int i = 0; i < 3; ++i) team[i] = t[i]; }
    void setDifficulty(Difficulty d) { difficulty = d; }
    void setSkinId(int id) { skinId = id; }
    void setX(int newX) { x = newX; }
    void setY(int newY) { y = newY; }
    void setPosition(int newX, int newY) { x = newX; y = newY; }

    const Pokemon& getPokemon(int index) const { return team[index]; }
    Pokemon& getPokemon(int index) { return team[index]; }

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