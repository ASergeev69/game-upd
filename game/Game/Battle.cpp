#include "Battle.h"

float GetTypeEffectiveness(pokemonType atk, pokemonType def)
{
    if (atk == pokemonType::WATER && def == pokemonType::FIRE) return 2.0f;
    if (atk == pokemonType::FIRE && def == pokemonType::WATER) return 0.5f;
    return 1.0f;
}

float GetWeatherMultiplier(pokemonType type, Weather weather)
{
    switch (weather) {
    case Weather::RAIN:
        return type == pokemonType::WATER ? 1.5f :
            type == pokemonType::FIRE ? 0.8f : 1.0f;
    case Weather::SUN:
        return type == pokemonType::FIRE ? 1.5f :
            type == pokemonType::WATER ? 0.8f : 1.0f;
    default:
        return 1.0f;
    }
}

void Battle::PlayerAttack(int moveIndex)
{
    Pokemon& attacker = player->getPokemon(playerIndex);
    Pokemon& defender = enemy->getPokemon(enemyIndex);

    const Move& move = attacker.getMove(moveIndex);
    float typeMultiplier = GetTypeEffectiveness(attacker.getType(), defender.getType());
    float weatherMultiplier = GetWeatherMultiplier(attacker.getType(), weather);

    int damage = static_cast<int>(move.damage * typeMultiplier * weatherMultiplier);
    defender.takeDamage(damage);
}

void Battle::EnemyAttack(int moveIndex)
{
    Pokemon& attacker = enemy->getPokemon(enemyIndex);
    Pokemon& defender = player->getPokemon(playerIndex);

    const Move& move = attacker.getMove(moveIndex);
    float typeMultiplier = GetTypeEffectiveness(attacker.getType(), defender.getType());
    float weatherMultiplier = GetWeatherMultiplier(attacker.getType(), weather);

    int damage = static_cast<int>(move.damage * typeMultiplier * weatherMultiplier);
    defender.takeDamage(damage);
}

bool Battle::isPlayerDead() const
{
    for (int i{}; i < 3; ++i)
    {
        if (player->getPokemon(i).getHP() > 0)
            return false;
    }

    return true;
}

bool Battle::isCurrentDead() const
{
    return player->getPokemon(playerIndex).getHP() <= 0;
}

bool Battle::isEnemyDead() const
{
    for (int i{}; i < 3; ++i)
    {
        if (enemy->getPokemon(i).getHP() > 0)
            return false;
    }

    return true;
}