#include "JsonConverters.h"

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