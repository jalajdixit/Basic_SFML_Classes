#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>

class SwagBall
{
    private:
        sf::CircleShape shape;

        void initShape(const sf::RenderWindow& window);
    public:
        SwagBall(const sf::RenderWindow& window);
        ~SwagBall();

        const sf::CircleShape getShape() const;

        void update();
        void render(sf::RenderTarget& target);
};
