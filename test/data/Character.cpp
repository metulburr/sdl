

#include "include/Character.h"

void Character::init(SDL_Renderer* rend, std::string filepath){
    this->renderer = rend;
    texture_manager.load(filepath, "animate", renderer);
}

void Character::render(SDL_Renderer* renderer){
    //texture_manager.draw("animate", 0,0, 50, 72, renderer, SDL_FLIP_NONE);
    texture_manager.draw_frame("animate", 0,0, 50, 72, 1, current_frame, renderer, SDL_FLIP_NONE);
}

void Character::update(){
    current_frame = int(((SDL_GetTicks() / 100) % 10));
}
