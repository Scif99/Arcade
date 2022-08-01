#pragma once
#include <SFML/Graphics.hpp>

namespace engine
{

	class StateBase
	{
	public:
		StateBase() {};
		virtual ~StateBase() = default; //Default
		virtual void HandleEvents() = 0;
		virtual void Update(sf::Time elapsed) = 0;
		virtual void Draw() = 0;

	};
}