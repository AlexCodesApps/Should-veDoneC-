#pragma once
#include <array>
#include "renderable.hpp"
#include "enginedata.hpp"

struct SDL_Texture;

class RenderableCollection;

class Engine {
    SDL_Color BackgroundColor = {0, 0, 0, 255};
    std::array<SDL_Texture*, TEXTURE_COUNT> loaded_textures;
    void LoadTextures();
    SDL_Event event;
    public:
    ~Engine();
    RenderableCollection sprites;
    SDL_Window* window;
    SDL_Renderer* renderer;
    bool running = true;
    SDL_Texture* GetTexture(Texture_Enum texture);
    Engine(const char* title = "Engine", int width = 680, int height = 480);
    void Draw();
    void Input();
};