#include <SFML/Graphics.hpp>
#include <cstdio>
#include <vector>
#include <string>

class Rect;
class Block;
class Text;

class Engine
{
public:
    Engine(sf::RenderWindow &a) : win(a) {}
    bool renderBlocks();
    bool createBlocks(); // this should create blocks objects and put them into blocksMatrix
    void handleKeys();
    bool renderSprites();
    int run();
    Block *blocksMatrix[10][15];
    void setWindow(sf::RenderWindow *w);
    void replaceBlocks();
    Rect *rectangle;
    sf::Texture *textures;
    sf::RenderWindow &win;
    void log(std::string txt);
    void prepareElements();
    void drawElements();
    int score;
    void handleEvent(sf::Event *event, Engine *engine);
    void addScore(int points)
    {
        score += points;
    }
    void rearrangeBlocks();
    void clearBlocks(); // This should clear sets of blocks.
private:
    std::string test1;
    std::vector<sf::Sprite> sprites;
    std::vector<sf::Sprite>::iterator spi;
    Text *scoreText;
    Text *title;
};
