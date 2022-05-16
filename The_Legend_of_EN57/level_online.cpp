#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>
#include <fstream>
#include "train.h"
#include "rock.h"
#include "level_online.h"
#include "Functions.h"

level_online::level_online(sf::Vector2u window_size, sf::Sprite rock_sprite, train* tTrain, train* tsTrain)
{
    window_x = window_size.x;
    window_y = window_size.y;

    rock_s = rock_sprite;

    cooldown_clock_summ = 0.0;
    Train = tTrain;
    Train_second = tsTrain;

    collision_cooldown = 0.0;
    rock_fill_cooldown = 4.0;
    ac_line = 1;
}

void level_online::step(sf::Time elapsed, sf::Time time_overall, sf::RenderWindow &window_l, std::string skaly, float sec_player_left, float sec_player_top)
{
    //////////////////////////////////////////////////////////////// PORUSZANIE

    float ac_train_speed_front = Train->train_speed_front;
    float ac_train_speed_back = Train->train_speed_back;
    float ac_train_speed_h = Train->train_speed_h;

    if((Train->train_s.getGlobalBounds().top <= 0.0)&&(sf::Keyboard::isKeyPressed(sf::Keyboard::Up)))
    {
        ac_train_speed_front = 0.0;
    }
    else if((Train->train_s.getGlobalBounds().top + Train->train_s.getGlobalBounds().height >= window_y)&&(sf::Keyboard::isKeyPressed(sf::Keyboard::Down)))
    {
        ac_train_speed_back = 0.0;
    }

    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
    {
        Train->train_s.move(0.0, -ac_train_speed_front*elapsed.asSeconds());
    }

    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
    {
        Train->train_s.move(0.0, ac_train_speed_back*elapsed.asSeconds());
    }

    cooldown_clock_summ += elapsed.asSeconds();

    if((Train->train_s.getGlobalBounds().left <= 140)&&(sf::Keyboard::isKeyPressed(sf::Keyboard::Left)))
    {
        ac_train_speed_h = 0.0;
    }
    else if((Train->train_s.getGlobalBounds().left + Train->train_s.getGlobalBounds().width >= window_x - 140)&&(sf::Keyboard::isKeyPressed(sf::Keyboard::Right)))
    {
        ac_train_speed_h = 0.0;
    }

    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left) && (cooldown_clock_summ > 0.3))
    {
        Train->train_s.move(-ac_train_speed_h, 0.0);
        cooldown_clock_summ = 0.0;
    }

    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right) && (cooldown_clock_summ > 0.3))
    {
        Train->train_s.move(ac_train_speed_h, 0.0);
        cooldown_clock_summ = 0.0;
    }

    if((collision_cooldown <= 0.0))
    {
       window_l.draw(Train->train_s);
    }

    //////////////////////////////////////////////////////////////// SPAWN SKAL

    if(rock_fill_cooldown <= 0)
    {
        rock_fill_cooldown = 4.9;

        for(int i = 0; i < 5; i++)
        {
            if(skaly[i] == 'A')
            {
                rock_v.emplace_back(rock(ac_line, i+1, 60.0, rock_s));
            }
        }
        ac_line++;
    }

    rock_fill_cooldown -= elapsed.asSeconds();

    for(unsigned long long i = 0; i < rock_v.size(); i++)
    {
        if((time_overall.asSeconds() > rock_v[i].spawn_delay)&&(rock_v[i].rock_sprite.getGlobalBounds().top < window_y + 100))
        {
            window_l.draw(rock_v[i].rock_sprite);
            rock_v[i].rock_sprite.move(0.0,rock_v[i].rock_speed*elapsed.asSeconds());
        }
    }

    ///////////////////////////////////////////////////////////////// KOLIZJA ZE SKALA

    for(unsigned long long i = 0; i < rock_v.size(); i++)
    {
        sf::FloatRect rock_bounds = rock_v[i].rock_sprite.getGlobalBounds();

        if( (rock_bounds.intersects(Train->train_s.getGlobalBounds())) && (collision_cooldown <= 0.0))
        {
            collision_cooldown = 3.0;
            Train->hp -= 1;
        }
    }

    if((collision_cooldown <= 3.0)&&(collision_cooldown > 2.8))
    {
        window_l.draw(Train->train_s);
    }

    if((collision_cooldown < 2.5)&&(collision_cooldown > 2.0))
    {
        window_l.draw(Train->train_s);
    }

    if((collision_cooldown < 1.5)&&(collision_cooldown > 1.0))
    {
        window_l.draw(Train->train_s);
    }

    if((collision_cooldown < 0.5)&&(collision_cooldown > 0.0))
    {
        window_l.draw(Train->train_s);
    }

    collision_cooldown -= elapsed.asSeconds();

    ////////////////////////////////////////////////////////////////////// WYSWIETL HP

    for(int i = 0; i < Train->hp; i++)
    {
        Train->hp_s.setPosition(1220.0,5.0 + i*44 + i*8);
        window_l.draw(Train->hp_s);
    }
    Train->hp_s.setPosition(1220.0,5.0);

    ////////////////////////////////////////////////////////////////// DRUGI GRACZ ///////////////////////////////////////////////////////////

    Train_second->train_s.setPosition(sec_player_left,sec_player_top);

    if((collision_cooldown_second <= 0.0))
    {
       window_l.draw(Train_second->train_s);
    }

    ////////////////KOLIZJA 2 GRACZ

    for(unsigned long long i = 0; i < rock_v.size(); i++)
    {
        sf::FloatRect rock_bounds = rock_v[i].rock_sprite.getGlobalBounds();

        if( (rock_bounds.intersects(Train_second->train_s.getGlobalBounds())) && (collision_cooldown_second <= 0.0))
        {
            collision_cooldown_second = 3.0;
            Train_second->hp -= 1;
        }
    }

    if((collision_cooldown_second <= 3.0)&&(collision_cooldown_second > 2.8))
    {
        window_l.draw(Train_second->train_s);
    }

    if((collision_cooldown_second < 2.5)&&(collision_cooldown_second > 2.0))
    {
        window_l.draw(Train_second->train_s);
    }

    if((collision_cooldown_second < 1.5)&&(collision_cooldown_second > 1.0))
    {
        window_l.draw(Train_second->train_s);
    }

    if((collision_cooldown_second < 0.5)&&(collision_cooldown_second > 0.0))
    {
        window_l.draw(Train_second->train_s);
    }

    collision_cooldown_second -= elapsed.asSeconds();

    /////////////////////HP 2 GRACZ

    for(int i = 0; i < Train_second->hp; i++)
    {
        Train_second->hp_s.setPosition(60.0,5.0 + i*44 + i*8);
        window_l.draw(Train_second->hp_s);
    }
    Train_second->hp_s.setPosition(60.0,5.0);

}
