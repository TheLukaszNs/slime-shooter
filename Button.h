#pragma once

#include <SFML/Graphics.hpp>

enum class ButtonState { BTN_IDLE = 0, BTN_HOVER, BTN_ACTIVE };

struct TexturePaths
{
	const std::string& idle;
	const std::string& hover;
	const std::string& active;
};

class Button
{
private:
	// Stan przycisku
	ButtonState buttonState;
	
	sf::RectangleShape shape;

	// Tekstury
	sf::Texture idleTexture;
	sf::Texture hoverTexture;
	sf::Texture activeTexture;	

public:
	Button(float x, float y, float width, float height, TexturePaths paths);
	~Button();

	// Funckja zwracaj¹ca informacjê, czy przycisk jest wciœniêty
	const bool isPressed() const;

	void Update(const sf::Vector2f& mousePos);
	void Render(sf::RenderTarget* target);
};

