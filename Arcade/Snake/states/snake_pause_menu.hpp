#pragma once
#include <SFML/Graphics.hpp>
#include "game.hpp"
#include "state_base.hpp"

namespace snake
{
	class PauseMenu : public engine::StateBase
	{
	public:
		PauseMenu(Context& context);
		~PauseMenu() = default; //Default
		void HandleEvents();
		void Update(sf::Time elapsed) {};
		void Draw();

	private:
		Context& r_context_;
		sf::Font m_font_;
		sf::Text m_item_;
	};
}