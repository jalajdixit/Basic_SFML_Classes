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

void Game::initSoundBuffer()
{
    if(!this->hitBuffer[SwagBallTypes::DEFAULT].loadFromFile("clickSound.mp3")) {
        std::cout << "ERROR::GAME::INITSOUNDBUFFER could not load clickSound.mp3" << std::endl;
    }
    if(!this->hitBuffer[SwagBallTypes::HEALING].loadFromFile("Coin07.wav")) {
        std::cout << "ERROR::GAME::INITSOUNDBUFFER could not load Coin07.wav" << std::endl;
    }
    if(!this->hitBuffer[SwagBallTypes::DAMAGING].loadFromFile("Swooosh07.wav")) {
        std::cout << "ERROR::GAME::INITSOUNDBUFFER could not load Swooosh07.wav" << std::endl;
    }
}

void Game::initSound()
{
    this->hitSound[SwagBallTypes::DEFAULT].setBuffer(this->hitBuffer[SwagBallTypes::DEFAULT]);
    this->hitSound[SwagBallTypes::DEFAULT].setVolume(50.f);
    this->hitSound[SwagBallTypes::HEALING].setBuffer(this->hitBuffer[SwagBallTypes::HEALING]);
    this->hitSound[SwagBallTypes::HEALING].setVolume(50.f);
    this->hitSound[SwagBallTypes::DAMAGING].setBuffer(this->hitBuffer[SwagBallTypes::DAMAGING]);
    this->hitSound[SwagBallTypes::DAMAGING].setVolume(50.f);
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

    this->endGametext.setFont(this->font);
    this->endGametext.setFillColor(sf::Color::Red);
    this->endGametext.setCharacterSize(35);
    this->endGametext.setPosition(100.f,250.f);
    this->endGametext.setString("G A M E - O V E R");
}

// Constructor & Destructor
Game::Game()
{
    this->initvariables();
    this->initWindow();
    this->initFont();
    this->initText();
    this->initSoundBuffer();
    this->initSound();
}

Game::~Game()
{
    delete this->window;
}

const bool& Game::getEndGame() const
{
    return this->endGame;
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

const int Game::randBallType() const
{
    int type = SwagBallTypes::DEFAULT;
    int randValue = rand()%100+1;

    if (randValue > 60 && randValue <= 80)
        type = SwagBallTypes::DAMAGING;
    else if (randValue > 80 && randValue <= 100)
        type = SwagBallTypes::DAMAGING;
    
    return type;
}

void Game::updatePlayer()
{
    this->player.update(this->window);
    if(this->player.getHp() <= 0)
        this->endGame = true;
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
                this->hitSound[SwagBallTypes::DEFAULT].play();
                break;
            case SwagBallTypes::DAMAGING:
                this->player.takeDamage(2);
                this->hitSound[SwagBallTypes::DAMAGING].play();
                break;
            case SwagBallTypes::HEALING:
                this->player.gainHealth(1);
                this->hitSound[SwagBallTypes::HEALING].play();
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

    if(!this->endGame) {
        this->spawnSwagBalls();
        this->updatePlayer();
        this->updateCollision();
        this->updateGui();
    }
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

    if(this->endGame)
        this->window->draw(endGametext);

    this->window->display();
}
