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
    bool Error = false;
public:
    int get_width() const;

    int get_height() const;

    TexturesIn();

    sf::Font font;
    sf::Texture textures[10];

    sf::Text LifeInfo;
    sf::Text ScoreInfo;
    sf::Text GameOver;
    sf::Text RestartInfo;
    sf::Text BackMenuInfo;
    sf::Text Menu[3];


    std::vector<Enemy> objects;
};


#endif //SPACESHOOTER_TEXTURESIN_H
