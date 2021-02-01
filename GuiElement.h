#pragma once

#include <SFML/Graphics.hpp>

class GuiElement
{
private:
	sf::Texture* texture;
	sf::Sprite sprite;
	
public:
	GuiElement(sf::Texture* texture, sf::Vector2f position, sf::IntRect textureRect = sf::IntRect(0, 0, 16, 16));
	virtual ~GuiElement();

	void Update();
	void Render(sf::RenderTarget* target) const;
};

