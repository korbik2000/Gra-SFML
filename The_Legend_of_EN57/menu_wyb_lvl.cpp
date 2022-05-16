#include "menu_wyb_lvl.h"
#include <iostream>

menu_wyb_lvl::menu_wyb_lvl(float x, float y)
{
    if(!font.loadFromFile("arial.ttf"))
    {
        std::cerr << "Could not load font" << std::endl;
    }

    Menu[0].setFont(font);
    Menu[0].setFillColor(sf::Color::Red);
    Menu[0].setOutlineColor(sf::Color::White);
    Menu[0].setOutlineThickness(2.5);
    Menu[0].setString("Poziom 1");
    Menu[0].setPosition(sf::Vector2f(x/2 - Menu[0].getLocalBounds().width/2, y/(LICZBA_POZIOMOW+1)*1));

    Menu[1].setFont(font);
    Menu[1].setFillColor(sf::Color::Black);
    Menu[1].setOutlineColor(sf::Color::White);
    Menu[1].setOutlineThickness(2.5);
    Menu[1].setString("Poziom 2");
    Menu[1].setPosition(sf::Vector2f(x/2 - Menu[1].getLocalBounds().width/2, y/(LICZBA_POZIOMOW+1)*2));

    Menu[2].setFont(font);
    Menu[2].setFillColor(sf::Color::Black);
    Menu[2].setOutlineColor(sf::Color::White);
    Menu[2].setOutlineThickness(2.5);
    Menu[2].setString("Poziom 3");
    Menu[2].setPosition(sf::Vector2f(x/2 - Menu[2].getLocalBounds().width/2, y/(LICZBA_POZIOMOW+1)*3));

    choose = 0;
}

menu_wyb_lvl::~menu_wyb_lvl()
{
}

void menu_wyb_lvl::draw(sf::RenderWindow &window)
{
    for(int i = 0; i < LICZBA_POZIOMOW; i++)
    {
        window.draw(Menu[i]);
    }
}

void menu_wyb_lvl::MoveUp()
{
    if ( choose - 1 >= 0 )
    {
        Menu[choose].setFillColor(sf::Color::Black);
        choose--;
        Menu[choose].setFillColor(sf::Color::Red);
    }
}

void menu_wyb_lvl::MoveDown()
{
    if ( choose + 1 < LICZBA_POZIOMOW )
    {
        Menu[choose].setFillColor(sf::Color::Black);
        choose++;
        Menu[choose].setFillColor(sf::Color::Red);
    }
}
