#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Network.hpp>
#include "level.h"
#include "train.h"
#include "rock.h"
#include "background.h"
#include "menu.h"
#include "Functions.h"
#include "menu_wyb_lvl.h"
#include "level_endless.h"
#include "level_online.h"
#include "menu_wyb_online.h"
#include <iostream>
#include <string>
#include <sstream>
#include <windows.h>

int main()
{
    sf::RenderWindow window(sf::VideoMode(1280, 720), "The legend of EN57");

    /////////////////////////////////////Textury mapy

    sf::Texture track_texture = loadTexture("track.png");
    track_texture.setRepeated(true);
    sf::Sprite track_sprite;
    track_sprite.setTexture(track_texture);
    track_sprite.setTextureRect(sf::IntRect(0, 0, 60, 720));

    sf::Texture background_texture = loadTexture("background.png");
    sf::Sprite background_sprite;
    background_sprite.setTexture(background_texture);

    ///////////////////////////////////Textury obiekty

    sf::Texture rock_texture = loadTexture("rock.png");
    sf::Sprite rock_sprite;
    rock_sprite.setTexture(rock_texture);
    rock_sprite.setScale(0.08,0.08);

    sf::Texture tlo_menu_t = loadTexture("tlo_menu.jpg");
    sf::Sprite tlo_menu;
    tlo_menu.setTexture(tlo_menu_t);

    ////////////////////////////////////Obiekty klas

    std::unique_ptr<level> poziom;
    std::unique_ptr<level_endless> poziom_nieskonczony;
    std::unique_ptr<level_online> poziom_online;
    background* tlo = new background(background_sprite, track_sprite);

    menu* main_menu = new menu(window.getSize().x, window.getSize().y);
    menu_wyb_lvl* menu_lvl = new menu_wyb_lvl(window.getSize().x, window.getSize().y);
    menu_wyb_online* menu_online = new menu_wyb_online(window.getSize().x, window.getSize().y);

    //////////////////////////////////Inne

    sf::Clock clock_elapsed;
    sf::Clock clock_overall;
    sf::Time elapsed;

    int menu_choose = 0;
    int lvl_choose = 0;
    srand(time(NULL));

    std::ostringstream lvl;
    bool init;

    sf::Font Arial;
    if(!Arial.loadFromFile("arial.ttf"))
    {
        std::cerr << "Could not load font" << std::endl;
    }

    ////////////////////////////////Online

    sf::IpAddress ip = sf::IpAddress::getLocalAddress();
    sf::TcpSocket socket;
    sf::TcpListener listener;
    bool connected = false;
    int online_choose = 0;
    char connectionType = 'n';

    //////////////////////////////////Loop gry

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if(event.type == sf::Event::Closed)
            {
                window.close();
            }

            if(menu_choose == 1)
            {
                switch(event.type)
                {
                case sf::Event::KeyReleased:
                    switch(event.key.code)
                    {
                    case sf::Keyboard::Up:
                        menu_lvl->MoveUp();
                        break;

                    case sf::Keyboard::Down:
                        menu_lvl->MoveDown();
                        break;

                    case sf::Keyboard::Return:
                        lvl_choose = menu_lvl->wybor() + 1;
                        lvl.str("");
                        lvl << "lvl" << lvl_choose << ".txt";
                        menu_choose = 6;
                        break;
                    }
                    break;
                }
            }

            if(menu_choose == 2)
                switch(event.type)
                {
                case sf::Event::KeyReleased:
                    switch(event.key.code)
                    {
                    case sf::Keyboard::Up:
                        menu_online->MoveUp();
                        break;

                    case sf::Keyboard::Down:
                        menu_online->MoveDown();
                        break;

                    case sf::Keyboard::Return:
                        online_choose = menu_online->wybor() + 1;
                        if(online_choose == 1)
                        {
                            connectionType = 'h';
                        }
                        else if(online_choose == 2)
                        {
                            connectionType = 'c';
                        }
                        menu_choose = 7;
                        break;
                    }
                    break;
                }

            if(menu_choose == 0)
            {
                switch(event.type)
                {
                case sf::Event::KeyReleased:
                    switch(event.key.code)
                    {
                    case sf::Keyboard::Up:
                        main_menu->MoveUp();
                        break;

                    case sf::Keyboard::Down:
                        main_menu->MoveDown();
                        break;

                    case sf::Keyboard::Return:
                        menu_choose = main_menu->wybor() + 1;
                        break;
                    }
                    break;
                }
            }            
        }

        window.clear(sf::Color(255,255,255));

        switch(menu_choose)
        {
        case 0 :
            window.draw(tlo_menu);
            main_menu->draw(window);
            break;
        case 1 :
            window.draw(tlo_menu);
            menu_lvl->draw(window);
            break;
        case 2 :
            window.draw(tlo_menu);
            menu_online->draw(window);
            break;
        case 6 :
            //Init
            if(init == false)
            {
                poziom = std::make_unique<level>(window.getSize(), rock_sprite, new EN57());
                tlo = new background(background_sprite, track_sprite);
                poziom->apply_rocks(lvl.str());
                clock_overall.restart();
                clock_elapsed.restart();
                init = true;
            }
            else if(init == true)
            {
                elapsed = clock_elapsed.restart();
                tlo->background_step(elapsed, window);
                poziom->step(elapsed, clock_overall.getElapsedTime(), window);
                //koniec
                if(poziom->Train->getHP() <= 0)
                {
                    //porazka
                    Wyswietl(Arial,"Porazka",360.0,250.0,window);
                    window.display();
                    Sleep(3000);
                    init = false;
                    poziom.reset(nullptr);
                    lvl_choose = 0;
                    menu_choose = 0;
                } else if(poziom->check_win() == true)
                    {
                        Wyswietl(Arial,"Zwyciestwo",320.0,250.0,window);
                        window.display();
                        Sleep(3000);
                        init = false;
                        poziom.reset(nullptr);
                        lvl_choose = 0;
                        menu_choose = 0;
                    }


            }
            break;
        case 7:
            if(init == false)
            {
                poziom_online = std::make_unique<level_online>(window.getSize(), rock_sprite, new EN57(), new EP07());
                tlo = new background(background_sprite, track_sprite);
                init = true;
            }
            if(connected == false)
            {
                if(connectionType == 'h')
                {
                    listener.listen(7777);
                    listener.accept(socket);
                }
                else if(connectionType == 'c')
                {
                    socket.connect(ip, 7777);
                }

                if(socket.getRemoteAddress() != sf::IpAddress::None)
                {
                    connected = true;
                }
                clock_overall.restart();
                clock_elapsed.restart();
            }

            if((connected == true)&&(init==true))
            {
                sf::Packet pakiet;
                pakiet << poziom_online->Train->train_s.getGlobalBounds().left << poziom_online->Train->train_s.getGlobalBounds().top;
                std::string random;

                if(connectionType == 'h')
                {
                    random = RandomLine();
                    pakiet << random;
                }
                socket.send(pakiet);

                sf::Packet odbior;
                socket.receive(odbior);
                float second_pos_x, second_pos_y;
                odbior >> second_pos_x >> second_pos_y;
                if(connectionType == 'c')
                {
                    odbior >> random;
                }

                elapsed = clock_elapsed.restart();
                tlo->background_step(elapsed, window);
                poziom_online->step(elapsed, clock_overall.getElapsedTime(), window, random, second_pos_x, second_pos_y);
            }

            break;
        case 3:
            if(init == false)
            {
                poziom_nieskonczony = std::make_unique<level_endless>(window.getSize(), rock_sprite, new EN57());
                tlo = new background(background_sprite, track_sprite);
                clock_overall.restart();
                clock_elapsed.restart();
                init = true;
            }
            else if(init == true)
            {
                elapsed = clock_elapsed.restart();
                tlo->background_step(elapsed, window);
                poziom_nieskonczony->step(elapsed, clock_overall.getElapsedTime(), window);
                //koniec
                if(poziom_nieskonczony->Train->getHP() <= 0)
                {
                    Wyswietl(Arial,"Koniec",460.0,150.0,window);
                    int wynik = poziom_nieskonczony->getScore();
                    char fale = static_cast<char>(wynik+48);
                    std::string fale_wynik = "fale: ";
                    fale_wynik += fale;
                    Wyswietl(Arial,fale_wynik,460.0,450.0,window);
                    window.display();
                    Sleep(3000);
                    init = false;
                    poziom_nieskonczony.reset(nullptr);
                    menu_choose = 0;
                }
            }
            break;
        case 4:
            window.close();
            break;
        }

        window.display();
    }

    delete tlo;
    delete main_menu;
    delete menu_lvl;

    return 0;
}
