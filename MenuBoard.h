//
// Created by Gus on 05.05.2020.
//

#ifndef SPACESHOOTER_MENUBOARD_H
#define SPACESHOOTER_MENUBOARD_H

#include "SFML/Graphics.hpp"
#include "TexturesIn.h"
#include "ResultsBoard.h"

enum {
    Play = 0,
    Result = 1,
    Exit = 2,
    Menu = 3
};

class MenuBoard {
    int Selected;
    int Page = Menu;
public:
    sf::Sprite shape;
    sf::Sprite logo;

    MenuBoard();

    TexturesIn space;
    void moveUP();
    void moveDOWN();
    int GetSelected() const;
    void Events(const sf::Event &event);
    void DrawingMenu(sf::RenderWindow &win);
    int getPage();
    void setPage3();
};


#endif //SPACESHOOTER_MENUBOARD_H
