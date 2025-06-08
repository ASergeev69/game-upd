#pragma once
#include "Enums.h"
#include "AssetManager.h"

class Cell {
private:
    mapType type = mapType::AIR;
    std::string textureName = "air";
    bool isCanWalk = true;

public:
    Cell(mapType type_ = mapType::AIR)
        : type(type_), isCanWalk(type_ != mapType::WALL) {
        updateTextureName();
    }

    void updateTextureName() {
        switch (type) {
        case mapType::WALL: textureName = "wall"; break;
        case mapType::HEAL: textureName = "heal"; break;
        case mapType::ENEMY: textureName = "enemy"; break;
        case mapType::PLAYER: textureName = "player"; break;
        case mapType::AIR: default: textureName = "air"; break;
        }
    }

    mapType getType() const noexcept {
        return type;
    }

    const std::string& getTextureName() const noexcept {
        return textureName;
    }

    bool isWalkable() const noexcept {
        return isCanWalk;
    }

    void setType(mapType newType) {
        type = newType;
        updateTextureName();
        isCanWalk = (type != mapType::WALL);
    }

    void setTextureName(const std::string& name) {
        textureName = name;
    }

    void setWalkable(bool value) noexcept {
        isCanWalk = value;
    }

};