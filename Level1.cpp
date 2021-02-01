#include "Level1.h"

void Level1::InitVariables()
{
	if (!levelTexture.loadFromFile("./Resources/Images/Levels/l1.png"))
	{
		throw "LEVEL TEXTURE WAS NOT LOADED";
	}

	levelBackground.setTexture(&levelTexture);
	levelBackground.setSize(sf::Vector2f(window->getSize()));

	money = 900;
}

void Level1::InitTurrets()
{
	turrets.emplace_back(sf::Vector2f(418, 872), &textures->at("TOWERS_SHEET"));
	turrets.emplace_back(sf::Vector2f(1450, 210), &textures->at("TOWERS_SHEET"));
}

void Level1::InitGui()
{
	/*gui->AddText("XP: ", { 15, 0 }, 36, "TXT_XP");
	gui->AddText(std::to_string(xp), { 80, 0 }, 36, "TXT_XP_VALUE");

	gui->AddText(std::to_string(money), { 150, 50 }, 36, "TXT_MONEY_VALUE");*/
	
	gui->AddElement(new GuiElement(&textures->at("GUI_SHEET"), { 10, 10 }), "ELEM_MONEY");
	gui->AddText(std::to_string(money), { 94, 20 }, 36, "TXT_MONEY_VALUE");

	gui->AddElement(new GuiElement(&textures->at("GUI_SHEET"), { 10, 84 }, sf::IntRect(16, 0, 16, 16)), "ELEM_LIFE");
	gui->AddText(std::to_string(lifesLeft), { 94, 89 }, 36, "TXT_LIFES_VALUE");

	gui->AddElement(new GuiElement(&textures->at("SLIME"), { 10, 158 }), "ELEM_S_ICON");
	gui->AddText(std::to_string(enemies.size()), { 94, 158 }, 36, "TXT_LIFES_VALUE");

}

Level1::Level1(sf::RenderWindow* window, std::map<std::string, sf::Texture>* textures, GUI* gui) : GameLevel(window, textures, gui)
{
	levelSpawner = new EnemySpawner({ -10.f, 536.f }, {100.f, 10.f, {window->getSize().x + 10.f, 536.f}, &textures->at("SLIME") }, 10, &enemies, 1.5f);

	InitVariables();
	InitTurrets();
	InitGui();

}

Level1::~Level1()
{
	delete levelSpawner;
}

void Level1::Update(const float& dt, const sf::Vector2f& mousePos)
{
	if (lifesLeft <= 0)
		EndGame();
	else
	{
		GameLevel::Update(dt, mousePos);
		if (levelSpawner->GetRemainingEnemies() > 0)
			levelSpawner->Update(dt);
		else if (levelSpawner->GetRemainingEnemies() <= 0 && enemies.empty())
			hasWon = true;

		gui->UpdateText("TXT_LIFES_VALUE", std::to_string(lifesLeft));
		gui->UpdateText("TXT_MONEY_VALUE", std::to_string(money));
		gui->UpdateText("ELEM_S_VALUE", std::to_string(enemies.size()));

	}
}
