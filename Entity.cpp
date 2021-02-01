#include "Entity.h"

void Entity::InitVariables()
{
	texture = nullptr;
	sprite = nullptr;
	movementSpeed = 100.f;
}

Entity::Entity()
{
	InitVariables();
	
}

Entity::~Entity()
{
	delete sprite;
}

void Entity::CreateSprite(sf::Texture* texture)
{
	this->texture = texture;
	sprite->setTexture(*texture);
}

void Entity::Move(const float& dt, const float x, const float y)
{
	if(sprite)
		sprite->move(x * movementSpeed * dt, y * movementSpeed * dt);
	else
		shape.move(x * movementSpeed * dt, y * movementSpeed * dt);
}

void Entity::Move(const float& dt, const sf::Vector2f& dir)
{
	if(sprite)
		sprite->move(dir.x * movementSpeed * dt, dir.y * movementSpeed * dt);
	else
		shape.move(dir.x * movementSpeed * dt, dir.y * movementSpeed * dt);
}

void Entity::Update(const float& dt)
{
}

void Entity::Render(sf::RenderTarget* target)
{
	if (sprite)
		target->draw(*sprite);
	else
		target->draw(shape);
}
