#include "engine.hpp"

Engine::Engine(const char* title, int width, int height) {
    SDL_CreateWindowAndRenderer(width, height, 0, &window, &renderer);
    SDL_SetWindowTitle(window, title);
}

Engine::~Engine() {
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
}

void Engine::Draw() {
    SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
    SDL_RenderClear(renderer);
    for (auto& renderable : sprites.renderables) {
        renderable.second->Draw();  
    }
    SDL_RenderPresent(renderer);
}

void Engine::Input() {
    while (SDL_PollEvent(&event)) {
        if (event.type == SDL_QUIT) {
            running = false;
        }
    }
}