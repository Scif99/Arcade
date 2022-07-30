#pragma once
#include <SFML/Graphics.hpp>
#include <memory>
#include "state_manager.hpp"


struct Context
{
	engine::StateManager m_state_man_;
	sf::RenderWindow& r_window_;

	Context(sf::RenderWindow& window)
		:r_window_{ window } {}
};


class Game
{
public:
	Game(char c, sf::RenderWindow& window);
	~Game() {};

	void run();
private:
	Context m_context_;

};

