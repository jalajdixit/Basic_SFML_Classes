/* Demo Game 2 */
#include "game.h"

void Game::initvariables()
{
    this->endGame = false;
}

void Game::initWindow()
{
    // this->videoMode = sf::VideoMode::getDesktopMode();
    this->videoMode = sf::VideoMode(800,600);
    this->window = new sf::RenderWindow(this->videoMode, "G A M E - 2", sf::Style::Close | sf::Style::Titlebar);
}

// Constructor & Destructor
Game::Game()
{
    this->initvariables();
    this->initWindow();
}

Game::~Game()
{
    delete this->window;
}


//Functions
void Game::update()
{

}

void Game::render()
{

}