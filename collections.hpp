#pragma once
#include <memory>
#include <concepts>
#include "engine.hpp"
#define New_Renderable(T, ...) std::make_shared<T>(__VA_ARGS__)
#define New_Renderable_Pointer(T, C) RenderablePointer<T>(C)

template <typename T>
requires std::derived_from<T, Renderable>
class RenderablePointer {
    RenderableCollection *collection;
    std::string identifier;
    public:
    RenderablePointer(RenderableCollection &collection_p);
    RenderablePointer(std::string id, RenderableCollection &collection_p);
    template <typename... Args>
    RenderablePointer(RenderableCollection &collection_p, Args &&... args) { // Couldn't Do Outside Class
        collection = &collection_p;
        std::shared_ptr<T> temp = std::make_shared<T>(std::forward<Args>(args)...);
        identifier = temp->GetID();
        collection->AddRenderable(temp);
    }
    T* operator->();
    std::shared_ptr<T> Get();
    std::string GetID();
};

template <typename T>
requires std::derived_from<T, Renderable>
RenderablePointer<T>::RenderablePointer(RenderableCollection &collection_p) {
    this->collection = &collection_p;
    std::shared_ptr<T> temp = std::make_shared<T>();
    this->identifier = temp->GetID();
    this->collection->AddRenderable(temp);
}

template <typename T>
requires std::derived_from<T, Renderable>
RenderablePointer<T>::RenderablePointer(std::string id, RenderableCollection &collection_p) {
    this->identifier = id;
    this->collection = &collection_p;
}

template <typename T>
requires std::derived_from<T, Renderable>
std::shared_ptr<T> RenderablePointer<T>::Get() {
    return dynamic_cast<T*>(collection->Get(identifier));
}
template <typename T>
requires std::derived_from<T, Renderable>
std::string RenderablePointer<T>::GetID() {
    return identifier;
}

template <typename T>
requires std::derived_from<T, Renderable>
T* RenderablePointer<T>::operator->() {
    return dynamic_cast<T*>(collection->Get(identifier).get());
}