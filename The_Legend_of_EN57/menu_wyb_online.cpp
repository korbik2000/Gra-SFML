#include "menu_wyb_online.h"
#include <iostream>

menu_wyb_online::menu_wyb_online(float x, float y)
{
    if(!font.loadFromFile("arial.ttf"))
    {
        std::cerr << "Could not load font" << std::endl;
    }

    Menu[0].setFont(font);
    Menu[0].setFillColor(sf::Color::Red);
    Menu[0].setOutlineColor(sf::Color::White);
    Menu[0].setOutlineThickness(2.5);
    Menu[0].setString("HOSTUJ");
    Menu[0].setPosition(sf::Vector2f(x/2 - Menu[0].getLocalBounds().width/2, y/(LICZBA_WYBOROW+1)*1));

    Menu[1].setFont(font);
    Menu[1].setFillColor(sf::Color::Black);
    Menu[1].setOutlineColor(sf::Color::White);
    Menu[1].setOutlineThickness(2.5);
    Menu[1].setString("DOLACZ");
    Menu[1].setPosition(sf::Vector2f(x/2 - Menu[1].getLocalBounds().width/2, y/(LICZBA_WYBOROW+1)*2));

    choose = 0;
}

menu_wyb_online::~menu_wyb_online()
{
}

void menu_wyb_online::draw(sf::RenderWindow &window)
{
    for(int i = 0; i < LICZBA_WYBOROW; i++)
    {
        window.draw(Menu[i]);
    }
}

void menu_wyb_online::MoveUp()
{
    if ( choose - 1 >= 0 )
    {
        Menu[choose].setFillColor(sf::Color::Black);
        choose--;
        Menu[choose].setFillColor(sf::Color::Red);
    }
}

void menu_wyb_online::MoveDown()
{
    if ( choose + 1 < LICZBA_WYBOROW )
    {
        Menu[choose].setFillColor(sf::Color::Black);
        choose++;
        Menu[choose].setFillColor(sf::Color::Red);
    }
}
