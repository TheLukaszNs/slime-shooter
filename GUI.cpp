#include "GUI.h"

#include <utility>

void GUI::SetFont(sf::Font newFont)
{
	font = newFont;
}

void GUI::AddText(const std::string& text, sf::Vector2f position, unsigned int size, const std::string& id)
{
	sf::Text newGuiText;
	newGuiText.setFont(font);
	newGuiText.setString(text);
	newGuiText.setPosition(position);
	newGuiText.setCharacterSize(size);
	newGuiText.setFillColor(sf::Color::White);

	printf("ADDED TEXT %s\n", text.c_str());
	
	guiTexts[id] = newGuiText;
}

void GUI::UpdateText(const std::string& id, const std::string& newText)
{
	if (guiTexts.count(id) > 0)
		guiTexts[id].setString(newText);
}

void GUI::AddElement(GuiElement* element, const std::string& id)
{
	guiElements[id] = element;
}

void GUI::Render(sf::RenderTarget* target)
{
	for(auto const& text : guiTexts)
		target->draw(text.second);

	for (auto const& element : guiElements)
		element.second->Render(target);
}
