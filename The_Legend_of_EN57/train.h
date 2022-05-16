#ifndef TRAIN_H
#define TRAIN_H

#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

class train{
public:
    train();
    int getHP() {return hp;}
    sf::Sprite train_s;
protected:
    friend class level;
    friend class level_endless;
    friend class level_online;
    float train_speed_front;
    float train_speed_back;
    int train_speed_h;
    int hp;
    sf::Texture train_t;
    sf::Texture hp_t;
    sf::Sprite hp_s;
};

class EN57 : public train{
public:
    EN57();
};

class EP07 : public train{
public:
    EP07();
};

#endif // TRAIN_H
