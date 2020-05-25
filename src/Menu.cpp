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
    if (event->type == sf::Event::KeyPressed)
    {
        if (kc == sf::Keyboard::Down)
        {
            moveDown(currentItemIndex);
        }
        if (kc == sf::Keyboard::Up)
        {
            moveUp(currentItemIndex);
        }
        if (kc == sf::Keyboard::Return)
        {
            run(currentItemIndex);
        }
    }
}

Menu::Menu(Engine *engine)
{
    currentItemIndex = DEFAULT_ITEM_INDEX;
    items[0] = createText(engine, "continue", 0, 0, 32);
    items[0]->setColor(ITEM_COLOR);
    items[1] = createText(engine, "new game", 0, 0, 32);
    items[1]->setColor(ITEM_COLOR);
    items[2] = createText(engine, "exit", 0, 0, 32);
    items[2]->setColor(ITEM_COLOR);
    updateItems();
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

void Menu::moveDown(int currentIndex)
{
    int newidx = currentIndex + 1;
    if (newidx < MAX_MENU_ITEMS)
    {
        if (!items[newidx]->getVisible())
        {
            return moveDown(newidx + 1);
        }
        changeItem(newidx);
    }
}

void Menu::moveUp(int currentIndex)
{
    int newidx = currentIndex - 1;
    if (newidx >= 0)
    {
        if (!items[newidx]->getVisible())
        {
            return moveUp(newidx - 1);
        }
        changeItem(newidx);
    }
}

void Menu::run(int idx)
{
    switch (idx)
    {
    case 1:
        /* Start a new game. */
        {
            this->currentGame = new Game(engine);
            this->currentGame->newGame();
            this->currentGame->loop();
            break;
        }
    case 2:
        /* Quit game. */
        {
            engine->win.close();
            break;
        }
    case 0:
        /* Continue game. */
        {
            this->currentGame->state = 1;
            this->currentGame->loop();
            break;
            // engine->win.close();
        }
    default:
        break;
    }
}

void Menu::updatePositions()
{
    /* Update positions. */
    int posIdx = 0;
    for (int i = 0; i < MAX_MENU_ITEMS; i++)
    {
        if (items[i]->getVisible())
        {
            posIdx++;
        }
        items[i]->setPosition(xOffset, yOffset + (posIdx * ySpace));
    }
}

void Menu::updateItems()
{
    int idx = DEFAULT_ITEM_INDEX;
    items[0]->setVisible(this->currentGame != NULL ? true : false);
    if (items[0]->getVisible())
    {
        idx = 0;
    }
    updatePositions();
    changeItem(idx);
}