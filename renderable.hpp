#pragma once
#include <SDL2/SDL.h>
#include <iostream>
#include <memory>
#include <string>
#include <unordered_map>

class Renderable {
    friend class Engine;
    protected:
    void GenerateID();
    std::string id;
    virtual void Draw() = 0;
    public:
    Renderable();
    virtual ~Renderable() = default;
    SDL_FRect body;
    std::string GetID() const;
};

class Engine;

class RenderableCollection {
    friend class Renderable;
    friend class Engine;
    protected:
        std::unordered_map<std::string, std::shared_ptr<Renderable>> renderables;
    public:
        std::shared_ptr<Renderable> Get(std::string id);
        template <typename T>
        requires std::derived_from<T, Renderable>
        std::shared_ptr<T> AddRenderable(std::shared_ptr<T> renderable);
        void RemoveRenderable(std::string id);
};

template <typename T>
requires std::derived_from<T, Renderable>
std::shared_ptr<T> RenderableCollection::AddRenderable(std::shared_ptr<T> renderable) {
    renderables[renderable->GetID()] = renderable;
    return std::dynamic_pointer_cast<T>(renderable);
}