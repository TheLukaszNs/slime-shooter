#pragma once

#include "State.h"
#include "Level1.h"
#include "Level2.h"
#include "PauseMenu.h"
#include "GUI.h"
#include <queue>

class GameState
	: public State
{
private:
	GameLevel* currentLevel;
	GUI gui;
		
	std::queue<GameLevel*> levels;
	PauseMenu* pauseMenu;
	
	std::map<std::string, sf::Texture> textures;
	sf::Font font;

	bool isPaused{};

	void InitVariables();
	void InitTextures();
	void InitFonts();
	void InitLevels();

public:
	GameState(sf::RenderWindow* window, std::stack<State*>* states);
	virtual ~GameState();
	
	void Update(const float& dt) override;
	void UpdateInput(const float& dt) override;
	void Render() override;
	void EndStateUpdate() override;
};

