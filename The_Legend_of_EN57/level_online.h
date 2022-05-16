#ifndef LEVEL_ONLINE_H
#define LEVEL_ONLINE_H

#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <vector>

class level_online
{
public:
    level_online(sf::Vector2u, sf::Sprite, class train*, train*);
    void step(sf::Time, sf::Time, sf::RenderWindow&, std::string, float, float);
    train *Train;
    train *Train_second;
private:
    friend class train;
    friend class rock;
    std::vector <class rock> rock_v;
    sf::Sprite rock_s;
    int window_x;
    int window_y;
    float cooldown_clock_summ;
    float collision_cooldown;
    float collision_cooldown_second;
    float rock_fill_cooldown;
    void train_rock_collision();
    int ac_line;
};

#endif // LEVEL_ONLINE_H
