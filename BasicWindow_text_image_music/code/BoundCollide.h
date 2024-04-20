/* Basic Bounding boxes & collisions */
#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

class BoundCollide 
{
    private:
        sf::Texture bgScene;
        sf::Sprite  bgSprite;

        sf::Font txtFont;
        sf::Text txtText;

        sf::SoundBuffer musicBuffer;
        sf::Sound       musicSound;

        bool load_images();
        bool load_sprites();
        bool load_sounds();
        bool load_text();

    public:
        bool init_game();
        
        void draw_windows(sf::RenderWindow& window);
};
