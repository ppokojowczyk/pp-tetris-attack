#include <SFML/Graphics.hpp>

/**
 * Handle key event.
 * @param sf::Event *event
 * @return void
 */
void Controls::handleEvent(sf::Event *event)
{

    int kc = event->key.code;

    /* Open in-game menu. */
    if (kc == sf::Keyboard::Escape)
    {
        game->endGame();
    }

    if (event->type == sf::Event::KeyPressed)
    {
        /* Replace blocks when space is pressed. */
        if (kc == sf::Keyboard::Space)
        {
            game->replaceBlocks();
        }
        /* Catch arrow keys. */
        if (kc == sf::Keyboard::Down)
        {
            game->rectangle->moveDown();
        }
        if (kc == sf::Keyboard::Up)
        {
            game->rectangle->moveUp();
        }
        if (kc == sf::Keyboard::Left)
        {
            game->rectangle->moveLeft();
        }
        if (kc == sf::Keyboard::Right)
        {
            game->rectangle->moveRight();
        }
    }
}
