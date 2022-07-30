#pragma once
#include "state_base.hpp"
#include "snake_play_game.hpp"
#include "snake_start_menu.hpp"

#include <memory>
#include "game.hpp"


namespace snake
{
	class GameOver : public engine::StateBase
	{
	public:

		GameOver(Context& context);
		~GameOver() {}; //Default
		void HandleEvents() override;
		void Update(sf::Time elapsed) {};
		void Draw() override;

	private:
		Context& r_context_;
		unsigned int m_curr_index_; //index of the highlighted item
		sf::Font m_font_;
		sf::Text m_items_[2];
	};
}