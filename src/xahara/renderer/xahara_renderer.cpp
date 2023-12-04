#pragma once
#include "./renderer_abstract.hpp"
#include "../material/material.h"
#include <typeinfo>

// Xahara physics based renderer class 
class PixelXahara : public Renderer {
    // Public attributes 
    public:
        // Constructors 
        PixelXahara(int windowWidth, int windowHeight) : Renderer(windowWidth,windowHeight){};

        PixelXahara(): Renderer(){};

        // Methods  
        void init(std::string windowName);
        
        virtual void handleEvents() override;
        virtual void update() override;
        virtual void render() override;
        virtual void clean() override;
};

// Initializes the renderer 
void PixelXahara::init(std::string windowName){

    // Create the display window 
    // check if the display adapter has been set 
    if (this->getDisplayAdapter() == nullptr){
        return exit(20);
    } 

    // Set adapter window dimensions 
    this->getDisplayAdapter()->setWindowDimensions(this->windowWidth,this->windowHeight);
    // Set pixel height 
    this->getDisplayAdapter()->setPixelHeight(this->getPixelHeight());

    // Create the window  
    this->getDisplayAdapter()->createWindow(windowName);

    // Set renderer to running  
    this->setRunning(true);
}

// Handle events 
void PixelXahara::handleEvents(){
    // Get the events
    std::vector<Event> events = this->getDisplayAdapter()->getEvents();

    // Handle 
    for (auto event: events){
        // Close window 
        if (event == CLOSE_WINDOW){
            this->setRunning(false);
        }
    }

}

// Update Method 
void PixelXahara::update(){
    this->setPixelAtPosition(MaterialFactory::createWater(),0,0);
    this->setPixelAtPosition(MaterialFactory::createWater(),1,1);

    // Get mouse position 
    std::cout << this->getDisplayAdapter()->getMouseX() << "," << this->getDisplayAdapter()->getMouseY() << std::endl;
}

// Render Method 
void PixelXahara::render(){
    // Iterate pixel map 
    for (int r=0; r != this->getPixelsAlongYAxis(); r++){
        for (int c=0; c != this->getPixelsAlongXAxis(); c++){
            Material pixel = this->getPixelAtPosition(r,c); 
            
            // Check is the pixel is water 
            if (pixel.material_id == 1 ){
                this->getDisplayAdapter()->drawPixel(
                    this->getMaterialManager()->getMaterialColor(pixel)
                    ,r,c);
            }
        }
    }

    // Render the items 
    this->getDisplayAdapter()->flush();
}

// Clean 
void PixelXahara::clean() {
    // Clean windows 
    this->getDisplayAdapter()->clean();
    // Clean pixel grid 
    std::free(this->getPixelGrid());
    
}