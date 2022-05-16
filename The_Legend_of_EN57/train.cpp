#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include "train.h"
#include "Functions.h"
#include <iostream>
#include <vector>

train::train()
{
}

EN57::EN57()
{
    train_speed_front = 140.0;
    train_speed_back = 80.0;
    train_speed_h = 240;

    train_t = loadTexture("en57.png");
    train_s.setTexture(train_t);
    train_s.setScale(1.6,1.0);
    train_s.setPosition(620,520);

    hp_t = loadTexture ("hp.png");
    hp_s.setTexture(hp_t);
    hp_s.setScale(2.0,2.0);
    hp_s.setPosition(1220.0,5.0);
    hp_s = hp_s;
    hp = 3;
}

EP07::EP07()
{
    train_speed_front = 140.0;
    train_speed_back = 80.0;
    train_speed_h = 240;

    train_t = loadTexture("ep07.png");
    train_s.setTexture(train_t);
    train_s.setScale(1.6,1.0);
    train_s.setPosition(620,520);

    hp_t = loadTexture ("hp.png");
    hp_s.setTexture(hp_t);
    hp_s.setScale(2.0,2.0);
    hp_s.setPosition(60.0,5.0);
    hp_s = hp_s;
    hp = 3;
}
