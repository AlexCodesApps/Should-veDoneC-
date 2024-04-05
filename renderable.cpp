#include "renderable.hpp"

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

std::shared_ptr<Renderable> RenderableCollection::Get(std::string id) {
    return renderables.at(id);
}

void RenderableCollection::RemoveRenderable(std::string id) {
    renderables.erase(id);
}