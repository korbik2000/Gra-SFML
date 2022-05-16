#ifndef MENU_WYB_ONLINE_H
#define MENU_WYB_ONLINE_H


#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

#define LICZBA_WYBOROW 2

class menu_wyb_online
{
public:
    menu_wyb_online(float,float);
    ~menu_wyb_online();
    void draw(sf::RenderWindow&);
    void MoveUp();
    void MoveDown();
    int wybor() {return choose;}

private:
    int choose;
    sf::Font font;
    sf::Text Menu[LICZBA_WYBOROW];
};

#endif // MENU_WYB_ONLINE_H
