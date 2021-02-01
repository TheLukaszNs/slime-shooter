#pragma once

#include "Tower.h"
#include "EnemySpawner.h"
#include "GUI.h"

// Klasa bêd¹ca "szablonem" ka¿dego poziomu w grze
class GameLevel
{
protected:
	sf::RenderWindow* window;
	std::vector<Tower> turrets;
	std::vector<Enemy> enemies;
	GUI* gui;

	sf::Texture levelTexture;
	sf::RectangleShape levelBackground;

	std::map<std::string, sf::Texture>* textures;

	int xp{};
	int money{};

	int lifesLeft = 3;
	bool hasWon{};

private:
	virtual void InitVariables() = 0;
	virtual void InitTurrets() = 0;

	void UpdateTower(const float& dt, const sf::Vector2f& mousePos, Tower& tower);
	void UpdateEnemies(const float& dt, const int& index);


public:
	GameLevel(sf::RenderWindow* window, std::map<std::string, sf::Texture>* textures, GUI* gui);
	virtual ~GameLevel();

	virtual void Render();
	virtual void Update(const float& dt, const sf::Vector2f& mousePos);
	// Destrukcja przeciwnika
	virtual void DestroyEnemy(int index);
	virtual void UpdateInput();
	// Koniec gry
	void EndGame();

	const int& GetLifesLeft() const { return lifesLeft; }
	const bool& GetHasWon() const { return hasWon; }
	
};

