/* Demo Game 2 */
#pragma once
#include <iostream>
#include <ctime>
#include "player.h"

class Game
{
    private:
        sf::VideoMode videoMode;
        sf::RenderWindow* window;
        sf::Event sfmlEvent;
        bool endGame;

        Player player;

        void initvariables();
        void initWindow();

    public:
    // Constructor & Destructor
        Game();
        ~Game();

    // Accessors

    //Modifiers

    //Functions
        const bool running() const;
        void pollEvents();

        void update();
        void render();
};
