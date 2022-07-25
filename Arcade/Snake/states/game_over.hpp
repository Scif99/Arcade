#pragma once
#include "game_state.hpp"
#include "play_game.hpp"
#include "start_menu.hpp"

#include <memory>
#include "game.hpp"


namespace snake
{
	class GameOver : public engine::GameState
	{
	public:

		GameOver(std::shared_ptr<Context>& context);
		~GameOver() {}; //Default
		void HandleEvents() override;
		void Update(sf::Time elapsed) {};
		void Draw() override;

	private:
		std::shared_ptr<Context> p_context_;
		unsigned int m_curr_index_; //index of the highlighted item
		sf::Font m_font_;
		sf::Text m_items_[2];
	};
}