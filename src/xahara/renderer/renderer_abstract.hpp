#pragma once
#include "../display/display.h"
#include "../material/material.h"

// Abstract renderer class 
class Renderer{
    // Private attributes 
    private:
        // Pixel information 
        int pixelHeight, pixelsAlongXAxis, pixelsAlongYAxis;

        // Mouse position 
        int mousePosX, mousePosY;

        // Display adapter 
        DisplayAdapter* displayAdapter;

        // Pixel grid 
        Material* pixelGrid;

        // Material Handler 
        MaterialManager materialManager;
    
        bool isRunning; 

    // Public attributes 
    public:

        // Window dimensions 
        int windowWidth, windowHeight; 

        // Constructors 
        Renderer(int windowWidth,int windowHeight,int pixelHeight=10){
            this->windowWidth = windowWidth;
            this->windowHeight = windowHeight;
            this->pixelHeight= pixelHeight;
            this->setUp();
        }

        Renderer(){
            this->windowWidth = 640;
            this->windowHeight = 427;
            this->pixelHeight = 10;
            this->setUp();
        }

        // Setup
        void setUp();

        // Initializes the renderer 
        void init(std::string windowName);

        // Set the display adapter  
        void setDiplayAdapter(DisplayAdapter *adapter);
        
        // Get pixel grid
        Material* getPixelGrid(){
            return this->pixelGrid;
        }

        // Get the display adapter 
        DisplayAdapter* getDisplayAdapter();

        // Get isRunning  
        bool isRendererRunning (){
            return this->isRunning;
        }

        // Set running 
        void setRunning(bool state=true){
            this->isRunning = state;
        }

        // Get pixels along Y axis  
        int getPixelsAlongYAxis(){
           return this->windowHeight / this->pixelHeight;
        }

        // Get pixels along X axis 
        int getPixelsAlongXAxis(){
            return this->windowWidth / this->pixelHeight;
        }

        // Get pixel height 
        int getPixelHeight(){
            return this->pixelHeight;
        }

        /// @brief Get material handler 
        MaterialManager* getMaterialManager(){
            return &this->materialManager;
        }

        // Get pixel at position 
        Material getPixelAtPosition(int row,int col){
            // Check if out of bounds
            if (col < 0  || col >= this->pixelsAlongXAxis || row < 0 || row >= pixelsAlongYAxis){
                exit(21);
            }

            return this->pixelGrid[(row * this->pixelsAlongXAxis) + col];
        }

        // Set pixel at position 
        // returns the previous material at that position
        Material setPixelAtPosition(Material pixel, int row,int col){
            // Check if out of bounds
            if (col < 0  || col >= this->pixelsAlongXAxis || row < 0 || row >= pixelsAlongYAxis){
                exit(21);
            }

            Material prev = this->getPixelAtPosition(col,row);
            this->pixelGrid[(row * this->pixelsAlongXAxis) + col] = pixel;
            return prev;
        }

        // Get mouse X
        int getMousePosX(){
            return this->mousePosX;
        }

        // Get mouse Y
        int getMousePosY(){
            return this->mousePosY;
        }

        // Get mouse X pointer 
        int* getMousePosXPointer(){
            return &this->mousePosX;
        }

        // Get mouse Y pointer
        int* getMousePosYPointer(){
            return &this->mousePosY;
        }

        // Handle events method 
        virtual void handleEvents(){};

        // Update method 
        virtual void update(){};

        // Render method
        virtual void render(){};

        // Clean method 
        virtual void clean(){
            std::free(this->pixelGrid);
        };
};


// Set display adapter method 
void Renderer::setDiplayAdapter(DisplayAdapter *adapter){
    this->displayAdapter = adapter;
}

// Get display adapter 
DisplayAdapter* Renderer::getDisplayAdapter(){
    return this->displayAdapter;
}

void Renderer::setUp(){
    // If pixelHeight is greater than the windowHeight 
    // then set the height to windowHeight
    if (pixelHeight > this->windowHeight ){
        this->pixelHeight = windowHeight;
    }

    if (pixelHeight <= 0){
        this->pixelHeight = 1;
    }

    // Set pixels along axis 
    this->pixelsAlongXAxis = this->getPixelsAlongXAxis();
    this->pixelsAlongYAxis = this->getPixelsAlongYAxis();
    
    // Set the material handler 
    this->materialManager = MaterialManager();

    // Create the pixel map 
    this->pixelGrid = new Material[pixelsAlongYAxis * pixelsAlongXAxis];
}

