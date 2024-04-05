#pragma once
#include <memory>
#include "engine.hpp"

class RenderableCollection {
    friend class Renderable;
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