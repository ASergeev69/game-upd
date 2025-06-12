#include "GameState.h"

bool GameState::movePlayer(int dx, int dy) {
    int oldX = player.getX();
    int oldY = player.getY();
    int newX = oldX + dx;
    int newY = oldY + dy;

    if (!map.inBounds(newX, newY)) return false;

    Cell& targetCell = map.at(newX, newY);

    switch (targetCell.getType()) {
    case mapType::ENEMY:
        map.at(oldX, oldY).setType(mapType::AIR);
        player.setX(newX);
        player.setY(newY);
        map.at(newX, newY).setType(mapType::PLAYER);
        return true;
        break;
    case mapType::HEAL:
        player.healAll();
        break;
    default:
        break;
    }

    if (!targetCell.isWalkable()) return false;

    map.at(oldX, oldY).setType(mapType::AIR);

    player.setX(newX);
    player.setY(newY);

    map.at(newX, newY).setType(mapType::PLAYER);

    return false;
}