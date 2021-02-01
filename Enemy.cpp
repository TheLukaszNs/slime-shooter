#include "Enemy.h"

void Enemy::InitVariables()
{
	shape.setSize(sf::Vector2f(75, 75));

}

Enemy::Enemy(float x, float y, EnemyData data) : Entity(), enemyHP(data.hp), targetPos(data.targetPos)
{
	InitVariables();
	SetPosition(x, y);
	shape.setTexture(data.texture);
}

Enemy::~Enemy()
{
}

void Enemy::Update(const float& dt)
{
	sf::Vector2f dirVector = (targetPos - shape.getPosition());
	float mag = std::sqrt(dirVector.x * dirVector.x + dirVector.y * dirVector.y);
	sf::Vector2f dir = dirVector / mag;
	
	Move(dt, dir);
}

void Enemy::DealDamage(float amount)
{
	enemyHP -= amount;
}


