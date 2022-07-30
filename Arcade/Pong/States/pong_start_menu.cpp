
#include "pong_start_menu.hpp"
#include "pong_play_game.hpp"

#include <memory>
#include <SFML/Graphics.hpp>
#include <iostream>

constexpr int ITEM_SIZE{ 4 };

pong::StartMenu::StartMenu(Context& context)
	: r_context_{ context }, m_curr_index_{ 0 }
{
	if (!m_font_.loadFromFile("arial.ttf"))
	{
		//handle error
	}

	m_items_[0].setFont(m_font_);
	m_items_[0].setFillColor(sf::Color::White);
	m_items_[0].setString("Play");
	m_items_[0].setPosition(sf::Vector2f(context.r_window_.getSize().x / 2, context.r_window_.getSize().y / (ITEM_SIZE + 1) * 1)); //3 items...

	m_items_[1].setFont(m_font_);
	m_items_[1].setFillColor(sf::Color::White);
	m_items_[1].setString("Join");
	m_items_[1].setPosition(sf::Vector2f(context.r_window_.getSize().x / 2, context.r_window_.getSize().y / (ITEM_SIZE + 1) * 2));

	m_items_[2].setFont(m_font_);
	m_items_[2].setFillColor(sf::Color::White);
	m_items_[2].setString("Host");
	m_items_[2].setPosition(sf::Vector2f(context.r_window_.getSize().x / 2, context.r_window_.getSize().y / (ITEM_SIZE + 1) * 3));

	m_items_[3].setFont(m_font_);
	m_items_[3].setFillColor(sf::Color::White);
	m_items_[3].setString("Exit");
	m_items_[3].setPosition(sf::Vector2f(context.r_window_.getSize().x / 2, context.r_window_.getSize().y / (ITEM_SIZE + 1) * 4));

	m_items_[m_curr_index_].setFillColor(sf::Color::Red); //Highlight 
}



void pong::StartMenu::HandleEvents()
{
	sf::Event event;
	while (r_context_.r_window_.pollEvent(event))
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
				if (m_curr_index_ < ITEM_SIZE - 1)
				{
					m_items_[m_curr_index_].setFillColor(sf::Color::White);
					++m_curr_index_;
					m_items_[m_curr_index_].setFillColor(sf::Color::Red);
				}
				break;
			case sf::Keyboard::Return:
				if (m_curr_index_ == 3) {
					r_context_.r_window_.close();
				}
				else if (m_curr_index_ == 0)
				{
					r_context_.m_state_man_.AddState(std::make_unique<pong::PlayGame>(r_context_), true);
					return; //After switching context, exit loop.
				}
				break;

			case sf::Keyboard::Escape:
				r_context_.r_window_.close();
			}
		}
	}


}

void pong::StartMenu::Draw()
{
	r_context_.r_window_.clear();
	for (const auto& item : m_items_)
	{
		r_context_.r_window_.draw(item);
	}
	r_context_.r_window_.display();
}