#include <iostream>
#include <cstdio>
#include <vector>
#include <string>
using namespace std;

class Block;

Game::Game(Engine *engine)
{
    this->engine = engine;
}

/**
 * Initialize new game.
 */
void Game::newGame()
{
    std::vector<sf::Sprite *> sprites;
    this->scoreLabel = createText(engine, "score", 30, 50, 32);
    this->scoreText = createText(engine, "000000", 30, 80, 32);
    this->title = createText(engine, "pp-tetris-attack", 200, 10, 28);
    this->controls = new Controls(this);
    this->state = 1;
    this->rectangle = new Rect(engine->win);
    this->rectangle->brdxpos = 0;
    createBlocks();
    vector<sf::Sprite *>::iterator spi;
    score = 0;
    this->bgSprite = sf::Sprite(engine->textures[7]);
}

void Game::loop()
{
    this->state = 1;
    // Loop
    while (this->state == 1)
    {
        sf::Event event;
        engine->win.clear();
        engine->win.draw(bgSprite);
        Text *copy = createText(engine, "pokojowczyk.pl 2020", 560, 575, 16);
        while (engine->win.pollEvent(event))
        {
            this->controls->handleEvent(&event);
            if (event.type == sf::Event::Closed)
            {
                engine->win.close();
            }
        }
        scoreText->setText(getFormattedScore());
        title->draw();
        scoreText->draw();
        scoreLabel->draw();
        rectangle->renderRectangle();
        drawElements();
        clearBlocks();
        rearrangeBlocks();
        renderBlocks();
        engine->win.display();
    }
}

void Game::endGame()
{
    state = 0;
    this->engine->menu->updateItems();
}

std::string Game::getFormattedScore()
{
    std::string scr = std::to_string(score);
    while (scr.length() < 6)
    {
        scr = "0" + scr;
    }
    return scr;
}

/**
 * Prepare game/interface elements.
 */
void Game::prepareElements()
{
}

void Game::drawElements()
{
    // std::string sc = "Score: ";
    // scoreText.setString(sc + std::to_string(score));
    // scoreText->draw();
    // win.draw(scoreText);
}

/**
 * Clear valid sets of blocks.
 */
void Game::clearBlocks()
{
    for (int y = 0; y < 13; y++)
    {
        for (int x = 0; x < 10; x++)
        {
            if (blocksMatrix[x][y] == NULL || blocksMatrix[x][y + 1] == NULL || blocksMatrix[x][y + 2] == NULL)
            {
                continue;
            }
            Block *blk = blocksMatrix[x][y];
            if (blocksMatrix[x][y + 1]->getType() == blk->getType() && blocksMatrix[x][y + 2]->getType() == blk->getType())
            {
                blocksMatrix[x][y] = NULL;
                blocksMatrix[x][y + 1] = NULL;
                blocksMatrix[x][y + 2] = NULL;
                addScore(3);
            }
        }
    }
}

/**
 * Rearrange blocks.
 * (!) Should be executed after clearBlocks().
 * (!) Pulls all blocks to bottom.
 */
void Game::rearrangeBlocks()
{
    // start from bottom
    for (int y = 14; y > 0; y--)
    {
        for (int x = 0; x < 10; x++)
        {
            if (blocksMatrix[x][y] != NULL)
            {
                continue;
            }
            if (blocksMatrix[x][y - 1] != NULL)
            {
                blocksMatrix[x][y] = blocksMatrix[x][y - 1];
                blocksMatrix[x][y]->currYPos = y;
                blocksMatrix[x][y - 1] = NULL;
            }
        }
    };
}

/**
 * Replace two blocks ( change x positions ).
 */
void Game::replaceBlocks()
{
    int x1 = rectangle->brdxpos;
    int y = rectangle->brdypos;
    int x2 = x1 + 1;
    Block *firstBlock = blocksMatrix[x1][y];
    Block *secondBlock = blocksMatrix[x2][y];

    // change position of first block (if block exists);
    if (firstBlock != NULL)
    {
        firstBlock->currXPos = x2;
    }

    // change position of second block (if block exists);
    if (secondBlock != NULL)
    {
        secondBlock->currXPos = x1;
    }

    // replace blocks on matrix;
    blocksMatrix[x1][y] = secondBlock;
    blocksMatrix[x2][y] = firstBlock;
}

/**
 * Render all blocks from blocksMatrix.
 */
void Game::renderBlocks()
{
    for (int y = 0; y < 15; y++)
    {
        for (int x = 0; x < 10; x++)
        {
            if (blocksMatrix[x][y] == NULL)
            {
                continue;
            }
            blocksMatrix[x][y]->draw();
        }
    }
}

/**
 * Render all sprites.
 * __TODO__
 * (!) Should be used for extended animations.
 */
void Game::renderSprites() {}

/**
 * This should create all blocks and put them into blocksMatrix (board).
 */
void Game::createBlocks()
{
    srand(time(NULL)); // to get different sequence when rand() is executed
    for (int x = 0; x < 10; x++)
    { // fill 10x15 board
        for (int y = 0; y < 15; y++)
        {
            Block *blk = createBlock(this, x, y);
            blk->prepare();
            blocksMatrix[x][y] = blk;
        }
    }
}

/**
 * Handle keys events.
 */
void Game::handleKeys()
{
}
