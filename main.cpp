#include "engine.hpp"
#include "collections.hpp"
#define New_Renderable(T) std::make_shared<T>()
#define New_Renderable_Pointer(T, C) RenderablePointer<T>(C)

class Foo : public Renderable {
    void Draw() override {
        std::cout << "Foo" << std::endl;
    }
};

int main() {
    SDL_Init(SDL_INIT_EVERYTHING);
    Engine engine;
    engine.sprites.AddRenderable(New_Renderable(Foo));
    while (engine.running) {
        engine.Input();
        engine.Draw();
    }
    SDL_Quit();
    return 0;
}