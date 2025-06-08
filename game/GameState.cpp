#include "GameState.h"

void GameState::movePlayer(int dx, int dy) {
    int oldX = player.getX();
    int oldY = player.getY();
    int newX = oldX + dx;
    int newY = oldY + dy;

    if (!map.inBounds(newX, newY)) return;

    Cell& targetCell = map.at(newX, newY);
    if (!targetCell.isWalkable()) return;

    // ��������� ����� ������
    switch (targetCell.getType()) {
    case mapType::ENEMY:

        break;
    case mapType::HEAL:
        player.healAll();
        break;
    default:
        break;
    }

    // ����� ������ ������
    map.at(oldX, oldY).setType(mapType::AIR);

    // ����������� ������
    player.setX(newX);
    player.setY(newY);

    // ���������� ������ � ����� ������
    map.at(newX, newY).setType(mapType::PLAYER);

    return;
}