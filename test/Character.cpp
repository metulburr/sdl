

#include "Character.h"
#include <iostream>

Character::Character(){
    
}

void Character::init(SDL_Renderer* renderer, std::string path){
    
    SDL_Surface* temp = IMG_Load(path.c_str());
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

void Character::render(SDL_Renderer* renderer){
    texture_manager.load("resources/images/waver.png", "animate", renderer);
    
    //SDL_RenderClear(renderer);
    
    texture_manager.draw("animate", 0,0, 50, 72, renderer, SDL_FLIP_NONE);
    texture_manager.draw_frame("animate", 100,100, 50, 72, 1, current_frame, renderer, SDL_FLIP_NONE);
    //SDL_renderPrsesnt(renderer);
}

void Character::update(){
    current_frame = int(((SDL_GetTicks() / 100) % 10));
}
