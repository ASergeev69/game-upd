#include "DataManager.h"
#include <fstream>
#include <iostream>
#include <nlohmann/json.hpp>
#include "AssetManager.h"

using nlohmann::json, std::cerr, std::ifstream;

unordered_map<string, Pokemon> DataManager::allPokemons;
vector<Bot> DataManager::allBots;

void DataManager::loadPokemons(fs::path directory) {
    ifstream file(directory);
    if (!file.is_open()) {
        cerr << "ERROR: Dir open: " << directory << std::endl;
        return;
    }

    json j;
    file >> j;

    for (auto& [name, data] : j.items()) {
        Pokemon p;
        p.setName(name);
        p.setType(typeFromString(data["type"]));
        p.setMaxHP(data["maxHP"]);
        p.setHP(data["HP"]);
        p.setExp(data["exp"]);
        p.setLevel(data["level"]);

        string texName = data["texture"];
        p.setTexture(AssetManager::getTexture(texName));

        for (const auto& m : data["moves"]) {
            Move move;
            move.name = m["name"];
            move.damage = m["damage"];
            p.addMove(move);
        }

        allPokemons[name] = p;
    }
}

void DataManager::loadBots(fs::path directory)
{

}

const unordered_map<string, Pokemon>& DataManager::getAllPokemons()
{

}

const vector<Bot>& DataManager::getAllBots()
{

}

Map& DataManager::getCurrentMap()
{

}