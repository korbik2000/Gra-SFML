#include "menu.h"
#include <iostream>

menu::menu(float x, float y)
{
    if(!font.loadFromFile("arial.ttf"))
    {
        std::cerr << "Could not load font" << std::endl;
    }

    Menu[0].setFont(font);
    Menu[0].setFillColor(sf::Color::Red);
    Menu[0].setOutlineColor(sf::Color::White);
    Menu[0].setOutlineThickness(2.5);
    Menu[0].setString("Jeden Gracz");
    Menu[0].setPosition(sf::Vector2f(x/2 - Menu[0].getLocalBounds().width/2, y/(LICZBA_OPCJI+1)*1));

    Menu[1].setFont(font);
    Menu[1].setFillColor(sf::Color::Black);
    Menu[1].setOutlineColor(sf::Color::White);
    Menu[1].setOutlineThickness(2.5);
    Menu[1].setString("Dwoch Graczy (Online)");
    Menu[1].setPosition(sf::Vector2f(x/2 - Menu[1].getLocalBounds().width/2, y/(LICZBA_OPCJI+1)*2));

    Menu[2].setFont(font);
    Menu[2].setFillColor(sf::Color::Black);
    Menu[2].setOutlineColor(sf::Color::White);
    Menu[2].setOutlineThickness(2.5);
    Menu[2].setString("Tryb nieskonczony");
    Menu[2].setPosition(sf::Vector2f(x/2 - Menu[2].getLocalBounds().width/2, y/(LICZBA_OPCJI+1)*3));

    Menu[3].setFont(font);
    Menu[3].setFillColor(sf::Color::Black);
    Menu[3].setOutlineColor(sf::Color::White);
    Menu[3].setOutlineThickness(2.5);
    Menu[3].setString("Wyjscie");
    Menu[3].setPosition(sf::Vector2f(x/2 - Menu[3].getLocalBounds().width/2, y/(LICZBA_OPCJI+1)*4));

    choose = 0;
}

menu::~menu()
{
}

void menu::draw(sf::RenderWindow &window)
{
    for(int i = 0; i < LICZBA_OPCJI; i++)
    {
        window.draw(Menu[i]);
    }
}

void menu::MoveUp()
{
    if ( choose - 1 >= 0 )
    {
        Menu[choose].setFillColor(sf::Color::Black);
        choose--;
        Menu[choose].setFillColor(sf::Color::Red);
    }
}

void menu::MoveDown()
{
    if ( choose + 1 < LICZBA_OPCJI )
    {
        Menu[choose].setFillColor(sf::Color::Black);
        choose++;
        Menu[choose].setFillColor(sf::Color::Red);
    }
}
