#include <SFML/Graphics.hpp>
#include "Engine.h"
#include "Block.cpp"
#include "Rect.h"
#include "Rect.cpp"
// #include "Text.h"
#include "Text.cpp"
#include "Textures.cpp"
#include "Controls.h"
#include "Controls.cpp"
#include <iostream>
#include <cstdio>
#include <vector>
#include <string>
using namespace std;

/**
 * Render all blocks from blocksMatrix.
 */
bool Engine::renderBlocks()
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
bool Engine::renderSprites() {}

/**
 * This should create all blocks and put them into blocksMatrix (board).
 */
bool Engine::createBlocks()
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
void Engine::handleKeys()
{
}

/**
 * Run main function.
 */
int Engine::run()
{
    score = 0;
    std::vector<sf::Sprite *> sprites;
    vector<sf::Sprite *>::iterator spi;
    textures = Textures::createTextures();
    Text::initTextures();
    Rect rect(win);
    rect.brdxpos = 0;
    rectangle = &rect;
    createBlocks();
    sf::Sprite bgSprite = sf::Sprite(textures[7]);
    prepareElements();
    Controls controls(this);
    Text *title = createText(this, "pp-tetris-attack", 200, 10, 28);
    Text *scoreLabel = createText(this, "score", 30, 50, 32);
    Text *scoreText = createText(this, "000000", 30, 80, 32);
    Text *copy = createText(this, "pokojowczyk.pl 2020", 560, 575, 16);

    // Loop
    while (win.isOpen())
    {
        sf::Event event;
        while (win.pollEvent(event))
        {
            handleKeys();
            controls.handleEvent(&event);
            if (event.type == sf::Event::Closed)
            {
                win.close();
            }
        }
        scoreText->setText(getFormattedScore());
        //handleKeys();
        win.clear();
        win.draw(bgSprite);
        title->draw();
        scoreText->draw();
        scoreLabel->draw();
        copy->draw();
        rectangle->renderRectangle();
        drawElements();
        clearBlocks();
        rearrangeBlocks();
        renderBlocks();
        win.display();
    }

    return 0;
}

/**
 * Replace two blocks ( change x positions ).
 */
void Engine::replaceBlocks()
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
 * Output log entry.
 */
void Engine::log(string message)
{
    std::cout << message;
}

/**
 * Prepare game/interface elements.
 */
void Engine::prepareElements()
{
}

void Engine::drawElements()
{
    // std::string sc = "Score: ";
    // scoreText.setString(sc + std::to_string(score));
    // scoreText->draw();
    // win.draw(scoreText);
}

/**
 * Clear valid sets of blocks.
 */
void Engine::clearBlocks()
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
void Engine::rearrangeBlocks()
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

std::string Engine::getFormattedScore()
{
    std::string scr = std::to_string(score);
    while (scr.length() < 6)
    {
        scr = "0" + scr;
    }
    return scr;
}