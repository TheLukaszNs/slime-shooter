#pragma once
#include "Entity.h"

// Szczeg�y przeciwnika (wykorzystywane g��wnie w innych miejscach)
struct EnemyData
{
	float hp;
	float damage;
	sf::Vector2f targetPos;
	sf::Texture* texture;
};

class Enemy :
    public Entity
{
private:
	
	float enemyHP;
	sf::Vector2f targetPos;

	void InitVariables();

public:
	Enemy(float x, float y, EnemyData data);
	virtual ~Enemy();

	void Update(const float& dt) override;
	// Funkcja zadaj�ca obra�enia
	void DealDamage(float amount);

	// Ile hp posiada jeszcze przeciwnik?
	const float& GetHP() const { return enemyHP; }
};

