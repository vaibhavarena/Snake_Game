#include "renderer.h"
#include <iostream>
#include <string>
#include <future>

Renderer::Renderer(const std::size_t &screen_width,
                   const std::size_t &screen_height,
                   const std::size_t &grid_width, const std::size_t &grid_height)
    : screen_width(screen_width),
      screen_height(screen_height),
      grid_width(grid_width),
      grid_height(grid_height) {
  // Initialize SDL
  if (SDL_Init(SDL_INIT_VIDEO) < 0) {
    std::cerr << "SDL could not initialize.\n";
    std::cerr << "SDL_Error: " << SDL_GetError() << "\n";
  }

  // Create Window
  sdl_window = SDL_CreateWindow("Snake Game", SDL_WINDOWPOS_CENTERED,
                                SDL_WINDOWPOS_CENTERED, screen_width,
                                screen_height, SDL_WINDOW_SHOWN);

  if (nullptr == sdl_window) {
    std::cerr << "Window could not be created.\n";
    std::cerr << " SDL_Error: " << SDL_GetError() << "\n";
  }

  // Create renderer
  sdl_renderer = SDL_CreateRenderer(sdl_window, -1, SDL_RENDERER_ACCELERATED);
  if (nullptr == sdl_renderer) {
    std::cerr << "Renderer could not be created.\n";
    std::cerr << "SDL_Error: " << SDL_GetError() << "\n";
  }
}

Renderer::~Renderer() {
  SDL_DestroyWindow(sdl_window);
  SDL_Quit();
}

void Renderer::renderBackground()
{
  _mutex.lock();
  // Clear screen
  SDL_SetRenderDrawColor(sdl_renderer, 0x1E, 0x1E, 0x1E, 0xFF);
  SDL_RenderClear(sdl_renderer);
  _mutex.unlock();
}

void Renderer::renderFood(SDL_Point const &food, SDL_Rect &block)
{
  _mutex.lock();
  // Render food
  SDL_SetRenderDrawColor(sdl_renderer, 0xFF, 0xCC, 0x00, 0xFF);
  block.x = food.x * block.w;
  block.y = food.y * block.h;
  SDL_RenderFillRect(sdl_renderer, &block);
  _mutex.unlock();
}

void Renderer::renderSnake(Snake snake, SDL_Rect &block)
{
  _mutex.lock();
  // Change 5 : Change snake body dimension 
  SDL_Rect snakeDim;
  snakeDim.w = block.w - 0.1;
  snakeDim.h = block.h - 0.1;

  // Render snake's body
  SDL_SetRenderDrawColor(sdl_renderer, 0xFF, 0xFF, 0xFF, 0xFF);
  for (SDL_Point const &point : snake.getBody()) {
    snakeDim.x = point.x * block.w;
    snakeDim.y = point.y * block.h;
    SDL_RenderFillRect(sdl_renderer, &snakeDim);
  }

  // Render snake's head
  block.x = static_cast<int>(snake.getHeadX()) * block.w;
  block.y = static_cast<int>(snake.getHeadY()) * block.h;
  if (snake.getAlive()) {
    SDL_SetRenderDrawColor(sdl_renderer, 0x00, 0x7A, 0xCC, 0xFF);
  } else {
    SDL_SetRenderDrawColor(sdl_renderer, 0xFF, 0x00, 0x00, 0xFF);
  }
  SDL_RenderFillRect(sdl_renderer, &block);
  _mutex.unlock();
}

void Renderer::Render(Snake snake, SDL_Point const &food) {
  SDL_Rect block;
  block.w = screen_width / grid_width;
  block.h = screen_height / grid_height;

  // Change 4 : Use concurrency to execute the below functions(Minor changes in cmake file to include pthread)
  std::future<void> backFtr = std::async(std::launch::deferred, &Renderer::renderBackground, this);
  std::future<void> foodFtr = std::async(std::launch::deferred, &Renderer::renderFood, this, std::ref(food), std::ref(block));
  std::future<void> snakeFtr = std::async(std::launch::deferred, &Renderer::renderSnake, this, snake, std::ref(block));

  backFtr.wait();
  foodFtr.wait();
  snakeFtr.wait();

  // Update Screen
  SDL_RenderPresent(sdl_renderer);
}

void Renderer::UpdateWindowTitle(int score, int fps) {
  std::string title{"Snake Score: " + std::to_string(score) + " FPS: " + std::to_string(fps)};
  SDL_SetWindowTitle(sdl_window, title.c_str());
}
