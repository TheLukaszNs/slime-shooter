#include "GameLevel.h"

GameLevel::GameLevel(sf::RenderWindow* window, std::map<std::string, sf::Texture>* textures, GUI* gui) : window(window), gui(gui), textures(textures)
{
}

GameLevel::~GameLevel()
{
}

void GameLevel::Render()
{
	window->draw(levelBackground);
	
	for(auto &turret : turrets)
		turret.Render(window);
	
	for (auto& enemy : enemies)
		enemy.Render(window);
}

void GameLevel::UpdateTower(const float& dt, const sf::Vector2f& mousePos, Tower& tower)
{
	tower.UpdateMouse(mousePos);
		
	if (tower.GetHoverState() == TowerHoverState::TWR_ACTIVE && tower.GetUpgradeCost() <= money)
	{
		money -= tower.GetUpgradeCost();
		tower.LevelUp();
	}
	
	if(tower.GetLevel() != TowerLevel::NONE)
	{
		tower.Update(dt, mousePos);
			
		for (auto& enemy : enemies)
		{
			auto tPos = tower.GetPosition();
			auto ePos = enemy.GetPosition();

			const float mag = sqrt((tPos.x - ePos.x) * (tPos.x - ePos.x) + (tPos.y - ePos.y) * (tPos.y - ePos.y));
				
			if (mag < tower.GetRange())
			{
				tower.LookAt(enemy.GetPosition());
				tower.ShootAt(&enemy);
				break;
			}
		}
	}
}

void GameLevel::UpdateEnemies(const float& dt, const int& index)
{
	Enemy& enemy = enemies[index];

	if (enemy.GetPosition().x > window->getSize().x)
	{
		DestroyEnemy(index);
		lifesLeft--;
	}

	if (enemy.GetHP() <= 0)
	{
		DestroyEnemy(index);
		xp += 20;
		money += 50;
	}

	enemy.Update(dt);
}

void GameLevel::EndGame()
{
	hasWon = false;
}

void GameLevel::Update(const float& dt, const sf::Vector2f& mousePos)
{

	for (size_t i = 0; i < enemies.size(); i++)
		UpdateEnemies(dt, i);

	for (auto& tower : turrets)
		UpdateTower(dt, mousePos, tower);
}

void GameLevel::DestroyEnemy(int index)
{
	enemies.erase(enemies.begin() + index);
	
	
}

void GameLevel::UpdateInput()
{
}
