

#include "Character.h"
#include <iostream>

void Character::init(SDL_Renderer* renderer){
    SDL_Surface* temp = IMG_Load("resources/images/waver.png");
    if (temp == NULL){
        std::cout << IMG_GetError() << std::endl;
    }
    texture = SDL_CreateTextureFromSurface(renderer, temp);
    if (texture == NULL){
        std::cout << SDL_GetError() << std::endl;
    }
    SDL_FreeSurface(temp);
    SDL_QueryTexture(texture, NULL, NULL, &source_rect.w, &source_rect.h);
    dest_rect.x = source_rect.x = 0;
    dest_rect.y = source_rect.y = 0;
    dest_rect.w = source_rect.w;
    dest_rect.h = source_rect.h;
}
