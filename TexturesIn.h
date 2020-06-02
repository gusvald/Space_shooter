//
// Created by Gus on 05.05.2020.
//

#ifndef SPACESHOOTER_TEXTURESIN_H
#define SPACESHOOTER_TEXTURESIN_H

#include <SFML/Graphics.hpp>
#include "Enemy.h"


class TexturesIn {
    int width = 1024;
    int height = 768;
public:
    int get_width() const;

    int get_height() const;

    TexturesIn();

    sf::Font font;

    sf::Texture shipTex;
    sf::Texture enemyTex;
    sf::Texture enemy1Tex;
    sf::Texture laserTex;
    sf::Texture laserTex1;
    sf::Texture specialTex;
    sf::Texture enemy2Tex;
    sf::Texture Game_logo;
    sf::Texture Game_sigTex;
    sf::Texture ExplosionTex;

    sf::Text LifeInfo;
    sf::Text ScoreInfo;
    sf::Text GameOver;
    sf::Text RestartInfo;
    sf::Text BackMenuInfo;
    sf::Text Menu[3];


    std::vector<Enemy> objects;
};


#endif //SPACESHOOTER_TEXTURESIN_H
