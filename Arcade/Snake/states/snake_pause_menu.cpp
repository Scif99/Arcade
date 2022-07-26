#include "snake_pause_menu.hpp"
#include "snake_play_game.hpp"

snake::PauseMenu::PauseMenu(std::shared_ptr<Context>& context)
	: p_context_{ context }
{
	if (!m_font_.loadFromFile("arial.ttf"))
	{
		//handle error
	}

	m_item_.setFont(m_font_);
	m_item_.setFillColor(sf::Color::White);
	m_item_.setString("PAUSED");
	m_item_.setPosition(sf::Vector2f(context->p_window_->getSize().x / 2, context->p_window_->getSize().y / 2 ));
}

void snake::PauseMenu::HandleEvents()
{
	sf::Event event;
	while (p_context_->p_window_->pollEvent(event))
	{
		if (event.type == sf::Event::KeyPressed)
		{
			if (event.key.code == sf::Keyboard::Escape)
				p_context_->p_state_man_->RemoveState(); //TO_DO
			return;
		}

	}
}

void snake::PauseMenu::Draw()
{
	p_context_->p_window_->clear();
	p_context_->p_window_->draw(m_item_);
	p_context_->p_window_->display();
}