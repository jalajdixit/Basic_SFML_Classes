/* Demo Game 2 */
#include "player.h"

void Player::initVariables()
{

}

void Player::initShapes()
{
    this->shape.setFillColor(sf::Color::Green);
    this->shape.setSize(sf::Vector2f(50.f,50.f));
}

Player::Player()
{
    this->initVariables();
    this->initShapes();
}

Player::~Player()
{

}

void Player::update()
{

}

void Player::render(sf::RenderTarget* target)
{
    target->draw(this->shape);
}
