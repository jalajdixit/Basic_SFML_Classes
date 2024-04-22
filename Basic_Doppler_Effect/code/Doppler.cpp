/* Doppler Effect on Music */
#include "Doppler.h"

bool DopplerRadio::init_game()
{
    if (!load_text() | !load_sounds() | !load_images() | !load_sprites()) {
	  return false;		
	}
    // std::cout << txtText.getGlobalBounds().getPosition().x << "-" << txtText.getGlobalBounds().getPosition().y << std::endl;
    // std::cout << txtText.getGlobalBounds().getSize().x << "-" << txtText.getGlobalBounds().getSize().y << std::endl;
    musicSound.play();

    return true;
}

void DopplerRadio::draw_windows(sf::RenderWindow &window)
{
    window.draw(circle);
    window.draw(radioSprite);
    window.draw(txtText[0]);
    window.draw(txtText[1]);
}

void DopplerRadio::update_mouse_pos(sf::RenderWindow &window) {
    mousePosView = window.mapPixelToCoords(sf::Mouse::getPosition(window));
}

void DopplerRadio::update_volume() {
    if(!circleBounds.contains(mousePosView)) {
        musicSound.setVolume(0.f);
        txtText[1].setString("Volume : 0");
    }
    else {
        dist = std::sqrt(std::pow(400.f-mousePosView.x,2.f) + std::pow(300.f-mousePosView.y,2.f));
        perc = (dist*100.f)/225.f;
        if(perc>100.f) {
            musicSound.setVolume(0.f);
            txtText[1].setString("Volume : 0");
        }
        else {
            musicSound.setVolume(100.f-perc);
            txtText[1].setString("Volume : " + std::to_string(static_cast<int>(100.f-perc)));
        }
        // std::cout << mousePosView.x << " -- " << mousePosView.y << std::endl;
        // std::cout << dist << " = " << (dist*100.f)/225.f << std::endl;
    }
}
