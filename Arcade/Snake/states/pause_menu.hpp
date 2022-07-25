#pragma once
#include <SFML/Graphics.hpp>
#include "game.hpp"
#include "game_state.hpp"

namespace snake
{
	class PauseMenu : public engine::GameState
	{
	public:
		PauseMenu(std::shared_ptr<Context>& context);
		~PauseMenu() = default; //Default
		void HandleEvents();
		void Update(sf::Time elapsed) {};
		void Draw();

	private:
		std::shared_ptr<Context> p_context_;
		sf::Font m_font_;
		sf::Text m_item_;


	};
}