#include <iostream>
#include "controller.h"
#include "game.h"
#include "renderer.h"

int main() {
  constexpr std::size_t kFramesPerSecond{60};
  constexpr std::size_t kMsPerFrame{1000 / kFramesPerSecond};

  std::size_t grid_size;

  // ***Change 1*** : Let user choose the grid size
  std::cout<<"Enter the grid size(24-40) : ";
  std::cin >> grid_size;

  // Checks to contain grid size between 24 and 40, will be automatically set between 24 and 40 for unexpected inputs
  if(grid_size < 24) {grid_size = 24;}
  else if (grid_size > 40) {grid_size = 40;}

  // Removed constexpr for initialization of below variables for dynamic setting of size
  std::size_t kGridWidth{grid_size};
  std::size_t kGridHeight{grid_size};

  std::size_t kScreenWidth{grid_size*20};
  std::size_t kScreenHeight{grid_size*20};
  // ***Change 1 ends***

  Renderer renderer(kScreenWidth, kScreenHeight, kGridWidth, kGridHeight);
  Controller controller;
  Game game(kGridWidth, kGridHeight);
  game.Run(controller, renderer, kMsPerFrame);
  std::cout << "Game has terminated successfully!\n";
  std::cout << "Score: " << game.GetScore() << "\n";
  std::cout << "Size: " << game.GetSize() << "\n";
  return 0;
}