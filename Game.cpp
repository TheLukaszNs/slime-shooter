#include "Game.h"

#include <iostream>


void Game::InitStates()
{
	states.push(new MainMenuState(window, &states));
}

Game::Game()
{
	window = new sf::RenderWindow(sf::VideoMode::getDesktopMode(), "Projekt SFML", sf::Style::Fullscreen);
	InitStates();
}

Game::~Game()
{
	while(!states.empty())
	{
		delete states.top();
		states.pop();
	}
	
	delete window;
}

void Game::Run()
{
	while(window->isOpen())
	{
		UpdateDt();
		UpdateEvents();

		Update();
		Render();
	}
}

void Game::UpdateDt()
{
	deltaTime = dtClock.restart().asSeconds();
}

void Game::UpdateEvents()
{
	while (window->pollEvent(sfEvent))
	{
		if (sfEvent.type == sf::Event::Closed)
			window->close();
	}
}

void Game::Update()
{
	if (!states.empty())
	{
		states.top()->Update(deltaTime);

		if (states.top()->GetQuitStatus())
		{
			states.top()->OnStateQuit();
			delete states.top();
			states.pop();
		}
	}
	else
	{
		window->close();
	}
	
}

void Game::Render()
{
	window->clear(sf::Color::Black);

	if(!states.empty())
		states.top()->Render();
	
	window->display();
}
