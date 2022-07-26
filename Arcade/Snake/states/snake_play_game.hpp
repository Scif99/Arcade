#pragma once
#include "game_state.hpp"
#include "snake.hpp"
#include "game.hpp"
#include "snake_game_over.hpp"
#include <vector>
#include <cstdlib>

namespace snake
{
	class PlayGame : public engine::GameState
	{
	public:
		PlayGame(std::shared_ptr<Context>& context);
		~PlayGame() {};
		void HandleEvents() override;
		void Update(sf::Time elapsed) override;
		virtual void Draw() override;

	private:
		std::shared_ptr<Context> p_context_;
		Snake m_snake_;
		std::pair<int, int> m_apple_;
		std::vector<sf::RectangleShape> m_grid_;
		int m_tick_rate_;
		//bool game_over;
	};
}