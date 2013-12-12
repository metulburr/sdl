

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <string>
#include "texture_manager.h"
#include <iostream>

class Character{
    public:
        SDL_Texture* texture; 
        SDL_Rect source_rect; 
        SDL_Rect dest_rect; 
        int current_frame;
        TextureManager texture_manager;
        SDL_Renderer* renderer;

        //Character();
        void init(SDL_Renderer*, std::string);
        void render(SDL_Renderer*);
        void update();
};
