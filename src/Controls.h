#include <SFML/Graphics.hpp>

class Rect;

class Controls
{
public:
    Controls(Game *a) : game(a) {}
    void handleEvent(sf::Event *event);

protected:
    Game *game;
};