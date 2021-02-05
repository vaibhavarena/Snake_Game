# CPPND: Capstone Snake Game Example

The final project for Udacity CPP Nanodegree. The starter repo has been provided with a working game and further additions have been made to show understanding of various C++ concepts.


## Rubric criteria fulfilled
Many functionalities as specified in rubric has already been implemented in starter code. So, only the changes fulfilling the rubric criteria have been discussed below.
### Loop, functions & I/O
1. <b>Input</b> In main.cpp, line 14, the user has to input the grid size which in turn make display area smaller or larger.
2. <b>Condition</b>In game.cpp, line 85, and if loop is used which enforces the increase in speed after five turns only.
3. <b>Function</b>In renderer.cpp, line 96-98, three sepearte functions for rendering different objects have been defined to reduce complexity.
### Object Oriented Programming
1. <b>Access Specifier</b> In snake.h, from line 36-41, the members were public, has now been made private.
2. <b>Encapsulation</b> In snake.h, from line 26-31, getters and setters have been declared and defined in snake.cpp to access and set state of private member variables of snake class.
### Memory Management
1. <b>Pass by reference</b> 
  *In renderer.h, line 13, the constructor takes arguments as references.
  *In renderer.h, line 19, function renderFood() arguments as references.
### Concurrency
1. <b>Multi threading</b> In renderer.cpp, line 96-98, three async tasks have been defined.
2. <b>Future</b> In renderer.cpp, line 96-98, future has been used to implement wait mechanism
3. <b>Mutex and lock</b>In renderer.cpp, line 53, 64, mutex.lock() has been, without which concurrent access to block variable was creating bugs.

## Minor changes
1.  CMakeLists.txt has been modified to compile code with pthread.

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