#pragma once
#include <nlohmann/json.hpp>
#include "Pokemon.h"
#include "Move.h"

using nlohmann::json;

void to_json(json& j, const Pokemon& p);
void from_json(const json& j, Pokemon& p);

void to_json(json& j, const Move& m);
void from_json(const json& j, Move& m);