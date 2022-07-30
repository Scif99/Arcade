#include "snake_pause_menu.hpp"
#include "snake_play_game.hpp"

snake::PauseMenu::PauseMenu(Context& context)
	: r_context_{ context }
{
	if (!m_font_.loadFromFile("arial.ttf"))
	{
		//handle error
	}

	m_item_.setFont(m_font_);
	m_item_.setFillColor(sf::Color::White);
	m_item_.setString("PAUSED");
	m_item_.setPosition(sf::Vector2f(r_context_.r_window_.getSize().x / 2, r_context_.r_window_.getSize().y / 2 ));
}

void snake::PauseMenu::HandleEvents()
{
	sf::Event event;
	while (r_context_.r_window_.pollEvent(event))
	{
		if (event.type == sf::Event::KeyPressed)
		{
			if (event.key.code == sf::Keyboard::Escape)
				r_context_.m_state_man_.RemoveState(); //TO_DO
			return;
		}

	}
}

void snake::PauseMenu::Draw()
{
	r_context_.r_window_.clear();
	r_context_.r_window_.draw(m_item_);
	r_context_.r_window_.display();
}