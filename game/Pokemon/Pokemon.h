#pragma once
#include <vector>
#include <string>
#include "raylib.h"
#include "../Managers/Enums.h"
#include "Move.h"

using std::vector, std::string;

class Pokemon
{
private:
	string name;
	pokemonType type;
	Texture2D tex;

	int maxHP;
	int HP;
	int exp;
	int level;
	vector<Move> moves;
public:

    int getExpToNextLevel() const {
        return level * 50; 
    }

    void addExp(int amount) {
        exp += amount;

        while (exp >= getExpToNextLevel()) {
            exp -= getExpToNextLevel();
            level++;
            maxHP += 10;
            moves[0].damage += 0.5;
            moves[1].damage += 0.5;
            HP += 10;
        }
    }

    Move getMove(int index) { return moves.at(index); }
    void addMove(const Move& move) { moves.push_back(move); }
    void clearMoves() { moves.clear(); }

    void setTexture(Texture2D tex_) { tex = tex_; }
    const Texture2D& getTexture() const { return tex; }

    void setName(const string& name_) { name = name_; }
    const string& getName() const { return name; }

    void setType(pokemonType type_) { type = type_; }
    pokemonType getType() const { return type; }

    void setMaxHP(int value) { maxHP = value; }
    int getMaxHP() const { return maxHP; }

    void setHP(int value) { HP = value; }
    int getHP() const { return HP; }

    void setExp(int value) { exp = value; }
    int getExp() const { return exp; }

    void setLevel(int value) { level = value; }
    int getLevel() const { return level; }

    void setMoves(const vector<Move>& m) { moves = m; }
    const vector<Move>& getMoves() const { return moves; }

    void takeDamage(float dmg) { HP = std::max(0.0, HP - dmg*1.0); }
};