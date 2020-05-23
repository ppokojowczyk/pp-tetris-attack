#include <SFML/Graphics.hpp>
#include <cstdio>
#include <vector>

class Rect;

class Controls
{
public:
    Controls(Game *a) : game(a) {}
    void handleEvent(sf::Event *event);
    bool isKeyCodeValid(int kc);

protected:
    Game *game;
};