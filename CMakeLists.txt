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

add_executable(MyApp main.cpp Spaceship.cpp Spaceship.h Enemy.cpp Enemy.h Laser.cpp Laser.h MenuBoard.cpp MenuBoard.h ResultsBoard.cpp ResultsBoard.h GameBoard.cpp GameBoard.h TexturesIn.cpp TexturesIn.h DrawingGame.cpp DrawingGame.h)

target_link_libraries(MyApp sfml-graphics sfml-audio)