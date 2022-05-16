#ifndef ROCK_H
#define ROCK_H

#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

class rock{
public:
    rock(int,int,float,sf::Sprite&);
private:
    friend class level;
    friend class level_endless;
    friend class level_online;
    int track_number;
    float spawn_delay;
    float rock_speed;
    sf::Sprite rock_sprite;
};

#endif // ROCK_H
