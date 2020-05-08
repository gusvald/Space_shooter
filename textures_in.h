//
// Created by Gus on 05.05.2020.
//

#ifndef SPACESHOOTER_TEXTURES_IN_H
#define SPACESHOOTER_TEXTURES_IN_H

#include <SFML/Graphics.hpp>
#include "enemy.h"


class textures_in {
    int width = 1024;
    int height = 768;
public:
    int get_width() const;

    int get_height() const;

    textures_in();

    sf::Texture shipTex;
    sf::Texture enemyTex;
    sf::Texture enemy1Tex;
    sf::Texture laserTex;
    sf::Texture laserTex1;
    sf::Texture specialTex;
    sf::Texture enemy2Tex;
    sf::Texture Game_logo;
    sf::Font font;
    sf::Text LifeInfo;
    sf::Text ScoreInfo;
    sf::Text GameOver;
    sf::Text Menu[3];


    std::vector<enemy> objects;
};


#endif //SPACESHOOTER_TEXTURES_IN_H
