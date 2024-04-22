/* Doppler Effect on Music */
#include "Doppler.h"

bool DopplerRadio::load_images()
{
    if(!radioTexture.loadFromFile("../assets/radio.png")) {
        return false;
    }
    return true;
}

bool DopplerRadio::load_sprites()
{
    // bgSprite.setTexture(bgScene);
    //bgSprite.setScale(sf::Vector2f(0.5, 0.5f));
    radioSprite.setTexture(radioTexture);
    radioSprite.setOrigin(sf::Vector2f(50.f,37.5f));
    radioSprite.setPosition(sf::Vector2f(400.f,300.f));
    // radioSprite.setScale(sf::Vector2f(5.f, 5.f));

    // square.setSize(sf::Vector2f(450.f,450.f));
    circle.setRadius(225.f);
    circle.setOrigin(225.f,225.f);
    circle.setPosition(sf::Vector2f(400.f,300.f));
    circle.setFillColor(sf::Color::Blue);
    circle.setOutlineColor(sf::Color::White);
    circle.setOutlineThickness(-2.f);
    circleBounds = circle.getGlobalBounds();
    return true;
}

bool DopplerRadio::load_sounds()
{
    if (!musicBuffer.loadFromFile("../assets/easy_cheesy.mp3")) {
        return false;
	}
    musicSound.setBuffer(musicBuffer);
    musicSound.setVolume(100.f);
    musicSound.setLoop(true);
    return true;
}

bool DopplerRadio::load_text()
{
    if (!txtFont.loadFromFile("../assets/Gluten-Medium.ttf")) {
        return false;
    }
    for(int i=0;i<2;i++) {
        txtText[i].setFont(txtFont);
        txtText[i].setCharacterSize(35);
        txtText[i].setFillColor(sf::Color::Blue);
        txtText[i].setOutlineColor(sf::Color::White);
        txtText[i].setOutlineThickness(2);
        // txtText[i].setRotation(10);
        // txtText[i].setLetterSpacing(2.0f);
        // txtText[i].setStyle(sf::Text::Style::Italic | sf::Text::Style::Bold);
    }
    txtText[0].setString("Doppler Effect");
    txtText[0].setOrigin(sf::Vector2f(136.f,17.f));
    txtText[0].setPosition(sf::Vector2f(400.f,30.f));
    txtText[1].setString("Volume : ");
    txtText[1].setPosition(sf::Vector2f(30.f,530.f));
    return true;
}
