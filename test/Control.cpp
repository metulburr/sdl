
#include "Control.h"

//#include <SDL2/SDL.h>
//#include <SDL2/SDL_image.h>
#include <iostream>



Control::Control(std::string titlename, int window_width=0, int window_height=0, bool fullscr=false)
: title(titlename), width(window_width), height(window_height), fullscreen(fullscr){
    if ( ! init()){
        //problem
    }
}

Control::~Control(){
    clean();
}

void Control::clean(){
    SDL_DestroyWindow(window);
    SDL_DestroyRenderer(renderer);
    SDL_Quit();
}

bool Control::init(){
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

    //player.init(renderer, "resources/images/waver.png");

    return true;
}

void Control::events(){
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

void Control::update(){
    player.update();
}

void Control::render(){
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
    SDL_RenderClear(renderer);
    player.render(renderer);
    //SDL_RenderCopy(renderer, player.texture, &player.source_rect, &player.dest_rect);
    SDL_RenderPresent(renderer);
}

void Control::run(){
    while (running){
        events();
        update();
        render();
    }
}


