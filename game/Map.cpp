#include <random>
#include <iostream>
#include "Map.h"
#include "DataManager.h"

using std::cerr, std::random_device, std::mt19937, std::vector, std::pair;

Map::Map() { grid.resize(height, std::vector<Cell>(width)); }

Cell& Map::at(int x, int y) { return grid[y][x]; }

const Cell& Map::at(int x, int y) const { return grid[y][x]; }


bool Map::isReachable(int startX, int startY) const {
    bool visited[100][100]{}; // максимум 100x100
    int w = width;
    int h = height;

    vector<pair<int, int>> frontier;
    frontier.push_back({ startX, startY });
    visited[startY][startX] = true;

    int reachable = 1;

    const int dx[] = { 0, 0, -1, 1 };
    const int dy[] = { -1, 1, 0, 0 };

    while (!frontier.empty()) {
        auto [x, y] = frontier.back();
        frontier.pop_back();

        for (int i = 0; i < 4; ++i) {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if (nx < 0 || ny < 0 || nx >= w || ny >= h) continue;
            if (visited[ny][nx]) continue;
            if (!grid[ny][nx].isWalkable()) continue;

            visited[ny][nx] = true;
            frontier.push_back({ nx, ny });
            ++reachable;
        }
    }

    int totalWalkable = 0;
    for (int y = 0; y < h; ++y)
        for (int x = 0; x < w; ++x)
            if (grid[y][x].isWalkable())
                ++totalWalkable;

    return reachable == totalWalkable;
}

void Map::generate(int enemyCount, int healCount)
{
    int centerX = width / 2;
    int centerY = height / 2;
    do {
        random_device rd;
        mt19937 rng(rd());

        for (int y = 0; y < height; ++y)
            for (int x = 0; x < width; ++x)
                grid[y][x] = Cell();

        grid[centerY][centerX].setType(mapType::PLAYER);
        grid[centerY][centerX].setTextureName("player");
        grid[centerY][centerX].setWalkable(true);

        std::uniform_int_distribution<> wallDist(0, 99);
        for (int y = 0; y < height; ++y) {
            for (int x = 0; x < width; ++x) {
                if (x == centerX && y == centerY) continue;

                if (wallDist(rng) < 20) {
                    grid[y][x].setType(mapType::WALL);
                    grid[y][x].setTextureName("wall");
                    grid[y][x].setWalkable(false);
                }
            }
        }

        int placedEnemies = 0;
        for (int attempts = 0; placedEnemies < enemyCount && attempts < 1000; ++attempts) {
            int x = rng() % width;
            int y = rng() % height;

            if (grid[y][x].getType() == mapType::AIR) {
                grid[y][x].setType(mapType::ENEMY);
                grid[y][x].setTextureName("enemy");
                grid[y][x].setWalkable(false);
                placedEnemies++;
            }
        }

        int placedHeals = 0;
        for (int attempts = 0; placedHeals < healCount && attempts < 1000; ++attempts) {
            int x = rng() % width;
            int y = rng() % height;

            if (grid[y][x].getType() == mapType::AIR) {
                grid[y][x].setType(mapType::HEAL);
                grid[y][x].setTextureName("heal");
                grid[y][x].setWalkable(true);
                placedHeals++;
            }
        }
    } while (!isReachable(centerX, centerY));
}

bool Map::inBounds(int x, int y) const {
    return x >= 0 && y >= 0 && x < width && y < height;
}