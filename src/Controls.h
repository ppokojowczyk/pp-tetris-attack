#include <SFML/Graphics.hpp>
#include <cstdio>
#include <vector>

class Engine;
class Rect;

class Controls {

    public:
        Controls(Engine* a): engine(a) {}
        void handleEvent(sf::Event* event);
        bool isKeyCodeValid(int kc);
    protected:
        Engine* engine;
};