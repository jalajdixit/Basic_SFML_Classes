/* Demo Game 2 */
#pragma once
#include <iostream>
#include <vector>
#include <ctime>

#include "player.h"
#include "SwagBall.h"

class Game
{
    private:
        sf::VideoMode videoMode;
        sf::RenderWindow* window;
        sf::Event sfmlEvent;
        bool endGame;

        Player player;

        std::vector<SwagBall> swagBalls;
        float spawnTimerMax;
        float spawnTimer;
        int maxSwagBalls;

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

        void spawnSwagBalls();

        void update();
        void render();
};
