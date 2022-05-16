TEMPLATE = app
CONFIG += console c++17
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
        Functions.cpp \
        background.cpp \
        level.cpp \
        level_endless.cpp \
        level_online.cpp \
        main.cpp \
        menu.cpp \
        menu_wyb_lvl.cpp \
        menu_wyb_online.cpp \
        rock.cpp \
        train.cpp
INCLUDEPATH += "E:\Programy\QtCreator\SFML-2.5.1\include"
LIBS += -L"E:\Programy\QtCreator\SFML-2.5.1\lib"
CONFIG(debug, debug|release){
    LIBS += -lsfml-audio-d -lsfml-graphics-d -lsfml-network-d -lsfml-system-d -lsfml-window-d
} else {
    LIBS += -lsfml-audio -lsfml-graphics -lsfml-network -lsfml-system -lsfml-window
}

HEADERS += \
    Functions.h \
    background.h \
    level.h \
    level_endless.h \
    level_online.h \
    menu.h \
    menu_wyb_lvl.h \
    menu_wyb_online.h \
    rock.h \
    train.h
