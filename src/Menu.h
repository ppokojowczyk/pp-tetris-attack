#include <SFML/Graphics.hpp>

#define MAX_MENU_ITEMS 2
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
    void moveDown();
    void moveUp();
    void run(int idx);

protected:
    int currentItemIndex;
};