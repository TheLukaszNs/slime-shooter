#pragma once

#include <SFML/Graphics.hpp>

#include "Enemy.h"

class EnemySpawner
{
private:
	// Pozycja spawnera
	sf::Vector2f pos;
	// Szczeg�y przeciwnika
	EnemyData spawnedEnemyData;
	// Ilo�� przeciwnik�w
	unsigned int enemyNumber;
	// Czas pomi�dzy tworzeniem kolejnych przeciwnik�w
	float spawnCooldown;
	// Gdzie dodawa� przeciwnik�w?
	std::vector<Enemy>* container;

	float acDt{};
	
public:
	EnemySpawner(sf::Vector2f spawnerPos, EnemyData enemyData, unsigned int enemyNumber, std::vector<Enemy>* container, float cooldown = 1.f);
	virtual ~EnemySpawner();

	// Funckja odpowiedzialna za tworzenie kolejnych przeciwnik�w
	void SpawnEnemy();
	void Update(const float& dt);

	const unsigned int& GetRemainingEnemies() const { return enemyNumber; }
};

