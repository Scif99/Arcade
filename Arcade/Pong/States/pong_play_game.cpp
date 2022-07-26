#include "pong_play_game.hpp"
#include "pong_start_menu.hpp"

//Handles collisions between the ball and a paddle
void HandleCollisions(const Paddle& paddle, Ball& ball)
{
    if (ball.getGlobalBounds().intersects(paddle.getGlobalBounds()))
    {
        ball.velocity.x *= -(1.1f); //X speed increased by fixed amount each hit

        //Ball hits top half of paddle
        if (paddle.getPosition().y > ball.getPosition().y)
        {
            ball.velocity.y = paddle.getPosition().y > ball.getPosition().y ? -5.f : 5.f;
        }
    }
}

pong::PlayGame::PlayGame(std::shared_ptr<Context>& context)
	: p_context_{ context }, m_ball_{ 10.f }, m_left_paddle_{ 20.f, 0.f, Paddle::Side::LEFT }, m_right_paddle_{ context->p_window_->getSize().x - 20.f, 0.f, Paddle::Side::RIGHT }
{
	p_context_->p_window_->setFramerateLimit(60);
	m_ball_.setPosition(p_context_->p_window_->getSize().x / 2, p_context_->p_window_->getSize().y / 2); //fix with window?

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
    //Vertical collisions
    if (m_ball_.getPosition().y - m_ball_.getRadius() < 0.f || m_ball_.getPosition().y + m_ball_.getRadius() > p_context_->p_window_->getSize().y)
    {
        m_ball_.velocity.y = -m_ball_.velocity.y;
    }

    //If the ball collides with the right wall of the window, Left player scores a point
    if (m_ball_.getPosition().x + m_ball_.getRadius() > p_context_->p_window_->getSize().x)
    {
        //lscore.addPoint();
        m_ball_.Reset(0);
    }

    //If the ball collides with the left wall of the window, right player scores a point
    if (m_ball_.getPosition().x - m_ball_.getRadius() < 0)
    {
        //rscore.addPoint();
        //if (rscore.points % 10 == 0) { rscore.move(-15.f, 0.f); } //Prevent part of score clipping outside window
        m_ball_.Reset(1);
    }

	m_ball_.Update();
	m_left_paddle_.Update();
	m_right_paddle_.Update();

	HandleCollisions(m_left_paddle_, m_ball_);
	HandleCollisions(m_right_paddle_, m_ball_);

}

void pong::PlayGame::Draw()
{
	p_context_->p_window_->clear();

	p_context_->p_window_->draw(m_ball_);
	p_context_->p_window_->draw(m_left_paddle_);
	p_context_->p_window_->draw(m_right_paddle_);

	p_context_->p_window_->display();
}