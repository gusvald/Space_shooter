//
// Created by Gus on 05.05.2020.
//

#ifndef SPACESHOOTER_DRAWING_GAME_H
#define SPACESHOOTER_DRAWING_GAME_H
#include <SFML/Graphics.hpp>
#include "enemy.h"


class Drawing_Game {
    int width = 1024;
    int height = 768;
public:
    int get_width() const;
    int get_height() const;
    Drawing_Game();
    sf::Texture shipTex;
    sf::Texture enemyTex;
    sf::Texture enemy1Tex;
    sf::Texture laserTex;
    sf::Texture laserTex1;
    sf::Texture specialTex;
    sf::Texture enemy2Tex;
    sf::Font font;
    sf::Text LifeInfo;
    sf::Text ScoreInfo;
    sf::Text GameOver;

    std::vector<enemy> objects;
};


#endif //SPACESHOOTER_DRAWING_GAME_H
