#include <SFML/Graphics.hpp>

void Rect::moveDown(){
    if(brdypos+1 > maxbrdypos){return;}
    ypos += moveStep;
    brdypos += 1;
}

void Rect::moveUp(){
    if(brdypos-1 < 0){return;}
    ypos -= moveStep;
    brdypos -= 1;
}

void Rect::moveRight(){
    if(brdxpos+1 > maxbrdxpos){return;}
    xpos += moveStep;
    brdxpos += 1;
}

void Rect::moveLeft(){
    if(brdxpos-1 < 0){return;}
    xpos -= moveStep;
    brdxpos -= 1;
}

void Rect::renderRectangle(){
    sf::RectangleShape rct = sf::RectangleShape(sf::Vector2f(70, 35));
    rct.setPosition(xpos,ypos);
    rct.setFillColor(sf::Color(255,255,255,0));
    rct.setOutlineColor(sf::Color(255,255,255,196));
    rct.setOutlineThickness(2);
    win.draw(rct);
}

