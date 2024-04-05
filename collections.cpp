#include "collections.hpp"

std::shared_ptr<Renderable> RenderableCollection::Get(std::string id) {
    return renderables.at(id);
}

void RenderableCollection::NewRenderable(std::shared_ptr<Renderable> renderable) {
    renderables[renderable->GetID()] = renderable;
}

void RenderableCollection::RemoveRenderable(std::string id) {
    renderables.erase(id);
}