#pragma once

#include "MainMenuState.h"
#include "GameState.h"

// Klasa Game odpowiada za obs�ug� logiki gry
class Game
{
private:
	// Wska�nik do okna gry
	sf::RenderWindow* window;
	// Zegar czasu delta time, czyli tego pomi�dzy klatkami
	sf::Clock dtClock{};
	sf::Event sfEvent{};

	// Czas, kt�ry up�yn�� mi�dzy klatkami
	float deltaTime{};

	// TODO: Stany powinny by� obs�ugiwane w osobnym StateMachine!
	std::stack<State*> states{};

	// Inicjalizacja stan�w
	void InitStates();

public:
	Game();
	virtual ~Game();

	void Run();

private:
	// Aktualizacja Delta Time
	void UpdateDt();
	// Aktualizacja zdarze� SFML-a
	void UpdateEvents();
	// Aktualizacja logiki w danej klatce gry
	void Update();
	// Wy�wietlanie danej klatki
	void Render();
};

