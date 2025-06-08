#include "JsonConverters.h"

void to_json(json& j, const Bot& b) {
    j = json{
        {"name", b.getName()},
        {"x", b.getPos().first},
        {"y", b.getPos().second},
        {"team", {
            b.getTeam()[0],
            b.getTeam()[1],
            b.getTeam()[2]
        }}
    };
}

void from_json(const json& j, Bot& b) {
    std::string name = j.at("name");
    int x = j.at("x");
    int y = j.at("y");

    Pokemon team[3];
    for (int i = 0; i < 3; ++i) {
        team[i] = j.at("team").at(i).get<Pokemon>();
    }

    b.setName(name);
    b.setPosition(x, y);
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