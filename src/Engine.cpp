#include <SFML/Graphics.hpp>
#include "Engine.h"
#include "Game.h"
#include "Block.h"
#include "Rect.h"
#include "Controls.h"
#include "Text.h"
#include "Rect.cpp"
#include "Block.cpp"
#include "Text.cpp"
#include "Textures.cpp"
#include "Controls.cpp"
#include "Menu.cpp"
#include "Game.cpp"
#include <iostream>
#include <cstdio>
#include <vector>
#include <string>
using namespace std;

/**
 * Run main function.
 */
int Engine::run()
{
    setState(MENU_STATE);
    textures = Textures::createTextures();
    Text::initTextures();
    sf::Sprite bgSprite = sf::Sprite(textures[7]);
    Menu menu = Menu(this);
    Text *title = createText(this, "pp-tetris-attack", 200, 10, 28);

    // Loop
    while (win.isOpen())
    {
        sf::Event event;
        win.clear();
        win.draw(bgSprite);
        Text *copy = createText(this, "pokojowczyk.pl 2020", 560, 575, 16);
        while (win.pollEvent(event))
        {
            menu.handleEvent(&event);
            if (event.type == sf::Event::Closed)
            {
                win.close();
            }
        }
        menu.draw();
        copy->draw();
        title->draw();
        win.display();
    }

    return 0;
}

/**
 * Output log entry.
 */
void Engine::log(string message)
{
    std::cout << message;
}

int Engine::getState()
{
    return state;
}

void Engine::setState(int val)
{
    state = val;
}
