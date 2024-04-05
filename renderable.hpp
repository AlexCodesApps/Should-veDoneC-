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
        void AddRenderable(std::shared_ptr<Renderable> renderable);
        void RemoveRenderable(std::string id);
};