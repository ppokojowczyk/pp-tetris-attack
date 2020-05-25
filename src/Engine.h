#include <SFML/Graphics.hpp>
#include <cstdio>
#include <vector>
#include <string>

class Rect;
class Block;
class Text;
class Menu;
class Engine
{
public:
    sf::Texture *textures;
    Engine(sf::RenderWindow &a) : win(a) {}
    int run();
    void setWindow(sf::RenderWindow *w);
    sf::RenderWindow &win;
    void log(std::string txt);
    void handleEvent(sf::Event *event, Engine *engine);
    Menu *menu;
};
