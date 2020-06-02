//
// Created by Gus on 05.05.2020.
//

#include <cstring>
#include <iostream>
#include "TexturesIn.h"


TexturesIn::TexturesIn() {

    textures[0].loadFromFile("../Textures/Spaceship.png");
    if (!textures[0].loadFromFile("../Textures/Spaceship.png"))
        Error = true;

    textures[1].loadFromFile("../Textures/asteroid.png");
    if (!textures[1].loadFromFile("../Textures/asteroid.png"))
        Error = true;

    textures[2].loadFromFile("../Textures/asteroid2.png");
    if (!textures[2].loadFromFile("../Textures/asteroid2.png"))
        Error = true;

    textures[3].loadFromFile("../Textures/asteroid3.png");
    if (!textures[3].loadFromFile("../Textures/asteroid3.png"))
        Error = true;

    textures[4].loadFromFile("../Textures/laser1.png");
    if (!textures[4].loadFromFile("../Textures/laser1.png"))
        Error = true;

    textures[5].loadFromFile("../Textures/laser2.png");
    if (!textures[5].loadFromFile("../Textures/laser2.png"))
        Error = true;

    textures[6].loadFromFile("../Textures/levelup.png");
    if (!textures[6].loadFromFile("../Textures/levelup.png"))
        Error = true;

    textures[7].loadFromFile("../Textures/Game_logo.png");
    if (!textures[7].loadFromFile("../Textures/Game_logo.png"))
        Error = true;

    textures[8].loadFromFile("../Textures/Jupiter.png");
    if (!textures[8].loadFromFile("../Textures/Jupiter.png"))
        Error = true;

    textures[9].loadFromFile("../Textures/Explosion.png");
    if (!textures[9].loadFromFile("../Textures/Explosion.png"))
        Error = true;

    font.loadFromFile("../Fonts/8-bit.ttf");
    if (!font.loadFromFile("../Fonts/8-bit.ttf"))
        Error = true;


    if (Error) {
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
