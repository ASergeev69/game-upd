#include "JsonConverters.h"

void to_json(json& j, const Player& p) {
    j = json{
        {"name", p.getName()},
        {"difficulty", to_string(p.getDifficulty())},
        {"x", p.getX()},
        {"y", p.getY()},
        {"team", {p.getPokemon(0), p.getPokemon(1), p.getPokemon(2)}}
    };
}

void from_json(const json& j, Player& p) {
    p.setName(j.at("name").get<std::string>());
    p.setDifficulty(difficultyFromString(j.at("difficulty").get<std::string>()));
    p.setX(j.at("x").get<int>());
    p.setY(j.at("y").get<int>());

    auto teamJson = j.at("team");
    for (int i = 0; i < 3; ++i) {
        Pokemon poke = teamJson.at(i).get<Pokemon>();
        p.setPokemon(i, poke); // предполагается наличие setPokemon(i, Pokemon)
    }
}

void to_json(json& j, const Bot& b) {
    j = json{
        {"name", b.getName()},
        {"team", {
            b.getTeam()[0],
            b.getTeam()[1],
            b.getTeam()[2]
        }}
    };
}

void from_json(const json& j, Bot& b) {
    std::string name = j.at("name");

    Pokemon team[3];
    for (int i = 0; i < 3; ++i) {
        team[i] = j.at("team").at(i).get<Pokemon>();
    }

    b.setName(name);
    b.setTeam(team);
}

void to_json(json& j, const Move& m) {
    j = json{
        {"name", m.name},
        {"damage", m.damage}
    };
}

void from_json(const json& j, Move& m) {
    j.at("name").get_to(m.name);
    j.at("damage").get_to(m.damage);
}

void to_json(json& j, const Pokemon& p) {
    j = json{
        {"name", p.getName()},
        {"type", to_string(p.getType())},
        {"maxHP", p.getMaxHP()},
        {"HP", p.getHP()},
        {"exp", p.getExp()},
        {"level", p.getLevel()},
        {"moves", p.getMoves()}
    };
}

void from_json(const json& j, Pokemon& p) {
    p.setName(j.at("name"));
    p.setType(typeFromString(j.at("type")));
    p.setMaxHP(j.at("maxHP"));
    p.setHP(j.at("HP"));
    p.setExp(j.at("exp"));
    p.setLevel(j.at("level"));

    for (const auto& mj : j.at("moves")) {
        Move m = mj.get<Move>();
        p.addMove(m);
    }
}

void to_json(json& j, const Map& map) {
    std::vector<std::vector<mapType>> types;

    for (int y = 0; y < 10; ++y) {
        std::vector<mapType> row;
        for (int x = 0; x < 12; ++x) {
            row.push_back(map.at(x, y).getType());
        }
        types.push_back(row);
    }

    j = json{
        {"grid", types}
    };
}

void from_json(const json& j, Map& map) {
    const auto& types = j.at("grid").get<std::vector<std::vector<mapType>>>();

    for (int y = 0; y < 10; ++y) {
        for (int x = 0; x < 12; ++x) {
            map.at(x, y).setType(types[y][x]);
        }
    }
}

void to_json(json& j, const GameState& state) {
    j = json{
        {"player", state.getPlayer()},
        {"map", state.getMap()},
        {"score", state.getScore()}
    };
}

void from_json(const json& j, GameState& state) {
    Player player = j.at("player").get<Player>();
    Map map = j.at("map").get<Map>();
    int score = j.at("score").get<int>();
    int level = j.at("level").get<int>();

    state.getPlayer() = player;
    state.getMap() = map;
    state.setScore(score);
}