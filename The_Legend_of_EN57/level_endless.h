#ifndef LEVEL_ENDLESS_H
#define LEVEL_ENDLESS_H

#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <vector>

class level_endless
{
public:
    level_endless(sf::Vector2u, sf::Sprite, class train*);
    void step(sf::Time, sf::Time, sf::RenderWindow&);
    train *Train;
    int getScore() { return ac_line; }
private:
    friend class train;
    friend class rock;
    std::vector <class rock> rock_v;
    sf::Sprite rock_s;
    int window_x;
    int window_y;
    float cooldown_clock_summ;
    float collision_cooldown;
    float rock_fill_cooldown;
    void train_rock_collision();

    int ac_line;
};

#endif // LEVEL_ENDLESS_H
