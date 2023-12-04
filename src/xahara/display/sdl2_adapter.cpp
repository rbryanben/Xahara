#pragma once
#include "./display_adapter_abstract.hpp"
#include <SDL2/SDL.h>
#include <stdlib.h>
#include <string>
#include <iostream>

// SDL2 Adapter 
class SDL2Adapter : public DisplayAdapter {
    
    // Private Attributes 
    private:
        SDL_Window *window ;
        SDL_Renderer *renderer;
        void getMouseState(int *x, int *y);

    // Public Attributes
    public:
        void clearWindow();
        virtual void createWindow(std::string windowName) override;
        virtual std::vector<Event> getEvents() override;
        virtual void drawPixel(Color color, int x, int y) override;
        virtual void drawLine(Color lineColor,int x1,int y1,int x2,int y2);
        virtual void flush() override;
        virtual void clean() override;
        virtual int getMouseX() override;
        virtual int getMouseY() override;
};

// Create window method 
void SDL2Adapter::createWindow(std::string windowName) {
    SDL_Init(SDL_INIT_EVERYTHING);
    this->window = SDL_CreateWindow(windowName.c_str(),SDL_WINDOWPOS_CENTERED,SDL_WINDOWPOS_CENTERED,this->getWindowWidth(),this->getWindowHeight(),0);
    this->renderer = SDL_CreateRenderer(this->window,-1,0);
    SDL_RenderPresent(this->renderer);
}

// Get user events 
std::vector<Event> SDL2Adapter::getEvents(){
    // Result vector 
    auto res = std::vector<Event>();
    // Get event
    SDL_Event event;
    SDL_PollEvent(&event);
    
    // Window close 
    if (event.type == SDL_QUIT){
        res.push_back(CLOSE_WINDOW);
    }

    // Return events
    return res;
};

// Draw pixel 
void SDL2Adapter::drawPixel(Color color,int row, int col){
    SDL_SetRenderDrawColor(this->renderer,color.red,color.green,color.blue,255);
    SDL_Rect rect = {col * this->getPixelHeight(),row * this->getPixelHeight(),this->getPixelHeight(),this->getPixelHeight()};
    SDL_RenderFillRect(renderer,&rect);
}

// Draw line 
void SDL2Adapter::drawLine(Color lineColor,int x1,int y1,int x2,int y2){
    SDL_SetRenderDrawColor(this->renderer,lineColor.red,lineColor.green,lineColor.blue,255);
    SDL_RenderDrawLine(this->renderer,x1,y1,x2,y2);
}

// Flush the window
void SDL2Adapter::flush(){
    SDL_RenderPresent(this->renderer);
}

// Get mouse state 
void SDL2Adapter::getMouseState(int *x, int *y){
    SDL_GetMouseState(x,y);
}

// Get mouseX
int SDL2Adapter::getMouseX(){
    int x , y;
    this->getMouseState(&x,&y);
    return x;
}

// Get mouseY
int SDL2Adapter::getMouseY(){
    int x , y;
    this->getMouseState(&x,&y);
    return y;
}

// Clean 
void SDL2Adapter::clean(){
    SDL_DestroyWindow(this->window);
    SDL_DestroyRenderer(this->renderer);   
}




