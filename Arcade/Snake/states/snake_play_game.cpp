#include "snake_play_game.hpp"
#include <thread>
#include <chrono>
#include <memory>
#include "snake_pause_menu.hpp"
#include <algorithm>


#define GRID_DIM 20

snake::PlayGame::PlayGame(std::shared_ptr<Context>& context)
    : p_context_{ context }, m_snake_{ 10, 10 }, m_apple_{ rand() % GRID_DIM, rand() % GRID_DIM}, m_tick_rate_{10}
{
    //Constants
    int node_size = p_context_->p_window_->getSize().x / GRID_DIM; //size of the node in pixels 
    p_context_->p_window_->setFramerateLimit(10 + m_snake_.size()); //hack to increase speed

    //Fill the grid
    for (int y = 0;y < GRID_DIM;++y)
    {
        for (int x = 0;x < GRID_DIM;++x)
        {
            sf::RectangleShape node(sf::Vector2f(node_size, node_size));
            node.setPosition(sf::Vector2f(x * node_size, y * node_size));
            m_grid_.push_back(node);
        }

    }

}

void snake::PlayGame::HandleEvents()
{
    sf::Event event;
    while (p_context_->p_window_->pollEvent(event))
    {

        if (event.type == sf::Event::KeyPressed)
        {
            if (event.key.code == sf::Keyboard::Escape)
            {
                p_context_->p_state_man_->AddState(std::make_unique<snake::PauseMenu>(p_context_), false);
                return;
            }

            //Movement
            //Note that the snake is not allowed to turn 180 degrees (i.e turn in on itself)
            if (event.key.code == sf::Keyboard::Up && m_snake_.front().m_direction_ != std::make_pair(0, 1))
            {
                m_snake_.front().m_direction_= { 0,-1 };
                break;
            }

            if (event.key.code == sf::Keyboard::Down && m_snake_.front().m_direction_ != std::make_pair(0, -1))
            {
                m_snake_.front().m_direction_= { 0,1 };
                break;
            }

            if (event.key.code == sf::Keyboard::Left && m_snake_.front().m_direction_ != std::make_pair(1, 0))
            {
                m_snake_.front().m_direction_ = { -1,0 };
                break;
            }

            if (event.key.code == sf::Keyboard::Right && m_snake_.front().m_direction_!= std::make_pair(-1, 0))
            {
                m_snake_.front().m_direction_ = { 1,0 };
                break;
            }
        }
    }

}

void snake::PlayGame::Update(sf::Time elapsed)
{

    m_snake_.update_direction();
    m_snake_.update_position();

    //Reset if snake moves out of bounds or collides with itself
    auto front_coords = m_snake_.front().m_location_;
    if (m_snake_.intersect() || std::clamp(front_coords.first, 0, GRID_DIM - 1) != front_coords.first
        || std::clamp(front_coords.second, 0, GRID_DIM - 1) != front_coords.second)
    {
        p_context_->p_state_man_ ->AddState(std::make_unique<snake::GameOver>(p_context_), true);
        return;

    }

    //If the snake eats the apple, spawn apple at a new random point
    if (m_snake_.front().m_location_.first == m_apple_.first && m_snake_.front().m_location_.second == m_apple_.second)
    {
        //++tick_rate;
        m_snake_.add_piece(); //Add a piece to the tail of the snake
        p_context_->p_window_->setFramerateLimit(10 + m_snake_.size()); //hack to increase speed
        m_apple_.first = rand() % GRID_DIM;
        m_apple_.second = rand() % GRID_DIM; //x,y
        m_grid_[m_apple_.second * GRID_DIM + m_apple_.first].setFillColor(sf::Color::Red);
    }



}

//Basically only draw the nodes occupied by snake or apple
//NOT FINISHED
void snake::PlayGame::Draw()
{
    p_context_->p_window_->clear();
    for (int y = 0;y < GRID_DIM;++y)
    {
        for (int x = 0;x < GRID_DIM;++x)
        {
            int index = y * GRID_DIM + x;

            sf::RectangleShape curr = m_grid_[index];

            //Need to check if this point is occupied by any of the snake pieces
            if (m_snake_.contains(x, y))
            {
                m_grid_[y * GRID_DIM + x].setFillColor(sf::Color::Green);
                p_context_->p_window_->draw(m_grid_[y * GRID_DIM + x]);
            }

            if (x == m_apple_.first && y == m_apple_.second) //Apple is on this node
            {
                m_grid_[y * GRID_DIM + x].setFillColor(sf::Color::Red);
                p_context_->p_window_->draw(m_grid_[y * GRID_DIM + x]);
            }
            //window.draw(grid[y * grid_dim + x]);
        }
    }

    p_context_->p_window_->display();

}