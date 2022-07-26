#pragma once
#include <SFML/Graphics.hpp>

struct Paddle : sf::RectangleShape
{
	enum class Side 
	{
		LEFT,
		RIGHT
	};

	Paddle(float x, float y, Side side);

	void HandleInput(const std::unique_ptr<sf::RenderWindow>& p_window);
	void Update();
	void Draw();

	sf::Vector2f m_dim_{ 20.f,80.f };
	sf::Vector2f m_velocity_;
	Side m_side_;
};


