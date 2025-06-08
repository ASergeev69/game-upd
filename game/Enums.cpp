#include "Enums.h"

string to_string(pokemonType type) {
    switch (type) {
    case pokemonType::NORMAL:   return "Normal";
    case pokemonType::FIRE:     return "Fire";
    case pokemonType::WATER:    return "Water";
    case pokemonType::ELECTRIC: return "Electric";
    case pokemonType::BUG:      return "Bug";
    case pokemonType::POISON:   return "Poison";
    case pokemonType::AIR:      return "Air";
    default:                    return "Unknown";
    }
}

string to_string(Difficulty d) {
    switch (d) {
    case Difficulty::EASY:   return "Easy";
    case Difficulty::MEDIUM: return "Medium";
    case Difficulty::HARD:   return "Hard";
    default:                 return "Unknown";
    }
}

pokemonType typeFromString(const string& str) {
    if (str == "Fire")     return pokemonType::FIRE;
    if (str == "Water")    return pokemonType::WATER;
    if (str == "Electric") return pokemonType::ELECTRIC;
    if (str == "Bug")      return pokemonType::BUG;
    if (str == "Poison")   return pokemonType::POISON;
    if (str == "Air")      return pokemonType::AIR;
    else                   return pokemonType::NORMAL;
}