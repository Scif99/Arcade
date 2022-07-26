#include "paddle.h"

Paddle::Paddle(float x, float y, Side side)
	:m_side_{ side }
{

	setSize(m_dim_);
	setPosition(x, m_dim_.y / 2);
	setFillColor(sf::Color::White);
	setOutlineColor(sf::Color::Black);
	setOutlineThickness(-1.f);
	setOrigin(m_dim_.x / 2, m_dim_.y / 2);
}


void Paddle::HandleInput(const std::unique_ptr<sf::RenderWindow>& p_window)
{
	//Get correct key codes
	sf::Keyboard::Key up_key = m_side_ == Paddle::Side::LEFT ? sf::Keyboard::W : sf::Keyboard::Up;
	sf::Keyboard::Key down_key = m_side_ == Paddle::Side::LEFT ? sf::Keyboard::S : sf::Keyboard::Down;

	if (sf::Keyboard::isKeyPressed(up_key) && getPosition().y - getSize().y / 2 > 0)
	{
		m_velocity_.y = -10.f;
	}
	else if (sf::Keyboard::isKeyPressed(down_key) && getPosition().y + getSize().y / 2 < p_window->getSize().y)
	{
		m_velocity_.y = 10.f;
	}
	else { m_velocity_.y = 0.f; }
}



void Paddle::Update()
{
	move(m_velocity_);
}