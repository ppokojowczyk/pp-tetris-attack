#include <SFML/Graphics.hpp>
#include <cstdio>
#include <vector>

class Engine;

class Rect {
    public:
        Rect(sf::RenderWindow& a): win(a) {
	    brdxpos = 0;
	    brdypos = 0;
            xpos = 198;
            ypos = 48;
            moveStep = 35;
	    mvblk = false;
            maxbrdxpos = 8; // max x position value of rectangle on board
            maxbrdypos = 14; // max y position value of rectangle on board
        }
        void renderRectangle();
	void moveUp();
	void moveRight();
	void moveDown();
	void moveLeft();
	int brdxpos;
	int brdypos;
	int xpos;
	int ypos;
	int moveStep;
	bool mvblk;
	int maxbrdxpos;
	int maxbrdypos;
    private:
        int posx;
        int posy;
        sf::RenderWindow& win;
};

