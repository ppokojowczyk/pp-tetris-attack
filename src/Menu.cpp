#include <SFML/Graphics.hpp>
#include "Menu.h"

void Menu::draw()
{
    for (int i = 0; i < MAX_MENU_ITEMS; i++)
    {
        items[i]->draw();
    }
}

void Menu::handleEvent(sf::Event *event)
{
    int kc = event->key.code;
    if (kc == sf::Keyboard::Down)
        moveDown();
    if (kc == sf::Keyboard::Up)
        moveUp();
    if (kc == sf::Keyboard::Return)
        run(currentItemIndex);
}

Menu::Menu(Engine *engine)
{
    currentItemIndex = 0;
    items[0] = createText(engine, "new game", 30, 150, 32);
    items[0]->setColor(ITEM_COLOR);
    items[1] = createText(engine, "exit", 30, 200, 32);
    items[1]->setColor(ITEM_COLOR);
    changeItem(currentItemIndex);
    this->engine = engine;
}

Menu::~Menu()
{
}

void Menu::changeItem(int index)
{
    if (index != currentItemIndex)
    {
        items[currentItemIndex]->setColor(ITEM_COLOR);
    }
    currentItemIndex = index;
    items[currentItemIndex]->setColor(SELECTED_ITEM_COLOR);
}

void Menu::moveDown()
{
    int newidx = currentItemIndex + 1;
    if (newidx < MAX_MENU_ITEMS)
    {
        changeItem(newidx);
    }
}

void Menu::moveUp()
{
    int newidx = currentItemIndex - 1;
    if (newidx >= 0)
    {
        changeItem(newidx);
    }
}

void Menu::run(int idx)
{
    switch (idx)
    {
    case 0:
    {
        Game g = Game(engine);
        g.loop();
        // engine->setState(1);
        break;
    }
    case 1:
        engine->win.close();
    default:
        break;
    }
}