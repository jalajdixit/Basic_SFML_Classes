/* Demo Game 2 */
#include "player.h"

void Player::initVariables()
{
    this->movementSpeed = 10.f;
}

void Player::initShapes()
{
    this->shape.setFillColor(sf::Color::Green);
    this->shape.setSize(sf::Vector2f(50.f,50.f));
}

Player::Player(float x, float y)
{
    this->shape.setPosition(x,y);

    this->initVariables();
    this->initShapes();
}

Player::~Player()
{

}

void Player::updateInput()
{
    // Keyboard Input
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::A))
    {
        this->shape.move(-this->movementSpeed,0.f);
    }
    else if(sf::Keyboard::isKeyPressed(sf::Keyboard::D))
    {
        this->shape.move(this->movementSpeed,0.f);
    }

    if(sf::Keyboard::isKeyPressed(sf::Keyboard::W))
    {
        this->shape.move(0.f,-this->movementSpeed);
    }
    else if(sf::Keyboard::isKeyPressed(sf::Keyboard::S))
    {
        this->shape.move(0.f,this->movementSpeed);
    }
}

void Player::update(sf::RenderTarget* target)
{
    // Bounce Collide


    this->updateInput();
}

void Player::render(sf::RenderTarget* target)
{
    target->draw(this->shape);
}
