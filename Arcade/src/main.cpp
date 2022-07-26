#include <SFML/Graphics.hpp>
#include "game.hpp"
#include <iostream>
#include <snake.hpp>


int main()
{
    std::cout << "which game would you like to play?\n";
    int x;
    std::cin >> x;

    sf::RenderWindow window(sf::VideoMode(500, 500), "Arcade");
    Game game;
    game.run();
    return 0;
}