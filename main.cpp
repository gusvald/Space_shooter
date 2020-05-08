#include <iostream>
#include <cstdlib>
#include <ctime>
#include "Drawing_game.h"


int main() {
    srand(time(nullptr));
    Drawing_game game;
    game.drawing();
    return 0;
}

