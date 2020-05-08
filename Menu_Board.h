//
// Created by Gus on 05.05.2020.
//

#ifndef SPACESHOOTER_MENU_BOARD_H
#define SPACESHOOTER_MENU_BOARD_H

#include "SFML/Graphics.hpp"
#include "textures_in.h"
#include "Drawing_game.h"
#include "Results_board.h"


class Menu_Board {
    int Selected;
    int Page = 3;
public:

    sf::Sprite shape;
    sf::Sprite logo;

    Menu_Board();

    textures_in space;

    void moveUP();

    void moveDOWN();

    int GetSelected() const;

    void Events(const sf::Event &event);

    void DrawingMenu(sf::RenderWindow &win);

    int getPage();

    void setPage3();
};


#endif //SPACESHOOTER_MENU_BOARD_H
