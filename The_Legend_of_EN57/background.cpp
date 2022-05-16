#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>
#include "background.h"

background::background(sf::Sprite back, sf::Sprite track_sprite)
{
    background_speed = 60.0;
    background1 = back;
    background2 = back;

    background2.setPosition(0.0,-720.0);

    track = track_sprite;

    for(unsigned long long i = 0; i < 5; i++)
    {
        track_v1.emplace_back(track);
        track_v2.emplace_back(track);
    }
    for(unsigned long long i = 0; i < 5; i++)
    {
        track_v1[i].setPosition(130 + i*180 + i*60,0.0);
        track_v2[i].setPosition(130 + i*180 + i*60,-720.0);
    }

}

void background::background_step(sf::Time elapsed, sf::RenderWindow &window_l)
{
    window_l.draw(background1);
    window_l.draw(background2);

    for(unsigned long long i = 0; i < 5; i++)
    {
        window_l.draw(track_v1[i]);
        window_l.draw(track_v2[i]);
    }

    background1.move(0.0, background_speed*elapsed.asSeconds());
    background2.move(0.0, background_speed*elapsed.asSeconds());

    for(unsigned long long i = 0; i < 5; i++)
    {
        track_v1[i].move(0.0, background_speed*elapsed.asSeconds());
        track_v2[i].move(0.0, background_speed*elapsed.asSeconds());
    }

    if(background1.getPosition().y >= 720.0)
    {
        background1.setPosition(0.0,-720);
    }
    if(background2.getPosition().y >= 720.0)
    {
        background2.setPosition(0.0,-720.0);
    }

    for(unsigned long long i = 0; i < 5; i++)
    {
        if(track_v1[i].getPosition().y >= 720.0)
        {
            track_v1[i].setPosition(130 + i*180 + i*60,-720.0);
        }
        if(track_v2[i].getPosition().y >= 720.0)
        {
            track_v2[i].setPosition(130 + i*180 + i*60, -720.0);
        }
    }
}
