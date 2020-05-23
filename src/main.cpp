#include <SFML/Graphics.hpp>
#include <iostream>
#include "Engine.cpp"

int main()
{
    sf::RenderWindow window(sf::VideoMode(800, 600), "Tetris Attack");
    window.setPosition(sf::Vector2i((sf::VideoMode::getDesktopMode().width / 2) - 400, (sf::VideoMode::getDesktopMode().height / 2) - 300));
    Engine engine(window);
    engine.run();
    return 0;
}
