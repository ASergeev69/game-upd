#pragma once
#include "Player.h"
#include "Enums.h"
#include "Bot.h"
class Battle
{
private:
	Player* player;
	Bot* enemy;
	Weather weather = Weather::CLEAR;

	int playerIndex = 0;
	int enemyIndex = 0;
public:
	Battle(Player* player, Bot* enemy)
	{
		this->player = player;
		this->enemy = enemy;
	}

	void setPlayerIndex(int index) { playerIndex = index; }
	void setEnemyIndex(int index) { enemyIndex = index; }

	void PlayerAttack(int moveIndex);
	void EnemyAttack(int moveIndex);

	bool isEnemyDead() const;
	bool isPlayerDead() const;
};

float GetTypeEffectiveness(pokemonType atk, pokemonType def);

float GetWeatherMultiplier(pokemonType type, Weather weather);