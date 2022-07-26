#pragma once
#include <SFML/Graphics.hpp>

class Ball;

class Paddle : sf::Drawable
{
public:
	enum class Side 
	{
		LEFT,
		RIGHT
	};

	Paddle(float x, float y, Side side);

	void HandleInput(const sf::RenderWindow& window);
	void Update();
	void draw(sf::RenderTarget& target, sf::RenderStates states = sf::RenderStates::Default) const override;
	friend void HandleCollisions(const Paddle& paddle, Ball& ball);
private:
	sf::RectangleShape m_shape_;
	sf::Vector2f m_dim_{ 20.f,80.f };
	sf::Vector2f m_velocity_{0.f,0.f};
	Side m_side_;
};


