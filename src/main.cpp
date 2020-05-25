#include <SFML/Graphics.hpp>
#include <iostream>
#include "Engine.cpp"

int main()
{
    int winStyle = sf::Style::Fullscreen;
    sf::RenderWindow window(sf::VideoMode(800, 600), "pp-tetris-attack");
    window.setPosition(sf::Vector2i((sf::VideoMode::getDesktopMode().width / 2) - 400, (sf::VideoMode::getDesktopMode().height / 2) - 300));
    Engine engine(window);
    engine.run();
    return 0;
}
