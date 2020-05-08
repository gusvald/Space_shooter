//
// Created by Gus on 07.05.2020.
//

#ifndef SPACESHOOTER_DRAWING_GAME_H
#define SPACESHOOTER_DRAWING_GAME_H

#include <SFML/Graphics.hpp>
#include "textures_in.h"
#include "spaceship.h"
#include "Menu_Board.h"
#include "Game_Board.h"
#include "Results_board.h"

class Drawing_game {
    textures_in space;
    bool Done = false;
    int page = 0;
public:
    Drawing_game();

    void drawing();

};


#endif //SPACESHOOTER_DRAWING_GAME_H
