#include "EnemySpawner.h"

EnemySpawner::EnemySpawner(sf::Vector2f spawnerPos, EnemyData enemyData, unsigned int enemyNumber,
                           std::vector<Enemy>* container, float cooldown)
	: pos(spawnerPos), spawnedEnemyData(enemyData), enemyNumber(enemyNumber), spawnCooldown(cooldown),
	  container(container)
{
}

EnemySpawner::~EnemySpawner()
{
}

void EnemySpawner::SpawnEnemy()
{
	container->emplace_back(pos.x, pos.y, spawnedEnemyData);
	enemyNumber--;
}

void EnemySpawner::Update(const float& dt)
{
	acDt += dt;

	if (acDt >= spawnCooldown && enemyNumber > 0)
	{
		SpawnEnemy();
		acDt = 0.f;
	}
}
