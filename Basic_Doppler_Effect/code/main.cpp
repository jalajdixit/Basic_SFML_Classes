/* Doppler Effect on Music */
#include "Doppler.h"

using std::cout;
using std::endl;

int main()
{
    DopplerRadio dopR;
    if (!dopR.init_game()) {
		std::cout << "Unable to load game assets" << std::endl;
		return -1;
	}

    sf::RenderWindow window(sf::VideoMode(800, 600), "Doppler Effect", sf::Style::Titlebar | sf::Style::Close);
    window.setFramerateLimit(60);

    sf::Image game_icon;
    game_icon.loadFromFile("../assets/megaphone.png");
    window.setIcon(game_icon.getSize().x, game_icon.getSize().y, game_icon.getPixelsPtr());

    while(window.isOpen())
    {
        window.clear(sf::Color(25,180,200,0));
		dopR.draw_windows(window);
		window.display();

        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
            else if(event.type == sf::Event::MouseMoved) {
                dopR.update_mouse_pos(window);
                dopR.update_volume();
            }
        }
    }

    return 0;
}
