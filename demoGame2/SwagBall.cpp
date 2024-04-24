#include "SwagBall.h"

void SwagBall::initShape(const sf::RenderWindow& window)
{
    this->shape.setRadius(static_cast<float>(rand()%10+10));
    this->shape.setOutlineColor(sf::Color::White);
    sf::Color color;
    switch(this->type)
    {
        case DEFAULT:
            color = sf::Color(rand()%255+1,rand()%255+1,rand()%255+1);
            this->shape.setOutlineThickness(0.f);
            break;
        case DAMAGING:
            color = sf::Color::Red;
            this->shape.setOutlineThickness(2.f);
            break;
        case HEALING:
            color = sf::Color::Green;
            this->shape.setOutlineThickness(2.f);
            break;
    }
    
    this->shape.setFillColor(color);
    float shapePosX = static_cast<float>(rand() % window.getSize().x - this->shape.getGlobalBounds().width);
    float shapePosY = static_cast<float>(rand() % window.getSize().y - this->shape.getGlobalBounds().height);
    if (shapePosX < 0.f) {
        shapePosX = 0.f;
    }
    if(shapePosY < 0.f){
        shapePosY = 0.f;
    }
    this->shape.setPosition(sf::Vector2f(shapePosX, shapePosY));
    // this->shape.setPosition(sf::Vector2f(
    //             static_cast<float>(rand() % window.getSize().x - this->shape.getGlobalBounds().width),
    //             static_cast<float>(rand() % window.getSize().y - this->shape.getGlobalBounds().height)));
}

SwagBall::SwagBall(const sf::RenderWindow& window, int type) : type(type)
{
    this->initShape(window);
}

SwagBall::~SwagBall()
{

}

const sf::CircleShape SwagBall::getShape() const
{
    return this->shape;
}

const int& SwagBall::getType() const
{
    return this->type;
}

void SwagBall::update()
{

}

void SwagBall::render(sf::RenderTarget &target)
{
    target.draw(this->shape);
}
