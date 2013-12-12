

#include "include/texture_manager.h"

void TextureManager::draw(std::string id, int x, int y, int width, int height, 
SDL_Renderer* renderer, SDL_RendererFlip flip=SDL_FLIP_NONE){
    SDL_Rect src_rect;
    SDL_Rect dest_rect;
    
    src_rect.x = 0;
    src_rect.y = 0;
    src_rect.w = dest_rect.w = width;
    src_rect.h = dest_rect.h = height;
    dest_rect.x = x;
    dest_rect.y = y;
    
    SDL_RenderCopyEx(renderer, map[id], &src_rect, &dest_rect, 0, 0, flip);
}

void TextureManager::draw_frame(std::string id, int x, int y, int width, int height, 
int current_row, int current_frame, SDL_Renderer* renderer, SDL_RendererFlip flip=SDL_FLIP_NONE){
    SDL_Rect src_rect;
    SDL_Rect dest_rect;
    
    src_rect.x = width * current_frame;
    src_rect.y = height * (current_row -1);
    src_rect.w = dest_rect.w = width;
    src_rect.h = dest_rect.h = height;
    dest_rect.x = x;
    dest_rect.y = y;
    
    SDL_RenderCopyEx(renderer, map[id], &src_rect, &dest_rect, 0, 0, flip);
}

bool TextureManager::load(std::string filename, std::string id, SDL_Renderer* renderer){
    SDL_Surface* surface = IMG_Load(filename.c_str());
    if (surface == 0){
        std::cout << IMG_GetError() << std::endl;
        return false;
    }
    SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer, surface);
    SDL_FreeSurface(surface);
    if (texture == 0){
        std::cout << SDL_GetError() << std::endl;
        return false;
    }
    map[id] = texture;
    return true;
}
