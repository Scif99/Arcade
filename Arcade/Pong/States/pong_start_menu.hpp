#pragma once
#include <SFML/Graphics.hpp>
#include "game_state.hpp"
#include "game.hpp"


//struct Context; //forward declaration
namespace pong
{

	class StartMenu : public engine::GameState
	{
	public:
		StartMenu(std::shared_ptr<Context>& context);
		~StartMenu() {};
		void HandleEvents() override;
		void Update(sf::Time elapsed) {};
		void Draw() override;

	private:
		std::shared_ptr<Context> p_context_;
		int m_curr_index_; //index of the highlighted item
		sf::Font m_font_;
		sf::Text m_items_[4];
	};
}