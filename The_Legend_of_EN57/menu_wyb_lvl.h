#ifndef MENU_WYB_LVL_H
#define MENU_WYB_LVL_H

#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

#define LICZBA_POZIOMOW 3

class menu_wyb_lvl
{
public:
    menu_wyb_lvl(float,float);
    ~menu_wyb_lvl();
    void draw(sf::RenderWindow&);
    void MoveUp();
    void MoveDown();
    int wybor() {return choose;}

private:
    int choose;
    sf::Font font;
    sf::Text Menu[LICZBA_POZIOMOW];
};


#endif // MENU_WYB_LVL_H
