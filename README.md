# CPPND: Capstone Snake Game Example

The final project for Udacity CPP Nanodegree. The starter repo has been provided with a working game and further additions have been made to show understanding of various C++ concepts.

## Changes
1. <b>Change 1:</b>  In main.cpp, the user has been given the choice to enter the grid size which in turn will automatically modify the width and height of the display window.

2. <b>Change 2:</b>  The default code has some member variables of class Snake as public members, the variables have been changed to private except Direction(to reduce unnecessary complexity) and getters and setters have been implemented accordingly.

3. <b>Change 3:</b>  In renderer.h and renderer.cpp, functions for rendering background, food and snake has been divided into seperate functions to enhance code readability.

4. <b>Change 4:</b>  Use concurrency to execute the below functions(Minor changes in cmake file to include pthread). Although not required in such a small project, the idea has been taken from very large games, where there is priority based loading, the objects close to camera and the player character are loaded first and then the far away objects and textures.

5. <b>Change 5:</b>  In renderer.cpp, the dimensions of snake body has been modified to modify visual appearance in gameplay.

6. <b>Change 6:</b>  A count variable has been declared in snake.h and used in game.cpp to increase speed after 5 food pick ups.

## Minor changes
1.  CMakeLists.txt has been modified to compile code with pthread.
2.  In renderer.h and renderer.cpp, the constructor arguments have been changed to references to prevent making object copies for function.

## Dependencies for Running Locally
* cmake >= 3.7
  * All OSes: [click here for installation instructions](https://cmake.org/install/)
* make >= 4.1 (Linux, Mac), 3.81 (Windows)
  * Linux: make is installed by default on most Linux distros
  * Mac: [install Xcode command line tools to get make](https://developer.apple.com/xcode/features/)
  * Windows: [Click here for installation instructions](http://gnuwin32.sourceforge.net/packages/make.htm)
* SDL2 >= 2.0
  * All installation instructions can be found [here](https://wiki.libsdl.org/Installation)
  * Note that for Linux, an `apt` or `apt-get` installation is preferred to building from source.
* gcc/g++ >= 5.4
  * Linux: gcc / g++ is installed by default on most Linux distros
  * Mac: same deal as make - [install Xcode command line tools](https://developer.apple.com/xcode/features/)
  * Windows: recommend using [MinGW](http://www.mingw.org/)

## Basic Build Instructions

1. Clone this repo.
2. Make a build directory in the top level directory: `mkdir build && cd build`
3. Compile: `cmake .. && make`
4. Run it: `./SnakeGame`.