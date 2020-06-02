//
// Created by Gus on 07.05.2020.
//

#ifndef SPACESHOOTER_DRAWINGGAME_H
#define SPACESHOOTER_DRAWINGGAME_H

#include <SFML/Graphics.hpp>
#include "TexturesIn.h"
#include "Spaceship.h"
#include "MenuBoard.h"
#include "GameBoard.h"
#include "ResultsBoard.h"


class DrawingGame {
    TexturesIn space;
    bool IsAlreadySaved = false;
    int page = 0;
public:
    DrawingGame();

    void drawing();


    void events(sf::Event &event, sf::RenderWindow &win, Spaceship &player, MenuBoard &menu, GameBoard &play);

    void savinglogic(sf::RenderWindow &win, GameBoard &play, Spaceship &player, ResultsBoard &result);


};


#endif //SPACESHOOTER_DRAWINGGAME_H
