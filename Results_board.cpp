//
// Created by Gus on 05.05.2020.
//
#include "Results_board.h"
#include <iostream>

Results_board::Results_board() {
    LoadResults();
}

void Results_board::DrawResults(sf::RenderWindow &win) {
    for (int i = 0; i < 10; i++) {
        win.draw(Results[i]);
    }
    win.draw(space.BackMenuInfo);
}

void Results_board::LoadResults() {
    spaceship player(&space.shipTex);

    player.file.open("../Notes/Score.txt", std::ios::in);
    if (player.file.good()) {

        std::string line;

        for (int i = 0; i < 10; i++) {
            getline(player.file, line);
            score_int[i] = atoi(line.c_str());
        }
    }
    player.file.close();

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
