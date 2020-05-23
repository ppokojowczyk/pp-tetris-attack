#include <SFML/Graphics.hpp>
#include <cstdio>
#include <vector>
#include <string>

#define MENU_STATE 1
#define GAME_STATE 2

class Rect;
class Block;
class Text;

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
    void setState(int val);
    int getState();

private:
    int state = 0;
};
