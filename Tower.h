#pragma once

#include "Enemy.h"

enum class TowerLevel { NONE = 0, WOODEN, WOODEN_PLUS, STONE };
enum class TowerHoverState { TWR_IDLE = 0, TWR_HOVER, TWR_ACTIVE };

struct TowerData
{
	float damage{};
	float range{};
	float reloadTime{};
	int upgradeCost{};
};

// Klasa pozwalaj¹ca tworzyæ wie¿e, potrzebna refaktoryzacja
class Tower
{
private:
	sf::Vector2f position;
	sf::Texture* textureSheet;

	sf::Sprite			towerSprite;
	sf::RectangleShape	shape;
	sf::CircleShape		rangeIndicator;

	TowerLevel level;
	TowerHoverState hoverState;

	float reloadTime = 1.f;
	float damage = 20.f;
	float range = 500.f;

	float acDt{};
	bool wasPressed = false;

	void InitVariables();
	void InitTower();
	void InitRangeIndicator();

	void UpdateSprite();

	std::map<TowerLevel, TowerData> levels{
			{ TowerLevel::NONE, {0.f, 0.f, 0.f, 200 } },
			{ TowerLevel::WOODEN, {20.f, 450.f, 1.f, 300} },
			{ TowerLevel::WOODEN_PLUS, {35.f, 550.f, 1.f, 500} },
			{ TowerLevel::STONE, {40.f, 650.f, .5f, 0} }
	};
public:
	Tower(sf::Vector2f position, sf::Texture* textureSheet);
	virtual ~Tower();

	void Update(const float& dt, const sf::Vector2f& mousePos);
	void UpdateMouse(const sf::Vector2f& mousePos);
	void Render(sf::RenderTarget* target);

	// Funkcje zwracaj¹ce stan wie¿y
	const sf::Vector2f& GetPosition() const { return towerSprite.getPosition(); }
	const TowerHoverState& GetHoverState() const { return hoverState; }
	const TowerLevel& GetLevel() const { return level; }
	const float& GetDamage() const { return damage; }
	const float& GetRange() const { return range; }
	const int& GetUpgradeCost() const { return levels.at(level).upgradeCost; }

	// Strza³
	void ShootAt(Enemy* pos);
	// Obrót wie¿y
	void LookAt(sf::Vector2f pos);
	// Podniesienie poziomu wie¿y
	void LevelUp();
};