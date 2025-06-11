#include "DataManager.h"
#include <fstream>
#include <iostream>
#include <nlohmann/json.hpp>
#include "../json/JsonConverters.h"
#include "AssetManager.h"

using nlohmann::json, std::cerr, std::ifstream;

unordered_map<string, Pokemon> DataManager::allPokemons;
vector<Bot> DataManager::allBots;

void DataManager::loadPokemons(fs::path path)
{
    std::ifstream file(path);
    if (!file.is_open()) {
        std::cerr << "ERROR: Dir open: " << path << std::endl;
        return;
    }

    json j;
    file >> j;

    for (auto& [name, data] : j.items()) {
        Pokemon p = data.get<Pokemon>();
        // ��� ����� ������������� � ����� � ������, �� ���� ������ ��� ��� � ���������� �������:
        if (p.getName().empty()) p.setName(name);

        // ���������� �������� (���� ���� "texture" ���� � JSON)
        if (data.contains("texture")) {
            std::string texName = data["texture"];
            p.setTexture(AssetManager::getTexture(texName));
        }

        allPokemons[name] = p;
    }
}

void DataManager::loadBots(fs::path filePath) {
    ifstream file(filePath);
    if (!file.is_open()) {
        cerr << "ERROR: Dir open: " << filePath << std::endl;
        return;
    }

    json j;
    file >> j;

    for (const auto& botData : j) {
        Bot bot;

        std::string name = botData.at("name");

        Pokemon team[3];
        for (int i = 0; i < 3; ++i) {
            Pokemon p = botData.at("team").at(i).get<Pokemon>();
            string texName = botData.at("team").at(i).at("texture");
            p.setTexture(AssetManager::getTexture(texName));
            team[i] = p;
        }

        bot.setName(name);
        bot.setTeam(team);

        allBots.push_back(bot);
    }
}

const unordered_map<string, Pokemon>& DataManager::getAllPokemons()
{
    return allPokemons;
}

const vector<Bot>& DataManager::getAllBots()
{
    return allBots;
}