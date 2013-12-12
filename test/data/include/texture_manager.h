

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <string>
#include <map>
#include <iostream>

class TextureManager{
    public:
        std::map<std::string, SDL_Texture*> map;

        bool load(std::string filename, std::string id, SDL_Renderer* renderer);
        void draw(std::string id, int x, int y, int width, int height, 
            SDL_Renderer* renderer, SDL_RendererFlip flip);
        void draw_frame(std::string id, int x, int y, int width, int height, 
            int current_row, int current_frame, SDL_Renderer* renderer, SDL_RendererFlip flip);
};
