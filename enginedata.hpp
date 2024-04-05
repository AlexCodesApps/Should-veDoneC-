#pragma once
#include <map>
#include <string>
#include <SDL2/SDL_image.h>
#define ASSETS_PATH ""
#define ENDL "\n"

enum Texture_Enum {
    WHITE,
    BLANK,
};

static const std::map<const Texture_Enum, const std::string> TEXTURES = {
    {WHITE, "white.png"},
    {BLANK, "blank.png"},
};

constexpr int TEXTURE_COUNT = Texture_Enum::BLANK; // Blank is always the last