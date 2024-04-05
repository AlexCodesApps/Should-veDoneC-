#include "engine.hpp"
#include "collections.hpp"
#define New_Renderable(T, C) std::make_shared<RenderablePointer<T>>(C)

class Foo : public Renderable {
    void Draw() override {
        std::cout << "Foo" << std::endl;
    }
};

int main() {
    SDL_Init(SDL_INIT_EVERYTHING);
    Engine engine;
    std::shared_ptr<RenderableCollection> collection = std::make_shared<RenderableCollection>();
    collection->NewRenderable(std::make_shared<Foo>());
    std::shared_ptr<RenderablePointer<Foo>> foo = New_Renderable(Foo, collection);
    std::cout<<"ID: " << foo->GetID() << std::endl;
    while (engine.running) {
        engine.Input();
        engine.Draw();
    }
    return 0;
}
