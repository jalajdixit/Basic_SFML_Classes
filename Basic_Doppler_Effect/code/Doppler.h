/* Doppler Effect on Music */
#pragma once
#include <iostream>
#include <cmath>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

class DopplerRadio 
{
    private:
        sf::Texture radioTexture;
        sf::Sprite  radioSprite;

        sf::CircleShape circle;
        sf::FloatRect circleBounds;

        sf::Font txtFont;
        sf::Text txtText[2];

        sf::SoundBuffer musicBuffer;
        sf::Sound       musicSound;

        sf::Vector2f mousePosView;

        float dist;
        float perc;

        bool load_images();
        bool load_sprites();
        bool load_sounds();
        bool load_text();

    public:
        bool init_game();

        void update_volume();
        
        void update_mouse_pos(sf::RenderWindow &window);

        void draw_windows(sf::RenderWindow& window);
};
