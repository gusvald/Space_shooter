//
// Created by Gus on 05.05.2020.
//

#include "spaceship.h"


spaceship::spaceship(sf::Texture *texture) {
    this->HP_max = 20;
    this->HP = HP_max;
    this->score = 0;
    this->GameOver = false;
    this->texture = texture;
    this->shape.setTexture(*texture);
    this->shape.setPosition(440, 650);
}

void spaceship::decrease_HP() {
    this->HP--;
    if (this->HP == 0)
        GameOver = true;

}

bool spaceship::isGameOver() {
    return this->GameOver;
}

void spaceship::add_score() {
    this->score = this->score + 100;
}

void spaceship::add_score1() {
    this->score = this->score + 10;
}

void spaceship::add_score2() {
    this->score = this->score + 500;
}

int spaceship::get_Score() {
    return this->score;
}

int spaceship::get_HP() {
    return this->HP;
}

void spaceship::Safe_Score() {
    ScoreBoard[10] = get_Score();

    file.open("../Notes/Score.txt", std::ios::in);
    if (file.good()) {
        for (int i = 0; i < 10; i++) {
            getline(file, line);
            ScoreBoard[i] = atoi(line.c_str());
        }
    }
    file.close();

    for (unsigned int i = 0; i < 11; i++) {
        for (unsigned int g = 1; g < 11 - i; g++) {
            if (ScoreBoard[g - 1] < ScoreBoard[g])
                std::swap(ScoreBoard[g - 1], ScoreBoard[g]);
        }
    }

    file.open("../Notes/Score.txt", std::ios::out);
    for (unsigned int i = 0; i < 10; i++) {
        file << ScoreBoard[i] << std::endl;
    }
    file.close();
}

void spaceship::resetHP() {
    this->HP = this->HP_max;
}

void spaceship::resetSCORE() {
    this->score = 0;
}

void spaceship::resetGameOver() {
    GameOver = false;
}

void spaceship::resetLasers() {
    lasers.clear();
}








