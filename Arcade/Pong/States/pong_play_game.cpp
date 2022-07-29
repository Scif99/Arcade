#include "pong_play_game.hpp"
#include "pong_start_menu.hpp"


pong::PlayGame::PlayGame(std::shared_ptr<Context> context)
	: p_context_{ context }, m_ball_{ context->p_window_->getSize().x / 2, context->p_window_->getSize().y / 2 }, 
    m_left_paddle_{ 20.f, 0.f, Paddle::Side::LEFT }, m_right_paddle_{ context->p_window_->getSize().x - 20.f, 0.f, Paddle::Side::RIGHT }
{
	p_context_->p_window_->setFramerateLimit(60);

}



void pong::PlayGame::HandleEvents()
{
    sf::Event event;
    while (p_context_->p_window_->pollEvent(event))
    {
        if (event.type == sf::Event::KeyPressed)
        {
            if (event.key.code == sf::Keyboard::Escape)
            {
                p_context_->p_state_man_->AddState(std::make_unique<pong::StartMenu>(p_context_), false);
                return;
            }
        }
    }
	m_left_paddle_.HandleInput(p_context_->p_window_);
	m_right_paddle_.HandleInput(p_context_->p_window_);
}

void pong::PlayGame::Update(sf::Time elapsed)
{


	m_ball_.Update(*p_context_->p_window_);
	m_left_paddle_.Update();
	m_right_paddle_.Update();

	HandleCollisions(m_left_paddle_, m_ball_);
	HandleCollisions(m_right_paddle_, m_ball_);

}

void pong::PlayGame::Draw()
{
	p_context_->p_window_->clear();

    m_ball_.draw(*p_context_->p_window_);
    m_left_paddle_.draw(*p_context_->p_window_);
    m_right_paddle_.draw(*p_context_->p_window_);

	p_context_->p_window_->display();
}