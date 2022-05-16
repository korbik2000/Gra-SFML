#include "Functions.h"
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>

sf::Texture loadTexture(const std::string &filename_with_path)
{
    sf::Texture texture;
    if (!texture.loadFromFile(filename_with_path)) {
        std::cerr << "Could not load texture" << std::endl;
    }
    return texture;
}

void Wyswietl(sf::Font font, std::string napis, float x, float y, sf::RenderWindow& window)
{
    sf::Text text;
    text.setFont(font);
    text.setFillColor(sf::Color::Red);
    text.setOutlineColor(sf::Color::White);
    text.setOutlineThickness(2.5);
    text.setString(napis);
    text.setPosition(sf::Vector2f(x,y));
    text.setScale(4.0,4.0);

    window.draw(text);
}

std::string RandomLine()
{
    std::string line;
    int liczba;
    char znak;

    for(int i = 0; i < 5; i++)
    {
        liczba = rand() % 2;
        znak = liczba + 64;
        line += znak;
    }

    if(line == "AAAAA")
    {
        return RandomLine();
    }
    else
    {
        return line;
    }
}
