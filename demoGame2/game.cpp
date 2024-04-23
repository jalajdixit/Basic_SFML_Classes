/* Demo Game 2 */
#include "game.h"

void Game::initvariables()
{
    this->endGame = false;
    this->spawnTimerMax = 10.f;
    this->spawnTimer=this->spawnTimerMax;
    this->maxSwagBalls = 10;
    this->points = 0;
}

void Game::initWindow()
{
    // this->videoMode = sf::VideoMode::getDesktopMode();
    this->videoMode = sf::VideoMode(800,600);
    this->window = new sf::RenderWindow(this->videoMode, "G A M E - 2", sf::Style::Close | sf::Style::Titlebar);
    this->window->setFramerateLimit(60);
}

void Game::initFont()
{
    if(!this->font.loadFromFile("PressStart2P-Regular.ttf")) {
        std::cout << "ERROR::GAME::INITFONT could not load PressStart2P-Regular.ttf" << std::endl;
    }
}

void Game::initText()
{
    this->guiText.setFont(this->font);
    this->guiText.setFillColor(sf::Color::White);
    this->guiText.setCharacterSize(20);
    this->guiText.setPosition(10.f,10.f);
}

// Constructor & Destructor
Game::Game()
{
    this->initvariables();
    this->initWindow();
    this->initFont();
    this->initText();
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
            this->swagBalls.push_back(SwagBall(*this->window, rand()%SwagBallTypes::NROTYPES));
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
            switch (this->swagBalls[i].getType())
            {
            case SwagBallTypes::DEFAULT:
                this->points++;
                break;
            case SwagBallTypes::DAMAGING:
                this->player.takeDamage(1);
                break;
            case SwagBallTypes::HEALING:
                this->player.gainHealth(1);
                break;
            }
            
            this->swagBalls.erase(this->swagBalls.begin() + i);
            
        }
    }
}

void Game::updateGui()
{
    std::stringstream ss;

    ss  << "Points : " << this->points << "\n"
        << "Health : " << this->player.getHp() << "/" << this->player.getHpmax();

    this->guiText.setString(ss.str());
}

void Game::update()
{
    this->pollEvents();

    this->spawnSwagBalls();
    this->player.update(this->window);
    this->updateCollision();
    this->updateGui();
}

void Game::renderGui(sf::RenderTarget* target)
{
    target->draw(this->guiText);
}

void Game::render()
{
    this->window->clear();

    //Render Players & Swag Balls
    this->player.render(this->window);
    for(auto i : this->swagBalls) {
        i.render(*this->window);
    }

    //Render Gui
    this->renderGui(this->window);

    this->window->display();
}
