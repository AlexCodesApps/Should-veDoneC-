#include "engine.hpp"
#include "collections.hpp"
#define New_Renderable(T, C) RenderablePointer<T>(C)

class Foo : public Renderable {
    void Draw() override {
        std::cout << "Foo" << std::endl;
    }
};

int main() {
    SDL_Init(SDL_INIT_EVERYTHING);
    Engine engine;
    engine.sprites.NewRenderable(std::make_shared<Foo>());
    while (engine.running) {
        engine.Input();
        engine.Draw();
    }
    return 0;
}