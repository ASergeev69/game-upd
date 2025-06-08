#pragma once
#include <vector>
#include <string>
#include "raylib.h"
#include "Enums.h"
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

    void addMove(const Move& move) { moves.push_back(move); }
    void clearMoves() { moves.clear(); }

    void setTexture(Texture2D tex_) { tex = tex_; }
    const Texture2D& getTexture() const { return tex; }

    void setName(const std::string& name_) { name = name_; }
    const std::string& getName() const { return name; }

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

    void setMoves(const std::vector<Move>& m) { moves = m; }
    const std::vector<Move>& getMoves() const { return moves; }
};