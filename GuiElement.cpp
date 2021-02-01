#include "GuiElement.h"

GuiElement::GuiElement(sf::Texture* texture, sf::Vector2f position, sf::IntRect textureRect) : texture(texture)
{
	sprite.setScale(4.f, 4.f);
	sprite.setTextureRect(textureRect);
	sprite.setTexture(*this->texture);
	sprite.setPosition(position);
}

GuiElement::~GuiElement()
{
}

void GuiElement::Render(sf::RenderTarget* target) const
{
	target->draw(sprite);
}
