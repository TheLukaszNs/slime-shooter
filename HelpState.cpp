#include "HelpState.h"

void HelpState::InitTextures()
{
	if(!bgTexture.loadFromFile("Resources/Images/helpmenu_bg.png"))
	{
		throw "FAILED TO LOAD HELP MENU BG";
	}
}

HelpState::HelpState(sf::RenderWindow* window, std::stack<State*>* states) : State(window, states)
{
	m_StateName = "HELP STATE";

	InitTextures();

	background.setSize(sf::Vector2f(window->getSize()));
	background.setTexture(&bgTexture);
}

void HelpState::Update(const float& dt)
{
	UpdateInput(dt);
}

void HelpState::Render()
{
	window->draw(background);
}

void HelpState::UpdateInput(const float& dt)
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
		EndState();
}

void HelpState::EndStateUpdate()
{
}
