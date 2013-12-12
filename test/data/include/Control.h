

#include "Character.h"
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <iostream>


class Control{
    public:
        SDL_Window* window = 0;
        SDL_Renderer* renderer = 0;
        std::string title;
        int width = 0, height = 0;
        bool running = true, fullscreen;
        Character player;
        
        
        Control(std::string titlename, int window_width, int window_height, bool fullscr);
        ~Control();
        void clean();
        bool init();
        void events();
        void update();
        void render();
        void run();
};


