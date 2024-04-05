#include "engine.hpp"

Engine::Engine(const char* title, int width, int height) {
    SDL_CreateWindowAndRenderer(width, height, 0, &window, &renderer);
    SDL_SetWindowTitle(window, title);
    LoadTextures();
}

Engine::~Engine() {
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    for (auto& texture : loaded_textures) {
        SDL_DestroyTexture(texture);
    }
}

void Engine::Draw() {
    SDL_SetRenderDrawColor(renderer, BackgroundColor.r, BackgroundColor.g, BackgroundColor.b, BackgroundColor.a);
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

void Engine::LoadTextures() {
    for (int i = 0; i < TEXTURE_COUNT+1; i++) {
        loaded_textures[i] = IMG_LoadTexture(renderer, (ASSETS_PATH + TEXTURES.at(Texture_Enum(i))).c_str());
        if (loaded_textures[i] == nullptr) {
            std::cout << "Error loading texture: " << TEXTURES.at(Texture_Enum(i)) << ENDL;
        }
    }
}

SDL_Texture* Engine::GetTexture(Texture_Enum texture) {
    return loaded_textures[texture];
}