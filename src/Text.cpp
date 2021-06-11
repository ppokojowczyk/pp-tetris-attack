#include <SFML/Graphics.hpp>
#include <string>

/**
 * @todo Can this be moved into Text class?
 */

sf::Texture fontTexture = sf::Texture();
sf::Texture *Text::texture = &fontTexture;

std::map<char, letter> Text::lettersMap = {
    {'a', letter{0, 0}},
    {'b', letter{1, 0}},
    {'c', letter{2, 0}},
    {'d', letter{3, 0}},
    {'e', letter{4, 0}},
    {'f', letter{5, 0}},
    {'g', letter{6, 0}},
    {'h', letter{7, 0}},
    {'i', letter{0, 1}},
    {'j', letter{1, 1}},
    {'k', letter{2, 1}},
    {'l', letter{3, 1}},
    {'m', letter{4, 1}},
    {'n', letter{5, 1}},
    {'o', letter{6, 1}},
    {'p', letter{7, 1}},
    {'q', letter{0, 2}},
    {'r', letter{1, 2}},
    {'s', letter{2, 2}},
    {'t', letter{3, 2}},
    {'u', letter{4, 2}},
    {'v', letter{5, 2}},
    {'w', letter{6, 2}},
    {'x', letter{7, 2}},
    {'y', letter{0, 3}},
    {'z', letter{1, 3}},
    {'-', letter{2, 3}},
    {'0', letter{3, 3}},
    {'1', letter{4, 3}},
    {'2', letter{5, 3}},
    {'3', letter{6, 3}},
    {'4', letter{7, 3}},
    {'5', letter{0, 4}},
    {'6', letter{1, 4}},
    {'7', letter{2, 4}},
    {'8', letter{3, 4}},
    {'9', letter{4, 4}},
    {'.', letter{5, 4}},
    {',', letter{6, 4}}};

void Text::setFontSize(int size)
{
    fontSize = size;
}

int Text::getFontSize()
{
    return fontSize;
}

Text *createText(Engine *engine, std::string txt, int xpos, int ypos, int fontSize = 0)
{
    Text *text = new Text(engine);
    if (fontSize > 0)
    {
        text->setFontSize(fontSize);
    }
    else
    {
        text->setFontSize(32);
    }
    text->xpos = xpos;
    text->ypos = ypos;
    text->setText(txt);
    return text;
}

void Text::prepareSprites()
{
    sf::Sprite spr = sf::Sprite();
    sprites[0] = spr;
    for (int i = 0; i < txt.length(); i++)
    {
        textLength++;
        if (txt[i] == ' ')
            continue;
        sprites[i] = prepareLetter(txt[i], i);
    }
}

sf::Sprite Text::prepareLetter(char letter, int index)
{
    sf::Sprite sprite = sf::Sprite();
    sprite.setTexture(*texture);
    sprite.setPosition(xpos + (getOffset() * index), ypos);
    sprite.setTextureRect(sf::IntRect(lettersMap[letter].x * DEF_SIZE, lettersMap[letter].y * DEF_SIZE, DEF_SIZE, DEF_SIZE));
    double fc = static_cast<double>(fontSize) / DEF_SIZE;
    sprite.setScale(sf::Vector2f(fc, fc));
    return sprite;
}

float Text::getOffset()
{
    return getFontSize() * OFFSET_FACTOR;
}

void Text::initTextures()
{
    texture->loadFromFile("sprites/font.png");
    texture->setSmooth(true);
}

void Text::draw()
{
    if (!this->getVisible())
    {
        return;
    }
    for (int i = 0; i < textLength; i++)
    {
        engine->win.draw(sprites[i]);
    }
}

void Text::setText(std::string txt)
{
    this->txt = txt;
    this->textLength = 0;
    this->prepareSprites();
}

void Text::setColor(sf::Color color)
{
    for (int i = 0; i < textLength; i++)
    {
        sprites[i].setColor(color);
    }
}

void Text::setVisible(bool visible)
{
    this->visible = visible;
}

bool Text::getVisible()
{
    return this->visible;
}

void Text::setPosition(int x, int y)
{
    xpos = x;
    ypos = y;
    for (int i = 0; i < textLength; i++)
    {
        sprites[i].setPosition(xpos + (getOffset() * i), ypos);
    }
}
