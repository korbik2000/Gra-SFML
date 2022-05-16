#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include "rock.h"
#include <iostream>
#include <vector>

rock::rock(int line_number, int track_nr, float trock_speed, sf::Sprite& rock_s)
{       
    track_number = track_nr;
    spawn_delay = 5*line_number;
    rock_speed = trock_speed;
    rock_sprite = rock_s;

    switch(track_nr)
    {
    case 1 :
        rock_sprite.setPosition(129.0,0.0);
        break;
    case 2 :
        rock_sprite.setPosition(369.0,0.0);
        break;
    case 3 :
        rock_sprite.setPosition(609.0,0.0);
        break;
    case 4 :
        rock_sprite.setPosition(850.0,0.0);
        break;
    case 5 :
        rock_sprite.setPosition(1090.0,0.0);
        break;
    }
}
