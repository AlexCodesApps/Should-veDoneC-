#include "rendertexture.hpp"

RenderTexture::RenderTexture(Engine& engine_p, Texture_Enum texture_p) : Renderable(engine_p) {
    SetTexture(texture_p);
}

void RenderTexture::Draw() {
    SDL_RenderCopyF(engine->renderer, texture, &SourceRect, &DisplayRect);
}

void RenderTexture::SetTexture(Texture_Enum texture_p) {
    texture = engine->GetTexture(texture_p);
    SDL_QueryTexture(texture, NULL, NULL, &SourceRect.w, &SourceRect.h);
}