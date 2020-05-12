#include <SFML/Graphics.hpp>
#include "Textures.h"

sf::Texture * Textures::textures;

void Textures::init(){
    sf::Texture txt;
    txt.loadFromFile("sprites/face.jpg");
    Textures::textures[0] = txt;
    Textures::textures = textures;
}

sf::Texture Textures::getTexture(int i){
    return Textures::textures[i];
};

sf::Texture * Textures::createTextures(){
    static sf::Texture textures[6];
    sf::Texture texture;
    texture.loadFromFile("sprites/block.png");
    textures[0] = texture;

    // Tiles
    std::string tilesFile = "sprites/tiles.png";
    sf::Texture texture2;

    // heart
    texture2.loadFromFile(tilesFile, sf::IntRect(0,0,30,30));
    textures[1] = texture2;

    // diamond
    texture2.loadFromFile(tilesFile, sf::IntRect(32,0,30,30));
    textures[2] = texture2;

    // star
    texture2.loadFromFile(tilesFile, sf::IntRect(64,0,30,30));
    textures[3] = texture2;

    // circle
    texture2.loadFromFile(tilesFile, sf::IntRect(0,32,30,30));
    textures[4] = texture2;

    // triangle
    texture2.loadFromFile(tilesFile, sf::IntRect(32,32,30,30));
    textures[5] = texture2;

    // triangle upside-down
    texture2.loadFromFile(tilesFile, sf::IntRect(64,32,30,30));
    textures[6] = texture2;

    // window background
    sf::Texture bgTexture;
    bgTexture.loadFromFile("sprites/gbg.jpg");
    textures[7] = bgTexture;

    // logo
    sf::Texture logoTexture;
    logoTexture.loadFromFile("sprites/logo.png");
    textures[8] = logoTexture;

    return textures;
}

