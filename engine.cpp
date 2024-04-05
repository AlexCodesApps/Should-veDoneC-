#include "engine.hpp"
#include "collections.hpp"

Engine::Engine(const char* title, int width, int height) {
    SDL_CreateWindowAndRenderer(width, height, 0, &window, &renderer);
    SDL_SetWindowTitle(window, title);
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

Renderable::Renderable() {
    GenerateID();
}

void Renderable::GenerateID() {
    static Uint64 indexer = 0;
    id = "Sprite." + std::to_string(indexer++);
}

std::string Renderable::GetID() const {
    return id;
}