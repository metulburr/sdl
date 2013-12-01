
#include <iostream>
#include "SDL/SDL.h"



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
        
        bool resize(int width, int height){
            this->width = width;
            this->height = height;
            if ((_window = SDL_SetVideoMode(width, height, bpp, flags)) == NULL){
                return false;
            }
            return true;
        }
};

class Input{
    public:
        Input(){
            
        }
        
        void on_event(SDL_Event* event){
            switch(event->type){
                case SDL_KEYDOWN:
                    key_press(event->key.keysym.sym, 
                        event->key.keysym.mod, 
                        event->key.keysym.unicode);
                    break;
                case SDL_KEYUP:
                    key_release(event->key.keysym.sym, 
                        event->key.keysym.mod, 
                        event->key.keysym.unicode);
                    break;
                case SDL_MOUSEMOTION:
                    mouse_motion(event->motion.x, event->motion.y,
                        event->motion.xrel, event->motion.yrel,
                        (event->motion.state & SDL_BUTTON(SDL_BUTTON_LEFT)) != 0,
                        (event->motion.state & SDL_BUTTON(SDL_BUTTON_MIDDLE)) != 0,
                        (event->motion.state & SDL_BUTTON(SDL_BUTTON_RIGHT)) != 0);
                    break;
                case SDL_MOUSEBUTTONDOWN:
                    mouse_press(event->button.button, event->button.x, event->button.y);
                    break;
                case SDL_MOUSEBUTTONUP:
                    mouse_release(event->button.button, event->button.x, event->button.y);
                    break;
                case SDL_ACTIVEEVENT:
                    focus_change(event->active.state, event->active.gain);
                    break;
                case SDL_VIDEORESIZE:
                    resize(event->resize.w, event->resize.h);
                    break;
                case SDL_QUIT:
                    exiting();
                    break;
            }
        }
        
        virtual void key_press(SDLKey key, SDLMod mod, Uint16 unicode){}
        virtual void key_release(SDLKey key, SDLMod mod, Uint16 unicode){}
        virtual void mouse_motion(int x, int y, int relx, int rely, bool left,  bool middle, bool right){}
        virtual void mouse_press(Uint8 button, int x, int y){}
        virtual void mouse_release(Uint8 button, int x, int y){}
        virtual void focus_change(Uint8 state, Uint8 gain){}
        virtual void resize(int width, int height){}
        virtual void exiting(){}

};



class Application : public Input{
    public:
        bool done;
        Window window;
    
        Application(){
            done = false;
        }
        virtual ~Application(){
            
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
            SDL_Event event;
            while( ! done){
                input(&event);
                update();
                render();
            }
        }
        void input(SDL_Event* event){
            while(SDL_PollEvent(event)){
                on_event(event);
            }
        }
        void update(){
            SDL_Delay(50);
        }
        void render(){
            
        }
        void quit(){
            SDL_Quit();
        }
        
        void resize(int width, int height){
            if ( ! window.resize(width, height)){
                exiting();
            }
        }
        void exiting(){
            done = true;
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
