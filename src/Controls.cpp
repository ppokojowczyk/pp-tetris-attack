#include <SFML/Graphics.hpp>
#include <cstdio>
#include <vector>

void Controls::handleEvent(sf::Event* event){

    int kc = event->key.code;
    bool valid = isKeyCodeValid(kc);

    if (kc == sf::Keyboard::Escape || kc == sf::Keyboard::Q)
    {
        engine->win.close();
    }


    if(event->type == sf::Event::KeyPressed) {

        // check if key is a valid key for movement
        if(valid){
            //if(mvblk == true){return;}

	    // replace blocks when space is pressed
	    if(kc == sf::Keyboard::Space){
		engine->replaceBlocks();
	    }

	    // catch arrows keys
            if(kc == sf::Keyboard::Down || kc == sf::Keyboard::J){engine->rectangle->moveDown();}
            if(kc == sf::Keyboard::Up || kc == sf::Keyboard::K){engine->rectangle->moveUp();}
            if(kc == sf::Keyboard::Left || kc == sf::Keyboard::H){engine->rectangle->moveLeft();}
            if(kc == sf::Keyboard::Right || kc == sf::Keyboard::L){engine->rectangle->moveRight();}

            //mvblk = true; // block the movement when key is hold
        }
    }

    // unblock movement when arrow hey is released
    //if(event->type == sf::Event::KeyReleased && valid) { mvblk = false; }
}

bool Controls::isKeyCodeValid(int kc){
    sf::Keyboard::Key validKeys [] = {
        sf::Keyboard::Up,
        sf::Keyboard::Right,
        sf::Keyboard::Down,
        sf::Keyboard::Left,
        sf::Keyboard::K,
        sf::Keyboard::L,
        sf::Keyboard::J,
        sf::Keyboard::H,
        sf::Keyboard::Space
    };
    for(int i = 0; i < sizeof(validKeys); i++){
        if(validKeys[i] == kc){
            return true;
        }
    }
    return false;
}

