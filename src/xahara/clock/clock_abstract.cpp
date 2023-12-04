#include "../renderer/renderer.h"
#include <SDL2/SDL.h>

/// @brief This is a game clock that ticks at a frame rate 
class Clock {
    private:
        int frameRate; 
        Uint32 frameStart;
        int frameTime;
        int frameDelay;

        Renderer *renderer;

    public:
        Clock(int frameRate=60){
            this->frameRate = frameRate;
            this->frameDelay = 1000/this->frameRate;
        }   

        Clock* setRendererer(Renderer *renderer){
            this->renderer = renderer;
            return this;
        }

        /// @brief Start the game clock
        /// @return 
        Clock* start(){
        
            // Game running
            while (renderer->isRendererRunning())
            {
                // Frame start 
                this->frameStart = SDL_GetTicks();
                // Renderer loop 
                renderer->handleEvents();
                renderer->update();
                renderer->render();

                // Frame time 
                frameTime = SDL_GetTicks() - this->frameStart;
                
                // Delay 
                if (frameTime < this->frameDelay){
                    SDL_Delay(frameDelay - frameTime);
                }

            }

            // Clean before close 
            renderer->clean();

            return this;
        }
};

