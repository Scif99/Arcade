#pragma once
#include <SFML/Graphics.hpp>
#include <memory>
#include "state_manager.hpp"

struct Context
{
	std::unique_ptr<engine::StateManager> p_state_man_;
	std::unique_ptr<sf::RenderWindow> p_window_;

	Context()
		: p_window_{ std::make_unique<sf::RenderWindow>() }, p_state_man_{ std::make_unique<engine::StateManager>() } {}
};


class Game
{
public:
	Game();
	~Game() {};

	void run();
private:
	std::shared_ptr<Context> p_context_;

};

