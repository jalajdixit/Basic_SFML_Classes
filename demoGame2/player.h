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

        float movementSpeed;
        int hp;
        int hpMax;

        void initVariables();
        void initShapes();

    public:
        Player(float x=0.f, float y=0.f);
        virtual ~Player();

        const sf::RectangleShape getShape() const;

        void updateInput();
        void updateWindowBounceCollision(const sf::RenderTarget* target);

        void update(const sf::RenderTarget* target);
        void render(sf::RenderTarget* target);
};
