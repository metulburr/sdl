
#include <SDL2/SDL.h>
#include <iostream>

class Control{
    public:
        SDL_Window* window = 0;
        SDL_Renderer* renderer = 0;
        std::string title;
        int width = 0, height = 0;
        bool running = true, fullscreen;
        
        Control(std::string titlename, int window_width=0, int window_height=0, bool fullscr=false)
        : title(titlename), width(window_width), height(window_height), fullscreen(fullscr){
            if ( ! init()){
                //problem
            }
        }
        
        ~Control(){
            clean();
        }
        
        void clean(){
            SDL_DestroyWindow(window);
            SDL_DestroyRenderer(renderer);
            SDL_Quit();
        }
        
        bool init(){
            if (SDL_Init(SDL_INIT_EVERYTHING) == 0){
                int flags = 0;
                if (fullscreen){
                    flags = SDL_WINDOW_FULLSCREEN_DESKTOP;
                }
                window = SDL_CreateWindow(title.c_str(),
                    SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 
                    width, height,
                    flags);
                if (window != 0){
                    renderer = SDL_CreateRenderer(window, -1, 0);
                }
            }
            else{
                return false;
            }
            return true;
        }
        
        void events(){
            SDL_Event event;
            if (SDL_PollEvent(&event)){
                switch (event.type){
                    case SDL_QUIT:
                        running = false;
                        break;
                    case SDL_KEYDOWN:
                        running = false;
                        break;
                    default:
                        break;
                }
            }
        }
        
        void update(){
            
        }
        
        void render(){
            SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
            SDL_RenderClear(renderer);
            SDL_RenderPresent(renderer);
        }
        
        void run(){
            while (running){
                events();
                update();
                render();
                //SDL_Delay(5000);
                //running = false;
            }
        }
};

int main(){
    Control app("SDL test", 800, 600, false);
    app.run();
}
