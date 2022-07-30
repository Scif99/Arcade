#pragma once
#include <SFML/Graphics.hpp>
#include "state_base.hpp"
#include "game.hpp"


//struct Context; //forward declaration
namespace snake 
{

	class StartMenu : public engine::StateBase
	{
	public:
		StartMenu(Context& context);
		~StartMenu() {};
		void HandleEvents() override;
		void Update(sf::Time elapsed) {};
		void Draw() override;

	private:
		Context& r_context_;
		int m_curr_index_; //index of the highlighted item
		sf::Font m_font_;
		sf::Text m_items_[3];
	};
}