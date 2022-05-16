#ifndef LEVEL_H
#define LEVEL_H

#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <vector>

class level{
public:
    level(sf::Vector2u, sf::Sprite, class train*);
    void step(sf::Time, sf::Time, sf::RenderWindow&);
    void apply_rocks(const std::string&);
    train *Train;
    bool check_win() {return win;}
private:
    friend class train;
    friend class rock;
    std::vector <class rock> rock_v;
    sf::Sprite rock_s;
    int window_x;
    int window_y;
    float cooldown_clock_summ;
    float collision_cooldown;
    bool win;
    void train_rock_collision();
};

#endif // LEVEL_H
