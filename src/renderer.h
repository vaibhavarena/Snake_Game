#ifndef RENDERER_H
#define RENDERER_H

#include <vector>
#include "SDL.h"
#include "snake.h"

class Renderer {
 public:

  // Change 2 : Change the arguments to reference type to prevent making extra copies of variables(Also changed declarations in .cpp file)
  Renderer(const std::size_t &screen_width, const std::size_t &screen_height,
           const std::size_t &grid_width, const std::size_t &grid_height);
  ~Renderer();

  // Change 3 : Make seperate functions for rendering background, food and snake for more readability
  void renderBackground();
  void renderFood(SDL_Point const &food, SDL_Rect &block);
  void renderSnake(Snake snake, SDL_Rect &block);

  void Render(Snake snake, SDL_Point const &food);
  void UpdateWindowTitle(int score, int fps);

 private:
  SDL_Window *sdl_window;
  SDL_Renderer *sdl_renderer;

  const std::size_t screen_width;
  const std::size_t screen_height;
  const std::size_t grid_width;
  const std::size_t grid_height;
};

#endif