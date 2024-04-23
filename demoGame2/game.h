/* Demo Game 2 */
#pragma once
#include <iostream>
#include <vector>
#include <ctime>
#include <sstream>

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

        int points;

        sf::Font font;
        sf::Text guiText;
        sf::Text endGametext;

        std::vector<SwagBall> swagBalls;
        float spawnTimerMax;
        float spawnTimer;
        int maxSwagBalls;

        void initvariables();
        void initWindow();
        void initFont();
        void initText();

    public:
    // Constructor & Destructor
        Game();
        ~Game();

    // Accessors
        const bool& getEndGame() const;
    //Modifiers

    //Functions
        const bool running() const;
        void pollEvents();

        void spawnSwagBalls();
        const int randBallType() const;
        void updatePlayer();
        void updateCollision();
        void updateGui();
        void update();

        void renderGui(sf::RenderTarget* target);
        void render();
};
