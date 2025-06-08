#pragma once
#include <nlohmann/json.hpp>
#include "Pokemon.h"
#include "Move.h"
#include "Player.h"
#include "GameState.h"
#include "Bot.h"

using nlohmann::json;

void to_json(json& j, const Map& map);
void from_json(const json& j, Map& map);

void to_json(json& j, const GameState& state);
void from_json(const json& j, GameState& state);


void to_json(json& j, const Pokemon& p);
void from_json(const json& j, Pokemon& p);

void to_json(json& j, const Move& m);
void from_json(const json& j, Move& m);

void to_json(json& j, const Player& p);
void from_json(const json& j, Player& p);

void to_json(json& j, const Bot& b);
void from_json(const json& j, Bot& b);