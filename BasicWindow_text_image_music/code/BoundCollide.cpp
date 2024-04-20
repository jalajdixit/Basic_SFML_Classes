/* Basic Bounding boxes & collisions */
#include "BoundCollide.h"

bool BoundCollide::init_game()
{
    if (!load_text() | !load_sounds() | !load_images() | !load_sprites()) {
	  return false;		
	}

    musicSound.play();

    return true;
}

void BoundCollide::draw_windows(sf::RenderWindow &window)
{
    window.draw(bgSprite);
    window.draw(txtText);
}
