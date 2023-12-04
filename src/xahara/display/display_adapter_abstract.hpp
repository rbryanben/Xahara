#pragma once
#include "../utils/utils.h"
#include <string>
#include <stdlib.h>
#include <vector>

// Display adapter abstract class 
class DisplayAdapter{
    private:
        int windowWidth, windowHeight;
        int pixelHeight;

    // Public attributes 
    public:

        // Methods 
        virtual void createWindow(std::string windowName="Blank Window"){};
        virtual std::vector<Event> getEvents(){ return std::vector<Event>();};
        virtual void clean(){};
        virtual void drawPixel(Color color,int row, int col){};    
        virtual void drawLine(Color lineColor,int x1,int y1,int x2,int y2){};
        virtual void flush(){};
        virtual int getMouseX(){ return -1;};
        virtual int getMouseY(){ return -1;};
        void setWindowDimensions(int windowWidth,int windowHeight);
        void clearWindow();
        void updateWindow();
        void destroyWindow();

        int getWindowWidth(){
            return this->windowWidth;
        }

        int getWindowHeight(){
            return this->windowHeight;
        }

        int getPixelHeight(){
            return this->pixelHeight;
        }

        void setPixelHeight(int height){
            this->pixelHeight = height;
        }
};

// Set window dimensions
void DisplayAdapter::setWindowDimensions(int windowWidth,int windowHeight){
    this->windowWidth = windowWidth;
    this->windowHeight = windowHeight;
}

