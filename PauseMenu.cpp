#include "PauseMenu.h"

void PauseMenu::InitTextures()
{
	if (!textures["PAUSE_BG"].loadFromFile("Resources/Images/pausemenu_bg.png"))
		throw "FAILED TO LOAD PAUSE MENU BG";
}

void PauseMenu::InitButtons()
{
	buttons["UNPAUSE"] = new Button(1410, 640, 320, 160,
		{
			"Resources/Images/menu_start.png",
			"Resources/Images/menu_start_hover.png",
			"Resources/Images/menu_start.png"
		});

	buttons["QUIT"] = new Button(1410, 840, 320, 160,
		{
			"Resources/Images/menu_quit.png",
			"Resources/Images/menu_quit_hover.png",
			"Resources/Images/menu_quit.png"
		});
}

PauseMenu::PauseMenu(sf::Vector2f menuSize) : menuSize(menuSize)
{
	InitTextures();
	InitButtons();
	
	background.setSize(menuSize);
	background.setTexture(&textures.at("PAUSE_BG"));
}

PauseMenu::~PauseMenu()
{
	for (auto& it : buttons)
		delete it.second;
}

void PauseMenu::Update(const float& dt, const sf::Vector2f& mousePos)
{
	for (auto& it : buttons)
	{
		it.second->Update(mousePos);
	}


	if(buttons["UNPAUSE"]->isPressed())
	{
		shouldUnpause = true;
	}
	if (buttons["QUIT"]->isPressed())
	{
		shouldQuit = true;
	}
}

void PauseMenu::Render(sf::RenderTarget* target)
{
	target->draw(background);

	for (auto& it : buttons)
	{
		it.second->Render(target);
	}
}
