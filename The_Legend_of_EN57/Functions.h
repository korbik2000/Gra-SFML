#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

sf::Texture loadTexture(const std::string&);
void Wyswietl(sf::Font, std::string, float, float, sf::RenderWindow&);
std::string RandomLine();

#endif // FUNCTIONS_H
