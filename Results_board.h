//
// Created by Gus on 05.05.2020.
//

#ifndef SPACESHOOTER_RESULTS_BOARD_H
#define SPACESHOOTER_RESULTS_BOARD_H

#include "SFML/Graphics.hpp"
#include "textures_in.h"
#include "spaceship.h"

class Results_board {
    textures_in space;
    int score_int[10];
    sf::Text Results[10];
    std::string score_string[10];

public:
    void DrawResults(sf::RenderWindow &win);

    void LoadResults();

    Results_board();
};


#endif //SPACESHOOTER_RESULTS_BOARD_H
