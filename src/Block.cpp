#include <SFML/Graphics.hpp>

const int X_OFFSET = 200;
const int Y_OFFSET = 50;

int findGoodType(Block *block, Game *game)
{
    bool good = false;
    int type;
    while (good == false)
    {
        type = rand() % 6;
        if (block->currXPos > 0)
        {
            Block *bl = game->blocksMatrix[block->currXPos][block->currYPos - 1];
            if (type != bl->getType())
            {
                good = true;
            }
        }
        else
        {
            good = true;
        }
    }
    return type;
}

/**
 * Create a new Block pointer.
 */
Block *createBlock(Game *game, int x, int y)
{
    Block *block = new Block(game);
    block->currXPos = x;
    block->currYPos = y;
    block->prepare();
    return block;
};

/**
 * Draw sprite on window.
 */
void Block::draw()
{
    sprite.setPosition((currXPos * 35) + X_OFFSET, (currYPos * 35) + Y_OFFSET);
    game->engine->win.draw(getSprite());
}

/**
 * Prepare block; create sprite, apply texture, etc.
 */
void Block::prepare()
{
    sf::Sprite sprite = sf::Sprite();
    setSprite(sprite);
    int blockType = findGoodType(this, game);
    setType(blockType);
}
