#pragma once
#include <SFML/Graphics.hpp>
namespace engine
{

	class GameState
	{
	public:
		GameState() {};
		virtual ~GameState() = default; //Default
		virtual void HandleEvents() = 0;
		virtual void Update(sf::Time elapsed) = 0;
		virtual void Draw() = 0;

	};
}