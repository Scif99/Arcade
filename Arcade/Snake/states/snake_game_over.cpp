#include "snake_game_over.hpp"
#include <memory>
#include "snake_play_game.hpp"

#define ITEM_SIZE 2

snake::GameOver::GameOver(std::shared_ptr<Context>& context)
	: p_context_{ context }, m_curr_index_{ 0 }
{
	if (!m_font_.loadFromFile("arial.ttf"))
	{
		//handle error
	}

	m_items_[0].setFont(m_font_);
	m_items_[0].setFillColor(sf::Color::White);
	m_items_[0].setString("Retry");
	m_items_[0].setPosition(sf::Vector2f(context->p_window_->getSize().x / 2, context->p_window_->getSize().y / (ITEM_SIZE + 1) * 1)); //3 items...

	m_items_[1].setFont(m_font_);
	m_items_[1].setFillColor(sf::Color::White);
	m_items_[1].setString("Exit");
	m_items_[1].setPosition(sf::Vector2f(context->p_window_->getSize().x / 2, context->p_window_->getSize().y / (ITEM_SIZE + 1) * 2));

	m_items_[m_curr_index_].setFillColor(sf::Color::Red); //Highlight 
}

void snake::GameOver::HandleEvents()
{
	sf::Event event;
	while (p_context_->p_window_->pollEvent(event))
	{
		if (event.type == sf::Event::KeyPressed)
		{

			switch (event.key.code)
			{
			case sf::Keyboard::Up:
				if (m_curr_index_ > 0)
				{
					m_items_[m_curr_index_].setFillColor(sf::Color::White);
					--m_curr_index_;
					m_items_[m_curr_index_].setFillColor(sf::Color::Red);
				}
				break;
			case sf::Keyboard::Down:
				if (m_curr_index_ < ITEM_SIZE-1)
				{
					m_items_[m_curr_index_].setFillColor(sf::Color::White);
					++m_curr_index_;
					m_items_[m_curr_index_].setFillColor(sf::Color::Red);
				}
				break;
			case sf::Keyboard::Return:
				if (m_curr_index_ == 1) {
					p_context_->p_window_->close();
				}
				else if (m_curr_index_ == 0)
				{
					p_context_->p_state_man_->AddState(std::make_unique<snake::PlayGame>(p_context_), true);
					return; //After switching context, exit loop.
				}
				break;

			case sf::Keyboard::Escape:
				p_context_->p_window_->close();
			}
		}

	}


}

void snake::GameOver::Draw()
{
	p_context_->p_window_->clear();
	for (const auto& item : m_items_)
	{
		p_context_->p_window_->draw(item);
	}
	p_context_->p_window_->display();
}