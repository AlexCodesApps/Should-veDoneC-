#include "engine.hpp"
#include "collections.hpp"

class Foo : public Renderable {
    int _bar;
    void Draw() override {
        // std::cout << "Foo" << std::endl;
    }
    public:
    Foo() : _bar(0) {}
    Foo(int bar) : _bar(bar) {
        std::cout << "Bar is " << _bar << std::endl;
    }
};

int main() {
    SDL_Init(SDL_INIT_EVERYTHING);
    Engine engine;
    std::cout << engine.sprites.AddRenderable(New_Renderable(Foo, 10))->GetID() << std::endl;
    RenderablePointer<Foo> foo(engine.sprites, 20);
    std::cout << "test: " << foo->GetID() << std::endl;
    while (engine.running) {
        engine.Input();
        engine.Draw();
    }
    SDL_Quit();
    return 0;
}