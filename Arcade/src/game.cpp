#include "game.hpp"
#include "snake.hpp"
#include "states/snake_start_menu.hpp"
#include "states/pong_start_menu.hpp"

Game::Game(char c, sf::RenderWindow& window)
	: m_context_{ window }
{
	m_context_.r_window_.setFramerateLimit(10); //hack to fix timesteps

	if (c == 's')
	{
		m_context_.r_window_.create(sf::VideoMode(500, 500), "Snake"); //Create a 500 x 500 window
		m_context_.m_state_man_.AddState(std::make_unique<snake::StartMenu>(m_context_), false); //Game always starts in the Start Menu
	}
	else if (c == 'p')
	{
		m_context_.r_window_.create(sf::VideoMode(500, 600), "Pong"); //Create a 500 x 500 window
		m_context_.m_state_man_.AddState(std::make_unique<pong::StartMenu>(m_context_), false); //Game always starts in the Start Menu
	}
}


//Game loop
//TODO Implement timing correctly

void Game::run()
{
	sf::Clock clock;
	while (m_context_.r_window_.isOpen())
	{
		sf::Time dt = clock.restart();

		m_context_.m_state_man_.CurrentState().HandleEvents();
		m_context_.m_state_man_.CurrentState().Update(dt);
		m_context_.m_state_man_.CurrentState().Draw();
	}
}
