#include <SFML/Graphics.hpp>
#include <cstdio>
#include <vector>


class Engine;

class Block {

    protected:
	Engine* engine; // Reference to Engine.
	sf::Sprite sprite; // Sprite for block.
	int type; // Type of block (heart, triangle, etc ...).

    public:
        int currXPos;
        int currYPos;
        static Block create();
        Block(Engine* a): engine(a) {
        }
	void render();
	void draw();
	void prepare();
	void destroy();

	sf::Sprite getSprite(){
	    return sprite;
	}

	void setSprite(sf::Sprite newSprite){
	    sprite = newSprite;
	}

	void setType(int _type){
	    type = _type;
            sprite.setTexture(engine->textures[_type + 1]);
	}

	int getType(){
	    return type;
	}

};
