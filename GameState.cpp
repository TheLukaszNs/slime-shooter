#include "GameState.h"



void GameState::InitVariables()
{
	currentLevel = levels.front();
	pauseMenu = new PauseMenu(sf::Vector2f(window->getSize()));
	gui.SetFont(font);
}

void GameState::InitTextures()
{
	if(!textures["TOWERS_SHEET"].loadFromFile("Resources/Images/Entities/tower_sheet.png"))
		throw "FAILED TO LOAD TOWER SHEET";

	if(!textures["GUI_SHEET"].loadFromFile("Resources/Images/GUI/coin.png"))
		throw "FAILED TO LOAD GUI SHEET";

	if(!textures["SLIME"].loadFromFile("Resources/Images/Entities/slime.png"))
		throw "FAILED TO LOAD SLIME TEXTURE";

}

void GameState::InitFonts()
{
	if (!font.loadFromFile("Fonts/VCR.ttf"))
	{
		throw "ERR::MAINMENUSTATE::NIE ZALADOWANO CZCIONKI";
	}
}

void GameState::InitLevels()
{
	levels.push(new Level1(window, &textures, &gui));
	levels.push(new Level2(window, &textures, &gui));
}

GameState::GameState(sf::RenderWindow* window, std::stack<State*>* states) : State(window, states)
{
	InitFonts();
	InitTextures();
	InitLevels();
	InitVariables();
	m_StateName = "GAME STATE";
}

GameState::~GameState()
{
}

void GameState::Update(const float& dt)
{
	UpdateMousePositions();
	UpdateInput(dt);

	if(!isPaused)
	{
		if (levels.empty())
			shouldQuit = true;
		else
		{
			if (levels.front()->GetLifesLeft() <= 0 && !levels.front()->GetHasWon())
			{
				shouldQuit = true;
			}
			else if (levels.front()->GetHasWon())
			{
				delete levels.front();
				levels.pop();
			}
			else
				levels.front()->Update(dt, mousePosView);
		}
	}
	else
	{
		pauseMenu->Update(dt, mousePosView);
		if (pauseMenu->ShouldUnpause())
		{
			pauseMenu->ClearUnpause();
			isPaused = false;
		}
		
		if(pauseMenu->ShouldQuit())
		{
			pauseMenu->ClearUnpause();
			isPaused = false;
			shouldQuit = true;
		}
	}
}

void GameState::UpdateInput(const float& dt)
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
		isPaused = true;
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
		isPaused = false;

	if (!levels.empty())
		levels.front()->UpdateInput();

}

void GameState::Render()
{	
	if(isPaused)
		pauseMenu->Render(window);
	else
	{
		if (!levels.empty())
		{
			levels.front()->Render();
			gui.Render(window);
		}
	}


	
}

void GameState::EndStateUpdate()
{
}
