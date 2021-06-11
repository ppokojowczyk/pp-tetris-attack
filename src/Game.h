#include <SFML/Graphics.hpp>

class Engine;
class Block;
class Rect;
class Text;
class Controls;

class Game
{
public:
    Game(Engine *engine);
    // Game(Engine *a) : engine(a) {}
    void renderBlocks();
    void createBlocks(); // this should create blocks objects and put them into blocksMatrix
    void handleKeys();
    void renderSprites();
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
    int state = 0;
    Controls *controls;
    sf::Sprite bgSprite;

protected:
    std::vector<sf::Sprite> sprites;
    std::vector<sf::Sprite>::iterator spi;
    Text *scoreLabel;
    Text *scoreText;
    Text *title;
};
