#include <SFML/Graphics.hpp>
#include <cstdio>
#include <string>
#include <map>

class Engine;

struct letter
{
    int x;
    int y;
};

class Text
{

    const int DEF_SIZE = 32;
    const float OFFSET_FACTOR = 0.75;

protected:
    Engine *engine;
    int fontSize;

public:
    static sf::Texture *texture;
    static void *initTextures();
    static std::map<char, letter> lettersMap;
    int textLength;
    void setFontSize(int size);
    int getFontSize();
    sf::Sprite spr;
    /** @todo array length should not be fixed */
    sf::Sprite sprites[255];
    int xpos;
    int ypos;
    std::string txt;
    static Text createText(std::string txt, int xpos, int ypos, int fontSize);
    Text(Engine *a) : engine(a) {}
    void prepareSprites();
    sf::Sprite prepareLetter(char letter, int index);
    void draw();
    float getOffset();
};
