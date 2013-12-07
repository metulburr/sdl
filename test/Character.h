

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

class Character{
    public:
        SDL_Texture* texture; 
        SDL_Rect source_rect; 
        SDL_Rect dest_rect; 
        
        void init(SDL_Renderer*);
};
