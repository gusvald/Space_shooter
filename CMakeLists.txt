cmake_minimum_required(VERSION 3.1)


project(SpaceShooter)

set(CMAKE_CXX_STANDARD 14)
add_compile_options(-Wall -Wextra)


if (UNIX)

    set(CMAKE_MODULES_PATH "/usr/share/SFML/cmake/Modules" ${CMAKE_MODULE_PATH})


endif (UNIX)

if (WIN32)

    set(SFML_STATIC_LIBRARIES TRUE)


    set(SFML_DIR "C:/app/SFML-2.5.1/lib/cmake/SFML/")
endif (WIN32)


find_package(SFML 2 COMPONENTS graphics audio REQUIRED)

add_executable(MyApp main.cpp spaceship.cpp spaceship.h enemy.cpp enemy.h laser.cpp laser.h Menu_Board.cpp Menu_Board.h Results_board.cpp Results_board.h Game_Board.cpp Game_Board.h textures_in.cpp textures_in.h Drawing_game.cpp Drawing_game.h)

target_link_libraries(MyApp sfml-graphics sfml-audio)