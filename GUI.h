#pragma once

#include "GuiElement.h"

// Funkcja odpowiedzialna za swego rodzaju GUI, jakoœ dzia³a
class GUI
{
private:
	std::map<std::string, sf::Text> guiTexts;
	std::map<std::string, GuiElement*> guiElements;

	sf::Font font{};

public:
	void SetFont(sf::Font font);

	// Funkcje odpowiadaj¹ce za obs³ugê tektu w GUI
	void AddText(const std::string& text, sf::Vector2f position, unsigned int size, const std::string& id);
	void UpdateText(const std::string& id, const std::string& newText);

	// Dodawanie elementu do GUI
	void AddElement(GuiElement* element, const std::string& id);

	// Wyœwietlanie wszystkich elementów i tekstu na ekran
	void Render(sf::RenderTarget* target);
};

