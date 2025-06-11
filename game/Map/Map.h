#pragma once
#include "Cell.h"

using std::vector;

class Map
{
private:
	int width = 10;
	int height = 9;
	vector<vector<Cell>> grid;

public:
	Map();

	Cell& at(int x, int y);
	const Cell& at(int x, int y) const;
	bool inBounds(int x, int y) const;

	vector<vector<Cell>>& getGrid() { return grid; }


	void generate(int enemyCount, int healCount);
	bool isReachable(int startX, int startY) const;
};