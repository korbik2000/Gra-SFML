#ifndef MENU_H
#define MENU_H

#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

#define LICZBA_OPCJI 4

class menu
{
public:
    menu(float,float);
    ~menu();
    void draw(sf::RenderWindow&);
    void MoveUp();
    void MoveDown();
    int wybor() {return choose; }

private:
    int choose;
    sf::Font font;
    sf::Text Menu[LICZBA_OPCJI];
};

#endif // MENU_H
