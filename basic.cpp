#include <iostream>
#include "SDL/SDL.h"

// -lSDL

class Window{
    public:
        int width, height, bpp;
        Uint32 flags;
        SDL_Surface* _window;
        std::string title;
    
        Window(){
            width = 0;
            height = 0;
            bpp = 0;
            _window = NULL;
            title = " ";
        }
        
        void set_title(std::string title){
            this->title = title;
            SDL_WM_SetCaption(title.c_str(), NULL);
        }
        
        bool init(int width, int height, int bpp, Uint32 flags){
            this->width = width;
            this->height = height;
            this->bpp = bpp;
            this->flags = flags;
            if ((_window = SDL_SetVideoMode(width, height, bpp, flags)) == NULL){
                return false;
            }
            return true;
            
        }
};


class Application{
    public:
        bool done;
        Window window;
    
        Application(){
            done = false;
        }
        ~Application(){
            
        }
    
        bool init(){
            if (SDL_Init(SDL_INIT_EVERYTHING) != 0){
                return false;
            }
            if (window.init(800,600, 32, SDL_SWSURFACE) != true){
                return false;
            }
            window.set_title("SDL window");
            
            return true;
        }
        void run(){
            while( ! done){
                SDL_Delay(5000);
                done = true;
            }
        }
        void input(SDL_Event* event){
            
        }
        void update(){
            
        }
        void render(){
            
        }
        void quit(){
            SDL_Quit();
        }
};


int main(){
    Application* app;
    app = new Application();
    if ( ! app->init())
        return -1;
    app->run();
    app->quit();
    delete app;
    app = NULL;
    
}
