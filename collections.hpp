#pragma once
#include <memory>
#include "engine.hpp"

template <typename T>
class RenderablePointer {
    RenderableCollection *collection;
    std::string identifier;
    public:
    RenderablePointer(RenderableCollection *collection);
    RenderablePointer(std::string id, RenderableCollection *collection);
    std::shared_ptr<T> Get();
    std::string GetID();
};

template <typename T>
RenderablePointer<T>::RenderablePointer(RenderableCollection *collection_p) {
    this->collection = collection_p;
    std::shared_ptr<T> temp = std::make_shared<T>();
    this->identifier = temp->GetID();
    this->collection->AddRenderable(temp);
}

template <typename T>
RenderablePointer<T>::RenderablePointer(std::string id, RenderableCollection *collection_p) {
    this->identifier = id;
    this->collection = collection_p;
}

template <typename T>
std::shared_ptr<T> RenderablePointer<T>::Get() {
    return dynamic_cast<T*>(collection->Get(identifier));
}
    template <typename T>
std::string RenderablePointer<T>::GetID() {
    return identifier;
}