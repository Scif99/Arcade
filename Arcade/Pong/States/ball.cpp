#include "ball.h"

Ball::Ball(float radius)
    : sf::CircleShape{ radius } //Call constructor for sf::CircleShape
{
    setFillColor(sf::Color::White);
    setOutlineColor(sf::Color::Black);
    setOrigin(radius, radius); //Set the origin to be the centre of the ball (rather than the default top-left)
    setOutlineThickness(-1.f);
}




//Reset ball to start position
void Ball::Reset(int start_dir)
{
    setPosition(300, 300);
    velocity.x = start_dir ? -5.f : 5.f; //Right player scores : Left player scores
    velocity.y = 0.f;
}
