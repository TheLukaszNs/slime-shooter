#include "Tower.h"

const double PI = 3.1415;

void Tower::InitVariables()
{
	level = TowerLevel::NONE;
	hoverState = TowerHoverState::TWR_IDLE;
}

void Tower::InitTower()
{
	towerSprite.setPosition(position);
	towerSprite.setTexture(*textureSheet);
	towerSprite.setTextureRect(sf::IntRect(0, 0, 16, 16));
	towerSprite.setOrigin(towerSprite.getGlobalBounds().width / 2, towerSprite.getGlobalBounds().height / 2);
	towerSprite.setScale(10, 10);
}

void Tower::InitRangeIndicator()
{
	rangeIndicator.setFillColor(sf::Color(200, 20, 0, 50));
	rangeIndicator.setRadius(range);
	rangeIndicator.setOutlineColor(sf::Color(200, 20, 50, 255));
	rangeIndicator.setOutlineThickness(5.f);
	rangeIndicator.setOrigin(range, range);
	rangeIndicator.setPosition(towerSprite.getPosition());
}

void Tower::UpdateMouse(const sf::Vector2f& mousePos)
{
	hoverState = TowerHoverState::TWR_IDLE;
	
	if (towerSprite.getGlobalBounds().contains(mousePos))
	{
		hoverState = TowerHoverState::TWR_HOVER;

		if (sf::Mouse::isButtonPressed(sf::Mouse::Left) && !wasPressed)
		{
			wasPressed = true;
			hoverState = TowerHoverState::TWR_ACTIVE;
			printf("PRESSED\n");
		}
	}
	else
		wasPressed = false;
	
}

void Tower::UpdateSprite()
{
	const int offset = static_cast<int>(level) * 16;
	towerSprite.setTextureRect(sf::IntRect(offset, 0, 16, 16));
}

Tower::Tower(sf::Vector2f position, sf::Texture* textureSheet) : position(position), textureSheet(textureSheet)
{
	InitVariables();
	InitTower();
	InitRangeIndicator();
}

Tower::~Tower()
{
}

void Tower::Update(const float& dt, const sf::Vector2f& mousePos)
{
	acDt += dt;
}

void Tower::Render(sf::RenderTarget* target)
{
	if(hoverState == TowerHoverState::TWR_HOVER && level != TowerLevel::NONE)
		target->draw(rangeIndicator);
	
	target->draw(towerSprite);
}

void Tower::ShootAt(Enemy* enemy)
{
	if (acDt >= reloadTime)
	{
		acDt = 0.f;
		enemy->DealDamage(damage);
		printf("SHOOTING AT %f:%f AT %f DAMAGE\n", enemy->GetPosition().x, enemy->GetPosition().y, damage);
	}
}

void Tower::LookAt(sf::Vector2f pos)
{
	float dx = pos.x - position.x;
	float dy = pos.y - position.y;

	float rotation = atan2(dy, dx) * 180 / PI;

	towerSprite.setRotation(rotation + 90);
}

void Tower::LevelUp()
{
	if(level != TowerLevel::STONE)
	{
		level = static_cast<TowerLevel>(static_cast<int>(level) + 1);
		TowerData newLevel = levels.at(level);
		damage = newLevel.damage;
		range = newLevel.range;
		reloadTime = newLevel.reloadTime;

		printf("level: %i\n", level);
		
		rangeIndicator.setRadius(range);
		rangeIndicator.setOrigin(range, range);

		UpdateSprite();
	}
}
