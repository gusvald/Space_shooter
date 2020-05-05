#include <iostream>
#include <cstdlib>
#include <ctime>
#include "Play_game.h"


int main() {
    srand(time(nullptr));
    Play_game game;
    game.playing();
    return 0;
}
