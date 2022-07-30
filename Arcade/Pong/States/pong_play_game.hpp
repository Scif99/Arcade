#pragma once
#include "ball.h"
#include "paddle.h"
#include "state_manager.hpp"
#include "game.hpp"

namespace pong
{
	class PlayGame : public engine::StateBase
	{
	public:
		PlayGame(Context&  context);
		~PlayGame() {};
		void HandleEvents() override;
		void Update(sf::Time elapsed) override;
		virtual void Draw() override;

	private:
		Context&  r_context_;
		Ball m_ball_;
		Paddle m_left_paddle_;
		Paddle m_right_paddle_;
		//int m_tick_rate_;
		//bool game_over;
	};
}