#pragma once
#include "engine.hpp"
#include "enginedata.hpp"

class RenderTexture : public Renderable {
    protected:
    SDL_Texture* texture = nullptr;
    public:
    SDL_Rect SourceRect = {0, 0, 0, 0};
    RenderTexture(Engine&, Texture_Enum = BLANK);
    void Draw() override;
    void SetTexture(Texture_Enum);
};