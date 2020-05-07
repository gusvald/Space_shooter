#include <iostream>
#include <cstdlib>
#include <ctime>
#include "Play_game.h"
#include "Menu_Board.h"


int main() {
    srand(time(nullptr));
    Menu_Board menu;
    menu.DrawMenu();

    return 0;
}

