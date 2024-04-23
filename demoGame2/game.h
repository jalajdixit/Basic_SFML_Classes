/* Demo Game 2 */
#include <iostream>
#include <ctime>

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>

class Game
{
    private:
        sf::VideoMode videoMode;
        sf::RenderWindow* window;
        
        bool endGame;

        void initvariables();
        void initWindow();

    public:
    // Constructor & Destructor
        Game();
        ~Game();

    // Accessors

    //Modifiers

    //Functions
        void update();
        void render();
};
