#pragma once
#include <SFML/Graphics.hpp>
#include "paddle.h"

struct Ball : public sf::CircleShape
{
    Ball(float radius);

    void Reset(int start_dir);
    void Update() { move(velocity); };
    void Draw();
    sf::Vector2f velocity{5.f,5.f};
};

