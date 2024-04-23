/* Basic Bounding boxes & collisions */
#include "BoundCollide.h"

bool BoundCollide::load_images()
{
    if(!bgScene.loadFromFile("../assets/bgScene.jpg")) {
        return false;
    }
    return true;
}

bool BoundCollide::load_sprites()
{
    bgSprite.setTexture(bgScene);
    //bgSprite.setScale(sf::Vector2f(0.5, 0.5f));
    return true;
}

bool BoundCollide::load_sounds()
{
    if (!musicBuffer.loadFromFile("../assets/easy_cheesy.mp3")) {
        return false;
	}
    musicSound.setBuffer(musicBuffer);
    musicSound.setVolume(30.0f);
    musicSound.setLoop(true);
    return true;
}

bool BoundCollide::load_text()
{
    if (!txtFont.loadFromFile("../assets/Gluten-Regular.ttf")) {
        return false;
    }
    txtText.setFont(txtFont);
    txtText.setString("Basic Window");
    txtText.setPosition(sf::Vector2f(300.0f, 25.0f));
    txtText.setCharacterSize(35);
    txtText.setFillColor(sf::Color::White);
    txtText.setOutlineColor(sf::Color::Cyan);
    //txtText.setOrigin(50.0f,50.0f);
    txtText.setOutlineThickness(2);
    // txtText.setRotation(10);
    txtText.setLetterSpacing(2.0f);
    // txtText.setStyle(sf::Text::Style::Italic | sf::Text::Style::Bold);
    return true;
}
