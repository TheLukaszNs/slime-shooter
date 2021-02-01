#pragma once

#include <SFML/Graphics.hpp>

#include "Enemy.h"

class EnemySpawner
{
private:
	// Pozycja spawnera
	sf::Vector2f pos;
	// Szczegó³y przeciwnika
	EnemyData spawnedEnemyData;
	// Iloœæ przeciwników
	unsigned int enemyNumber;
	// Czas pomiêdzy tworzeniem kolejnych przeciwników
	float spawnCooldown;
	// Gdzie dodawaæ przeciwników?
	std::vector<Enemy>* container;

	float acDt{};
	
public:
	EnemySpawner(sf::Vector2f spawnerPos, EnemyData enemyData, unsigned int enemyNumber, std::vector<Enemy>* container, float cooldown = 1.f);
	virtual ~EnemySpawner();

	// Funckja odpowiedzialna za tworzenie kolejnych przeciwników
	void SpawnEnemy();
	void Update(const float& dt);

	const unsigned int& GetRemainingEnemies() const { return enemyNumber; }
};

