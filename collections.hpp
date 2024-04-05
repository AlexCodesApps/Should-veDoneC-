#pragma once
#include <memory>
#include "engine.hpp"

class RenderableCollection {
    friend class Renderable;
    friend class Engine;
    protected:
        std::unordered_map<std::string, std::shared_ptr<Renderable>> renderables;
    public:
        std::shared_ptr<Renderable> Get(std::string id);
        void NewRenderable(std::shared_ptr<Renderable> renderable);
        void RemoveRenderable(std::string id);
};

template <typename T>
class RenderablePointer {
    std::shared_ptr<RenderableCollection> collection;
    std::string identifier;
    public:
    RenderablePointer(std::shared_ptr<RenderableCollection>);
    RenderablePointer(std::string, std::shared_ptr<RenderableCollection>);
    std::shared_ptr<T> Get();
    std::string GetID();
};

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