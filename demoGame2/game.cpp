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
const bool Game::running() const
{
    return this->window->isOpen();
}

void Game::pollEvents()
{
    while(this->window->pollEvent(this->sfmlEvent))
    {
        switch (this->sfmlEvent.type)
        {
            case sf::Event::Closed:
                this->window->close();
                break;
        }
    }
}

void Game::update()
{
    this->pollEvents();
}

void Game::render()
{
    this->window->clear();

    this->player.render(this->window);

    this->window->display();
}
