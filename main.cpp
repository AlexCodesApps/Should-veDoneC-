#include "collections.hpp"
#include "rendertexture.hpp"

int main() {
    SDL_Init(SDL_INIT_EVERYTHING);
    Engine engine;
    std::shared_ptr<RenderTexture> temp = std::make_shared<RenderTexture>(engine, WHITE);
    engine.sprites.AddRenderable(temp);
    temp->DisplayRect = {0, 0, 100, 100};
    while (engine.running) {
        engine.Input();
        engine.Draw();
    }
    SDL_Quit();
    return 0;
}