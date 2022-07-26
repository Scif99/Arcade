#include <SFML/Graphics.hpp>
#include "game.hpp"
#include <iostream>
#include <snake.hpp>


int main()
{
    std::cout << "Press p for Pong, and s for Snake:\n";
    char x;
    std::cin >> x;

    sf::RenderWindow window(sf::VideoMode(500, 500), "Arcade");
    Game game(x);
    game.run();

    return 0;
}