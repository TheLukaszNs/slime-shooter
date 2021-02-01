#include "Button.h"

Button::Button(float x, float y, float width, float height, TexturePaths paths)
{
	buttonState = ButtonState::BTN_IDLE;
	
	shape.setPosition(sf::Vector2f(x, y));
	shape.setSize(sf::Vector2f(width, height));

	if(!idleTexture.loadFromFile(paths.idle) ||
		!hoverTexture.loadFromFile(paths.hover) ||
		!activeTexture.loadFromFile(paths.active))
	{
		throw "FAILED TO LOAD BUTTON TEXTURE!";
	}
	
	shape.setTexture(&idleTexture);
}

Button::~Button()
{
}

const bool Button::isPressed() const
{
	if (buttonState == ButtonState::BTN_ACTIVE)
		return true;

	return false;
}

void Button::Update(const sf::Vector2f& mousePos)
{
	buttonState = ButtonState::BTN_IDLE;
	
	if (shape.getGlobalBounds().contains(mousePos))
	{
		this->buttonState = ButtonState::BTN_HOVER;

		if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
			this->buttonState = ButtonState::BTN_ACTIVE;
	}

	switch(buttonState)
	{
		case ButtonState::BTN_IDLE:
			shape.setTexture(&idleTexture);
			break;
		case ButtonState::BTN_HOVER:
			shape.setTexture(&hoverTexture);
			break;
		case ButtonState::BTN_ACTIVE:
			shape.setTexture(&activeTexture);
			break;
		default:
			break;
	}
}

void Button::Render(sf::RenderTarget* target)
{
	target->draw(shape);
}
