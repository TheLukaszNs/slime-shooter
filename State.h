#pragma once

#include <stack>
#include <SFML/Graphics.hpp>

class State
{
protected:
	std::stack<State*>* states;
	sf::RenderWindow* window;
	std::string m_StateName = "UNNAMED STATE";

	// Pozycje wskaŸnika myszy
	sf::Vector2i mousePosScreen;
	sf::Vector2i mousePosWindow;
	sf::Vector2f mousePosView;

	// Czy dany stan powinien zostaæ opuszczony?
	bool shouldQuit{false};

public:
	State(sf::RenderWindow* window, std::stack<State*>* states);
	virtual ~State();

	// Aktualizacja danego stanu
	virtual void Update(const float& dt) = 0;
	// Wyœwietlanie danego stany
	virtual void Render() = 0;
	// Aktualizacja klawiatury
	virtual void UpdateInput(const float& dt) = 0;
	// Aktualizacja myszki
	virtual void UpdateMousePositions();

	virtual void EndStateUpdate() = 0;
	// Prosta metoda koñcz¹ca stan
	void EndState() { shouldQuit = true; }

	// Co powinno wydarzyæ siê po opuszczeniu stanu (pierowtnym pomys³em by³ zapis)
	virtual void OnStateQuit();
	const bool& GetQuitStatus() const { return shouldQuit; }
};

