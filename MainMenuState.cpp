#include "MainMenuState.h"

#include <iostream>
#include <sstream>


void MainMenuState::InitVariables()
{
	
}

void MainMenuState::InitBackground()
{
	background.setSize(sf::Vector2f(window->getSize()));
	
	if (!bgTexture.loadFromFile("Resources/Images/mainmenu_bg.png"))
		throw "ERR::MAINMENUSTATE::NIE ZALADOWANO TEKSTURY MENU!";

	background.setTexture(&bgTexture);


	
}

void MainMenuState::InitFonts()
{
	if (!font.loadFromFile("Fonts/OpenSans-Regular.ttf"))
	{
		throw "ERR::MAINMENUSTATE::NIE ZALADOWANO CZCIONKI";
	}
}

void MainMenuState::InitButtons()
{
	buttons["GAME_STATE"] = new Button(200, 440, 320, 160,
		{
			"Resources/Images/menu_start.png",
			"Resources/Images/menu_start_hover.png",
			"Resources/Images/menu_start.png"
		});

	buttons["HELP_STATE"] = new Button(200, 635, 320, 160,
		{
			"Resources/Images/menu_help.png",
			"Resources/Images/menu_help_hover.png",
			"Resources/Images/menu_help.png"
		});
	
	buttons["EXIT_STATE"] = new Button(200, 830, 320, 160,
		{
			"Resources/Images/menu_quit.png",
			"Resources/Images/menu_quit_hover.png",
			"Resources/Images/menu_quit.png"
		});
}

MainMenuState::MainMenuState(sf::RenderWindow* window, std::stack<State*>* states) : State(window, states)
{
	m_StateName = "MAIN MENU";

	InitVariables();
	InitBackground();
	InitFonts();
	InitButtons();

	authorText.setFont(font);
	authorText.setString("Author: Lukasz Mysliwiec");
	authorText.setCharacterSize(18);
	authorText.setPosition(window->getSize().x - authorText.getGlobalBounds().width - 20, window->getSize().y - authorText.getGlobalBounds().height - 20);
}

MainMenuState::~MainMenuState()
{
	auto it = buttons.begin();
	for (it = buttons.begin(); it != buttons.end(); ++it)
	{
		delete it->second;
	}
}

void MainMenuState::Update(const float& dt)
{
	UpdateMousePositions();
	UpdateInput(dt);
	UpdateButtons();
}

void MainMenuState::UpdateInput(const float& dt)
{
	
}

void MainMenuState::UpdateButtons()
{
	for (auto &it : buttons)
	{
		it.second->Update(mousePosView);
	}

	if (buttons["GAME_STATE"]->isPressed())
		states->push(new GameState(window, states));

	if (buttons["HELP_STATE"]->isPressed())
		states->push(new HelpState(window, states));

	if (buttons["EXIT_STATE"]->isPressed())
		EndState();
}

void MainMenuState::OnStateQuit()
{
	State::OnStateQuit();
}

void MainMenuState::RenderButtons()
{
	for (auto& it : buttons)
	{
		it.second->Render(window);
	}
}

void MainMenuState::Render()
{
	window->draw(background);
	RenderButtons();

	sf::Text mouseText;
	mouseText.setPosition(10, 10);
	mouseText.setFont(font);
	mouseText.setCharacterSize(12);
	std::stringstream ss;
	ss << mousePosView.x << " " << mousePosView.y;
	mouseText.setString(ss.str());

	window->draw(mouseText);
	window->draw(authorText);
}

void MainMenuState::EndStateUpdate()
{
}
