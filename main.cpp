
#include <cstdlib>
#include <ctime>
#include "DrawingGame.h"


int main() {
    srand(time(nullptr));
    DrawingGame game;
    game.drawing();
    return 0;
}

