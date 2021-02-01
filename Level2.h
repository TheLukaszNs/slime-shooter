#pragma once
#include "GameLevel.h"
class Level2 :
    public GameLevel
{
private:
	void InitVariables() override;
	void InitTurrets() override;

	EnemySpawner* levelSpawner;

	void InitGui();

public:
	Level2(sf::RenderWindow* window, std::map<std::string, sf::Texture>* textures, GUI* gui);
	virtual ~Level2();

	void Update(const float& dt, const sf::Vector2f& mousePos) override;
};

