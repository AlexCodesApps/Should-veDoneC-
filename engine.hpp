#pragma once
#include "renderable.hpp"

class RenderableCollection;

class Engine {
    SDL_Event event;
    public:
    ~Engine();
    RenderableCollection sprites;
    SDL_Window* window;
    SDL_Renderer* renderer;
    bool running = true;

    Engine(const char* title = "Engine", int width = 680, int height = 480);
    void Draw();
    void Input();
};