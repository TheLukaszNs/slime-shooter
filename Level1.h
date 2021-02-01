#pragma once

#include "GameLevel.h"

class Level1 :
    public GameLevel
{
private:
	void InitVariables() override;
	void InitTurrets() override;

	EnemySpawner* levelSpawner;

	void InitGui();

public:
	Level1(sf::RenderWindow* window, std::map<std::string, sf::Texture>* textures, GUI* gui);
	virtual ~Level1();

	void Update(const float& dt, const sf::Vector2f& mousePos) override;
};

