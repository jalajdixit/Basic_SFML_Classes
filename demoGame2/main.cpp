/* Demo Game 2 */
#include "game.h"

int main()
{
    // Initialize random seed
    srand(static_cast<unsigned>(time(0)));

    // Initialize Game object
    Game game;

    // Game Loop
    while(game.running())
    {
        game.update();
        game.render();
    }

    // End of main
    return 0;
}