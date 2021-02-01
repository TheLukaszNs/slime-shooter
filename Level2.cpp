#include "Level2.h"

void Level2::InitVariables()
{
	if (!levelTexture.loadFromFile("./Resources/Images/Levels/l2.png"))
	{
		throw "LEVEL TEXTURE WAS NOT LOADED";
	}

	levelBackground.setTexture(&levelTexture);
	levelBackground.setSize(sf::Vector2f(window->getSize()));

	money = 900;
}

void Level2::InitTurrets()
{
	turrets.emplace_back(sf::Vector2f(418, 872), &textures->at("TOWERS_SHEET"));
	turrets.emplace_back(sf::Vector2f(740, 270), &textures->at("TOWERS_SHEET"));
}

void Level2::InitGui()
{
	gui->AddElement(new GuiElement(&textures->at("GUI_SHEET"), { 10, 10 }), "ELEM_MONEY");
	gui->AddText(std::to_string(money), { 94, 20 }, 36, "TXT_MONEY_VALUE");

	gui->AddElement(new GuiElement(&textures->at("GUI_SHEET"), { 10, 84 }, sf::IntRect(16, 0, 16, 16)), "ELEM_LIFE");
	gui->AddText(std::to_string(lifesLeft), { 94, 89 }, 36, "TXT_LIFES_VALUE");

	gui->AddElement(new GuiElement(&textures->at("SLIME"), { 10, 158 }), "ELEM_S_ICON");
	gui->AddText(std::to_string(levelSpawner->GetRemainingEnemies()), { 94, 174 }, 36, "ELEM_S_VALUE");

}

Level2::Level2(sf::RenderWindow* window, std::map<std::string, sf::Texture>* textures, GUI* gui) : GameLevel(window, textures, gui)
{
	levelSpawner = new EnemySpawner({ -10.f, 157.f }, { 100.f, 10.f, {window->getSize().x + 10.f, 1079.f}, &textures->at("SLIME") }, 10, &enemies, 1.5f);

	InitVariables();
	InitTurrets();
	InitGui();

}

Level2::~Level2()
{
	delete levelSpawner;
}

void Level2::Update(const float& dt, const sf::Vector2f& mousePos)
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
		gui->UpdateText("ELEM_S_VALUE", std::to_string(levelSpawner->GetRemainingEnemies()));
	}
}
