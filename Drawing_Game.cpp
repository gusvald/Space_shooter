//
// Created by Gus on 05.05.2020.
//

#include <cstring>
#include <iostream>
#include "Drawing_Game.h"


Drawing_Game::Drawing_Game() {
    shipTex.loadFromFile("../Textures/spaceship.png");
    enemyTex.loadFromFile("../Textures/asteroid.png");
    enemy1Tex.loadFromFile("../Textures/asteroid2.png");
    enemy2Tex.loadFromFile("../Textures/asteroid3.png");
    laserTex.loadFromFile("../Textures/laser1.png");
    laserTex1.loadFromFile("../Textures/laser2.png");
    specialTex.loadFromFile("../Textures/levelup.png");

    font.loadFromFile("../Fonts/8-bit.ttf");
    if (!font.loadFromFile("../Fonts/8-bit.ttf")) {
        std::cerr << strerror(errno) << std::endl;
        abort();
    }


    LifeInfo.setFont(font);
    LifeInfo.setCharacterSize(30);
    LifeInfo.setPosition(20,0);

    ScoreInfo.setFont(font);
    ScoreInfo.setCharacterSize(30);
    ScoreInfo.setPosition(750,0);

    GameOver.setFont(font);
    GameOver.setCharacterSize(120);
    GameOver.setString("GameOver");
    GameOver.setPosition(275,0);


}

int Drawing_Game::get_width() const {
    return width;
}

int Drawing_Game::get_height() const {
    return height;
}
