#include "State.h"

#include <iostream>

State::State(sf::RenderWindow* window, std::stack<State*>* states) : window(window), states(states)
{
	std::cout << m_StateName << "::Initialized!\n";
}

State::~State()
{
}

void State::UpdateMousePositions()
{
	mousePosScreen = sf::Mouse::getPosition();
	mousePosWindow = sf::Mouse::getPosition(*window);
	mousePosView = window->mapPixelToCoords(sf::Mouse::getPosition(*window));
}

void State::OnStateQuit()
{
	std::cout << m_StateName << "::ClosingState!\n";
}
