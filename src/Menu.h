#include <SFML/Graphics.hpp>

#define DEFAULT_ITEM_INDEX 1
#define MAX_MENU_ITEMS 3
#define ITEM_COLOR sf::Color(100, 100, 100)
#define SELECTED_ITEM_COLOR sf::Color(255, 255, 255)

class Text;
class Engine;

class Menu
{
public:
    Menu(Engine *engine);
    ~Menu();
    void draw();
    void up();
    void down();
    Text *items[MAX_MENU_ITEMS];
    Engine *engine;
    void handleEvent(sf::Event *event);
    void changeItem(int index);
    void moveDown(int currentIndex);
    void moveUp(int currentIndex);
    void run(int idx);
    Game *currentGame;
    int xOffset = 30;
    int yOffset = 100;
    int ySpace = 50;
    void updateItems();
    void updatePositions();

protected:
    int currentItemIndex;
};