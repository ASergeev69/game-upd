#include "GameState.h"

bool GameState::movePlayer(int dx, int dy) {
    int oldX = player.getX();
    int oldY = player.getY();
    int newX = oldX + dx;
    int newY = oldY + dy;

    if (!map.inBounds(newX, newY)) return false;

    Cell& targetCell = map.at(newX, newY);

    // Обработка типов клеток
    switch (targetCell.getType()) {
    case mapType::ENEMY:
        return true;
        break;
    case mapType::HEAL:
        player.healAll();
        break;
    default:
        break;
    }

    if (!targetCell.isWalkable()) return false;

    // Сброс старой клетки
    map.at(oldX, oldY).setType(mapType::AIR);

    // Перемещение игрока
    player.setX(newX);
    player.setY(newY);

    // Назначение игрока в новую клетку
    map.at(newX, newY).setType(mapType::PLAYER);

    return false;
}