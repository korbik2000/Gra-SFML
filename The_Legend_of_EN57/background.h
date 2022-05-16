#ifndef BACKGROUND_H
#define BACKGROUND_H

#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <vector>

class background{
public:
    background(sf::Sprite, sf::Sprite);
    void background_step(sf::Time,sf::RenderWindow&);
private:
    sf::Sprite background1;
    sf::Sprite background2;
    sf::Sprite track;
    std::vector <sf::Sprite> track_v1;
    std::vector <sf::Sprite> track_v2;
    float background_speed;
};

#endif // BACKGROUND_H
