//
// Created by Gus on 05.05.2020.
//

#ifndef SPACESHOOTER_PLAY_GAME_H
#define SPACESHOOTER_PLAY_GAME_H
#include <SFML/Graphics.hpp>
#include "Drawing_Game.h"
#include "spaceship.h"



class Play_game {
    Drawing_Game space;
public:
    int laser_level;
    Play_game();
    void playing();


};


#endif //SPACESHOOTER_PLAY_GAME_H
