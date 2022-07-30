#include "pong_play_game.hpp"
#include "pong_start_menu.hpp"


pong::PlayGame::PlayGame(Context& context)
	: r_context_{ context }, m_ball_{ context.r_window_.getSize().x / 2, context.r_window_.getSize().y / 2 },
    m_left_paddle_{ 20.f, 0.f, Paddle::Side::LEFT }, m_right_paddle_{ context.r_window_.getSize().x - 20.f, 0.f, Paddle::Side::RIGHT }
{
    r_context_.r_window_.setFramerateLimit(60);

}



void pong::PlayGame::HandleEvents()
{
    sf::Event event;
    while (r_context_.r_window_.pollEvent(event))
    {
        if (event.type == sf::Event::KeyPressed)
        {
            if (event.key.code == sf::Keyboard::Escape)
            {
                r_context_.m_state_man_.AddState(std::make_unique<pong::StartMenu>(r_context_), false);
                return;
            }
        }
    }
	m_left_paddle_.HandleInput(r_context_.r_window_);
	m_right_paddle_.HandleInput(r_context_.r_window_);
}

void pong::PlayGame::Update(sf::Time elapsed)
{


	m_ball_.Update(r_context_.r_window_);
	m_left_paddle_.Update();
	m_right_paddle_.Update();

	HandleCollisions(m_left_paddle_, m_ball_);
	HandleCollisions(m_right_paddle_, m_ball_);

}

void pong::PlayGame::Draw()
{
    r_context_.r_window_.clear();

    m_ball_.draw(r_context_.r_window_);
    m_left_paddle_.draw(r_context_.r_window_);
    m_right_paddle_.draw(r_context_.r_window_);

    r_context_.r_window_.display();
}