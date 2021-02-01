#pragma once
#include <SFML/Graphics.hpp>

// Klasa odpowiedzialna za obs³ugê ka¿dego obiektu w grze
// Ostatecznie potrzebna jest jej refaktoryzacja
class Entity
{
private:
	void InitVariables();
	

protected:
	sf::Texture* texture;
	sf::Sprite* sprite;
	sf::RectangleShape shape;

	float movementSpeed{};

public:
	Entity();
	virtual ~Entity();

	virtual void CreateSprite(sf::Texture* texture);
	
	virtual void Move(const float& dt, float x, float y);
	void Move(const float& dt, const sf::Vector2f& dir);
	virtual void SetPosition(float x, float y) { shape.setPosition(x, y); }
	virtual const sf::Vector2f& GetPosition() { return shape.getPosition(); }

	virtual void Update(const float& dt);
	virtual void Render(sf::RenderTarget* target);
	
};

