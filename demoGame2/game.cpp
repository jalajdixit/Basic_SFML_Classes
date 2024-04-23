/* Demo Game 2 */
#include "game.h"

void Game::initvariables()
{
    this->endGame = false;
    this->spawnTimerMax = 10.f;
    this->spawnTimer=this->spawnTimerMax;
    this->maxSwagBalls = 10;
}

void Game::initWindow()
{
    // this->videoMode = sf::VideoMode::getDesktopMode();
    this->videoMode = sf::VideoMode(800,600);
    this->window = new sf::RenderWindow(this->videoMode, "G A M E - 2", sf::Style::Close | sf::Style::Titlebar);
    this->window->setFramerateLimit(60);
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

void Game::spawnSwagBalls()
{
    if (this->spawnTimer  <this->spawnTimerMax) {
        this->spawnTimer += 1.f;
    } else {
        if(this->swagBalls.size() < this->maxSwagBalls) {
            this->swagBalls.push_back(SwagBall(*this->window));
            this->spawnTimer = 0.f;
        }       
    }
    
}

void Game::updateCollision()
{
    // Check the collision
    for(size_t i =0; i<this->swagBalls.size(); i++)
    {
        if(this->player.getShape().getGlobalBounds().intersects(this->swagBalls[i].getShape().getGlobalBounds()))
        {
            this->swagBalls.erase(this->swagBalls.begin() + i);
        }
    }
}

void Game::update()
{
    this->pollEvents();

    this->spawnSwagBalls();
    this->player.update(this->window);
    this->updateCollision();
}

void Game::render()
{
    this->window->clear();

    this->player.render(this->window);

    for(auto i : this->swagBalls) {
        i.render(*this->window);
    }

    this->window->display();
}
