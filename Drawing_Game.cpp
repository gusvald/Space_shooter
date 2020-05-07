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
    Game_logo.loadFromFile("../Textures/Zann_Consortium.png");

    font.loadFromFile("../Fonts/8-bit.ttf");
    if (!font.loadFromFile("../Fonts/8-bit.ttf")) {
        std::cerr << strerror(errno) << std::endl;
        abort();
    }


    this->LifeInfo.setFont(font);
    this->LifeInfo.setCharacterSize(30);
    this->LifeInfo.setPosition(20,0);

    this->ScoreInfo.setFont(font);
    this->ScoreInfo.setCharacterSize(30);
    this->ScoreInfo.setPosition(750,0);

    this->GameOver.setFont(font);
    this->GameOver.setCharacterSize(120);
    this->GameOver.setString("GameOver");
    this->GameOver.setPosition(275,0);

    this->Menu[0].setFont(font);
    this->Menu[0].setCharacterSize(200);
    this->Menu[0].setString("PLAY");
    this->Menu[0].setPosition(330,0);

    this->Menu[1].setFont(font);
    this->Menu[1].setCharacterSize(180);
    this->Menu[1].setString("HIGH SCORES");
    this->Menu[1].setPosition(80,150);

    this->Menu[2].setFont(font);
    this->Menu[2].setCharacterSize(200);
    this->Menu[2].setString("EXIT");
    this->Menu[2].setPosition(365,300);


}

int Drawing_Game::get_width() const {
    return width;
}

int Drawing_Game::get_height() const {
    return height;
}
