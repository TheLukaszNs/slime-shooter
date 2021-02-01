#pragma once

#include "State.h"

class HelpState :
    public State
{
private:
	sf::RectangleShape background;
	sf::Texture bgTexture;
	
	void InitTextures();
public:
	HelpState(sf::RenderWindow* window, std::stack<State*>* states);

	void Update(const float& dt) override;
	void Render() override;
	void UpdateInput(const float& dt) override;
	void EndStateUpdate() override;
};

