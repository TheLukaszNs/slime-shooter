#pragma once

#include <SFML/Graphics.hpp>

#include "Button.h"

class PauseMenu
{
private:
	sf::RectangleShape background;
	
	std::map<std::string, sf::Texture> textures;
	std::map<std::string, Button*> buttons;
	
	sf::Vector2f menuSize;
	
	bool shouldUnpause{};
	bool shouldQuit{};

	void InitTextures();
	void InitButtons();


public:
	PauseMenu(sf::Vector2f menuSize);
	virtual ~PauseMenu();

	void Update(const float& dt, const sf::Vector2f& mousePos);
	void Render(sf::RenderTarget* target);

	const bool& ShouldUnpause() const { return shouldUnpause; }
	const bool& ShouldQuit() const { return shouldQuit; }
	
	void ClearUnpause() { shouldUnpause = false; shouldQuit = false; }
};

