#pragma once
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <iostream>
#include <memory>
#include <string>
#include <unordered_map>

class RenderableCollection;

class Engine {
    SDL_Event event;
    public:
    RenderableCollection sprites;
    SDL_Window* window;
    SDL_Renderer* renderer;
    bool running = true;

    Engine(const char* title = "Engine", int width = 680, int height = 480);
    void Draw();
    void Input();
};

class Renderable {
    friend class Engine;
    protected:
    void GenerateID();
    std::string id;
    virtual void Draw() = 0;
    public:
    Renderable();
    virtual ~Renderable() = default;
    SDL_FRect body;
    std::string GetID() const;
};