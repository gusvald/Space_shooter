//
// Created by Gus on 05.05.2020.
//

#ifndef SPACESHOOTER_MENU_BOARD_H
#define SPACESHOOTER_MENU_BOARD_H
#include "SFML/Graphics.hpp"
#include "Drawing_Game.h"


class Menu_Board {

    int Selected;
public:
    Menu_Board();
    Drawing_Game space;
    void moveUP();
    void moveDOWN();
    int GetSelected() const;
    void DrawMenu();
};


#endif //SPACESHOOTER_MENU_BOARD_H
