//
// Created by Gus on 05.05.2020.
//
#include "ResultsBoard.h"


ResultsBoard::ResultsBoard() {
    LoadResults();
}

void ResultsBoard::DrawResults(sf::RenderWindow &win) {
    for (int i = 0; i < 10; i++) {
        win.draw(Results[i]);
    }
    win.draw(space.BackMenuInfo);
}

void ResultsBoard::LoadResults() {


    file.open("../Notes/Score.txt", std::ios::in);
    if (file.good()) {

        std::string line;

        for (int i = 0; i < 10; i++) {
            getline(file, line);
            score_int[i] = atoi(line.c_str());
        }
    }
    file.close();

    for (int i = 0; i < 10; i++) {
        score_string[i] = std::to_string(score_int[i]);
    }

    for (int i = 0; i < 10; i++) {
        Results[i].setFont(space.font);
        Results[i].setCharacterSize(100);
        Results[i].setPosition(280, i * 70);
        Results[i].setString(score_string[i]);
    }
}

void ResultsBoard::saveScore(int score) {
    ScoreBoard[10] = score;

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


