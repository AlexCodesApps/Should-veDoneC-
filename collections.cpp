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

template <typename T>
RenderablePointer<T>::RenderablePointer(std::shared_ptr<RenderableCollection> collection) {
    this->collection = collection;
    std::shared_ptr<T> temp = std::make_shared<T>();
    this->identifier = temp->GetID();
    this->collection->NewRenderable(temp);
}

template <typename T>
RenderablePointer<T>::RenderablePointer(std::string id, std::shared_ptr<RenderableCollection> collection) {
    this->identifier = id;
    this->collection = collection;
}

template <typename T>
std::shared_ptr<T> RenderablePointer<T>::Get() {
    return dynamic_cast<T*>(collection->Get(identifier));
}

template <typename T>
std::string RenderablePointer<T>::GetID() {
    return identifier;
}