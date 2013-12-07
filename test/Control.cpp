
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
    //Img_Load IMG_Load
    SDL_Surface* temp = IMG_Load("resources/images/waver.png");
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
    
}

void Control::render(){
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
    SDL_RenderClear(renderer);
    SDL_RenderCopy(renderer, texture, &source_rect, &dest_rect);
    SDL_RenderPresent(renderer);
}

void Control::run(){
    while (running){
        events();
        update();
        render();
    }
}


