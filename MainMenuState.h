#pragma once

#include "GameState.h"
#include "HelpState.h"
#include "Button.h"

class MainMenuState final:
    public State
{
private:
	sf::Texture bgTexture;
	
	sf::RectangleShape background;
	sf::Font font;
	sf::Text authorText;

	std::map<std::string, Button*> buttons;

	void InitVariables();
	void InitBackground();
	void InitFonts();
	void InitButtons();
public:
	MainMenuState(sf::RenderWindow* window, std::stack<State*>* states);
	virtual ~MainMenuState();
	
	void Update(const float& dt) override;
	void UpdateInput(const float& dt) override;
	void UpdateButtons();
	void RenderButtons();
	void Render() override;
	void EndStateUpdate() override;
	void OnStateQuit() override;
};

