#include <SFML/Graphics.hpp>

class Engine;
class Block;
class Rect;
class Text;

class Game
{
public:
    Game(Engine *engine);
    // Game(Engine *a) : engine(a) {}
    bool renderBlocks();
    bool createBlocks(); // this should create blocks objects and put them into blocksMatrix
    void handleKeys();
    bool renderSprites();
    Block *blocksMatrix[10][15];
    void replaceBlocks();
    void setWindow(sf::RenderWindow *w);
    Rect *rectangle;
    sf::Texture *textures;
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
    std::string getFormattedScore();
    void newGame();
    void endGame();
    void loop();
    Engine *engine;
    int state = 1;

protected:
    std::vector<sf::Sprite> sprites;
    std::vector<sf::Sprite>::iterator spi;
    Text *scoreLabel;
    Text *scoreText;
    Text *title;
};
