#include <SFML/Graphics.hpp>
#include "game.hpp"

int main()
{
    sf::RenderWindow window(sf::VideoMode(500, 500), "Arcade");
    Game game;
    game.run();

    return 0;
}