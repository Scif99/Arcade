#include <SFML/Graphics.hpp>
#include <iostream>

#include "game.hpp"

//TODO: Read around creational patterns.


int main()
{
    std::cout << "Press p for Pong, and s for Snake:\n";
    char x;
    std::cin >> x;

    sf::RenderWindow window(sf::VideoMode(600, 600), "Arcade"); //Main menu for the arcade. Specifying a game will recreate with specifi dimensions to game
    Game game(x, window);
    game.run();

    return 0;
}