#include "./xahara/xahara.h"
#include <stdlib.h>
#include <iostream>

/*
    Sample world scenario using the Xahara renderer 
*/
int main(int arc,char** argv){

    // Instance of the Xahara renderer 
    PixelXahara instance = PixelXahara(800,600);
    // Display adapter using SDL
    SDL2Adapter displayAdapter = SDL2Adapter();
    instance.setDiplayAdapter(&displayAdapter);
    // Initialize the renderer 
    instance.init("Sandman");

    // Game clock 
    Clock clock = Clock();
    clock.setRendererer(&instance);
    clock.start();

    return 1;
}
