#include "game.hpp"
#include "snake.hpp"
#include "states/snake_start_menu.hpp"
#include "states/pong_start_menu.hpp"

Game::Game()
	: p_context_{ std::make_shared<Context>() }
{
	p_context_->p_window_->create(sf::VideoMode(500, 500), "Snake"); //Create a 500 x 500 window
	p_context_->p_window_->setFramerateLimit(10); //hack to fix timesteps
	p_context_->p_state_man_->AddState(std::make_unique<pong::StartMenu>(p_context_), false); //Game always starts in the Start Menu
}


//Game loop
//TODO Implement timing correctly

void Game::run()
{
	sf::Clock clock;
	while (p_context_->p_window_->isOpen())
	{
		sf::Time dt = clock.restart();

		p_context_->p_state_man_->CurrentState()->HandleEvents();
		p_context_->p_state_man_->CurrentState()->Update(dt);
		p_context_->p_state_man_->CurrentState()->Draw();
	}
}
