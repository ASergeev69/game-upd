#pragma once
#include "Player.h"
#include "../Managers/Enums.h"
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

	int getPlayerIndex() { return playerIndex; }
	int getEnemyIndex() { return enemyIndex; }

	void setPlayerIndex(int index) { playerIndex = index; }
	void setEnemyIndex(int index) { enemyIndex = index; }

	void PlayerAttack(int moveIndex);
	void EnemyAttack(int moveIndex);

	bool isEnemyDead() const;
	bool isPlayerDead() const;

	bool isCurrentDead() const;
};

float GetTypeEffectiveness(pokemonType atk, pokemonType def);

float GetWeatherMultiplier(pokemonType type, Weather weather);