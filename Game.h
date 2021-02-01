#pragma once

#include "MainMenuState.h"
#include "GameState.h"

// Klasa Game odpowiada za obs³ugê logiki gry
class Game
{
private:
	// WskaŸnik do okna gry
	sf::RenderWindow* window;
	// Zegar czasu delta time, czyli tego pomiêdzy klatkami
	sf::Clock dtClock{};
	sf::Event sfEvent{};

	// Czas, który up³yn¹³ miêdzy klatkami
	float deltaTime{};

	// TODO: Stany powinny byæ obs³ugiwane w osobnym StateMachine!
	std::stack<State*> states{};

	// Inicjalizacja stanów
	void InitStates();

public:
	Game();
	virtual ~Game();

	void Run();

private:
	// Aktualizacja Delta Time
	void UpdateDt();
	// Aktualizacja zdarzeñ SFML-a
	void UpdateEvents();
	// Aktualizacja logiki w danej klatce gry
	void Update();
	// Wyœwietlanie danej klatki
	void Render();
};

