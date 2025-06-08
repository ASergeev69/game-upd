#include "GameState.h"
#include <iostream>
#include <fstream>
#include "JsonConverters.h"



using std::cerr, std::ofstream, std::ifstream;

bool saveGame(const GameState& state, const fs::path& path) {
    if (!fs::exists(path.parent_path())) {
        if (!fs::create_directories(path.parent_path())) {
            cerr << "ERROR: dir 1" << path.parent_path() << "\n";
            return false;
        }
    }

    ofstream out(path);
    if (!out.is_open()) {
        cerr << "ERROR: dir 2" << path << "\n";
        return false;
    }

    json j = state;
    out << j.dump(4);
    return true;
}

bool loadGame(GameState& state, const fs::path& path) {
    if (!fs::exists(path)) {
        cerr << "ERROR: dir 3" << path << "\n";
        return false;
    }

    ifstream in(path);
    if (!in.is_open()) {
        cerr << "ERROR: dir 4" << path << "\n";
        return false;
    }

    json j;
    in >> j;

    if (!j.contains("player") || !j.contains("map")) {
        cerr << "ERRO: Syntax (player/map)\n";
        return false;
    }

    state = j.get<GameState>();
    return true;
}

unordered_map<string, GameState> loadAllSaves(const fs::path& directory) {
    unordered_map<string, GameState> result;

    if (!fs::exists(directory) || !fs::is_directory(directory)) return result;

    for (const auto& file : fs::directory_iterator(directory)) {
        if (file.path().extension() == ".json") {
            ifstream in(file.path());
            if (!in.is_open()) continue;

            json j;
            in >> j;

            if (j.contains("player") && j.contains("map")) {
                GameState gs = j.get<GameState>();
                result[file.path().filename().string()] = gs;
            }
        }
    }

    return result;
}