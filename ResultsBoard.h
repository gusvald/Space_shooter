//
// Created by Gus on 05.05.2020.
//

#ifndef SPACESHOOTER_RESULTSBOARD_H
#define SPACESHOOTER_RESULTSBOARD_H

#include "SFML/Graphics.hpp"
#include "TexturesIn.h"
#include "Spaceship.h"

class ResultsBoard {
    TexturesIn space;
    int score_int[10];
    sf::Text Results[10];
    std::string score_string[10];

public:
    void DrawResults(sf::RenderWindow &win);

    void LoadResults();

    ResultsBoard();
};


#endif //SPACESHOOTER_RESULTSBOARD_H
