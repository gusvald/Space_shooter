//
// Created by Gus on 05.05.2020.
//

#include <cstring>
#include <iostream>
#include "TexturesIn.h"


TexturesIn::TexturesIn() {

    shipTex.loadFromFile("../Textures/Spaceship.png");
    enemyTex.loadFromFile("../Textures/asteroid.png");
    enemy1Tex.loadFromFile("../Textures/asteroid2.png");
    enemy2Tex.loadFromFile("../Textures/asteroid3.png");
    laserTex.loadFromFile("../Textures/laser1.png");
    laserTex1.loadFromFile("../Textures/laser2.png");
    specialTex.loadFromFile("../Textures/levelup.png");
    Game_logo.loadFromFile("../Textures/Game_logo.png");
    Game_sigTex.loadFromFile("../Textures/Jupiter.png");
    ExplosionTex.loadFromFile("../Textures/Explosion.png");

    font.loadFromFile("../Fonts/8-bit.ttf");
    if (!font.loadFromFile("../Fonts/8-bit.ttf")) {
        std::cerr << strerror(errno) << std::endl;
        abort();
    }


    this->LifeInfo.setFont(font);
    this->LifeInfo.setCharacterSize(30);
    this->LifeInfo.setPosition(20, 0);

    this->ScoreInfo.setFont(font);
    this->ScoreInfo.setCharacterSize(30);
    this->ScoreInfo.setPosition(750, 0);

    this->GameOver.setFont(font);
    this->GameOver.setCharacterSize(120);
    this->GameOver.setString("GameOver");
    this->GameOver.setPosition(275, 0);

    this->Menu[0].setFont(font);
    this->Menu[0].setCharacterSize(120);
    this->Menu[0].setString("PLAY");
    this->Menu[0].setPosition(35, 150);

    this->Menu[1].setFont(font);
    this->Menu[1].setCharacterSize(100);
    this->Menu[1].setString("HIGH SCORES");
    this->Menu[1].setPosition(35, 300);

    this->Menu[2].setFont(font);
    this->Menu[2].setCharacterSize(120);
    this->Menu[2].setString("EXIT");
    this->Menu[2].setPosition(35, 450);

    this->BackMenuInfo.setFont(font);
    this->BackMenuInfo.setCharacterSize(30);
    this->BackMenuInfo.setString("Press M to show Menu");
    this->BackMenuInfo.setPosition(700, 0);

    this->RestartInfo.setFont(font);
    this->RestartInfo.setCharacterSize(30);
    this->RestartInfo.setString("Press R to Restart      Press M to show Menu");
    this->RestartInfo.setPosition(200, 30);

}

int TexturesIn::get_width() const {
    return width;
}

int TexturesIn::get_height() const {
    return height;
}
