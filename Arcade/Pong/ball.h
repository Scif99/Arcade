#pragma once
#include <SFML/Graphics.hpp>

class Paddle;

class Ball : sf::Drawable
{
public:
    Ball(float x, float y);

    void Reset(int start_dir);
    void Update(sf::RenderTarget& target);
    void draw(sf::RenderTarget& target, sf::RenderStates states = sf::RenderStates::Default) const override;

    friend void HandleCollisions(const Paddle& paddle, Ball& ball);

private:
    sf::CircleShape m_shape_;
    sf::Vector2f velocity{5.f,5.f};
};

