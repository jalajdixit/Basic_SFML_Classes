/* Demo Game 2 */
#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>

class Player
{
    private:
        sf::RectangleShape shape;

        void initVariables();
        void initShapes();

    public:
        Player();
        virtual ~Player();

        void update();
        void render(sf::RenderTarget* target);
};
